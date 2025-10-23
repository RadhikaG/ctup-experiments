#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/parsers/srdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/geometry.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/utils/timer.hpp>

#include <coal/shape/geometric_shapes.h>

#include <cassert>
#include <iostream>
#include <cmath>
#include <argparse/argparse.hpp>

#include "rla_grad_self_collision/runtime/utils.h"
#include "rla_grad_self_collision/rla_sd_grad_dispatcher/sd_grad_dispatcher.h"

using namespace pinocchio;

static Eigen::Matrix3d skew(const Eigen::Vector3d &v) {
  Eigen::Matrix3d m;
  m <<     0, -v.z(),  v.y(),
        v.z(),     0, -v.x(),
       -v.y(),  v.x(),    0;
  return m;
}

static void computeCollisionGradients(
    const Model &model,
    Data &data,
    const GeometryModel &geom_model,
    GeometryData &geom_data,
    const Eigen::VectorXd &q,
    Eigen::VectorXd &signed_distances,
    Eigen::MatrixXd &constraint_jacobian)
{
  computeJointJacobians(model, data, q);
  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  size_t cp_idx = 0;
  for (const auto &cp : geom_model.collisionPairs) {
    GeomIndex g1 = cp.first;
    GeomIndex g2 = cp.second;

    const auto &obj1 = geom_model.geometryObjects[g1];
    const auto &obj2 = geom_model.geometryObjects[g2];

    auto sph1 = std::dynamic_pointer_cast<coal::Sphere>(obj1.geometry);
    auto sph2 = std::dynamic_pointer_cast<coal::Sphere>(obj2.geometry);
    if (!sph1 || !sph2) {
      throw std::runtime_error("Non-sphere geometry detected in collision model.");
    }

    double r1 = sph1->radius;
    double r2 = sph2->radius;

    // World positions of sphere centers
    Eigen::Vector3d p1 = geom_data.oMg[g1].translation();
    Eigen::Vector3d p2 = geom_data.oMg[g2].translation();
    Eigen::Vector3d delta = p1 - p2;
    double dist = delta.norm();
    double signed_dist = dist - (r1 + r2);

    // Get witness points
    Eigen::Vector3d normal = delta / dist;
    Eigen::Vector3d witness_pt1 = p1 + r1 * normal;
    Eigen::Vector3d witness_pt2 = p2 - r2 * normal;

    // Get Jacobians
    Eigen::MatrixXd jac1 = getJointJacobian(model, data, obj1.parentJoint, WORLD);
    Eigen::MatrixXd jac2 = getJointJacobian(model, data, obj2.parentJoint, WORLD);

    Eigen::MatrixXd jac1_w = jac1.bottomRows<3>();
    Eigen::MatrixXd jac1_v = jac1.topRows<3>();
    Eigen::MatrixXd jac2_w = jac2.bottomRows<3>();
    Eigen::MatrixXd jac2_v = jac2.topRows<3>();

    // Compute twist at witness points
    Eigen::MatrixXd ptJac1 = jac1_v - skew(witness_pt1) * jac1_w;
    Eigen::MatrixXd ptJac2 = jac2_v - skew(witness_pt2) * jac2_w;

    // Gradient calculation
    Eigen::VectorXd grad = normal.transpose() * (ptJac1 - ptJac2);

    signed_distances(cp_idx) = signed_dist;
    constraint_jacobian.row(cp_idx) = grad;
    cp_idx++;
  }
}

int main(int argc, char **argv) {
  argparse::ArgumentParser program("eval_sd_grad");

  program.add_argument("urdf")
      .help("path to the URDF file");
  program.add_argument("srdf")
      .help("path to the SRDF file");
  program.add_argument("--robot")
      .default_value(std::string("panda"))
      .help("robot name (panda, ur5)");
  program.add_argument("--fidelity")
      .default_value(std::string("spherized_1"))
      .help("fidelity level (e.g., spherized_1, spherized)");
  program.add_argument("--config")
      .default_value(std::string("ready"))
      .help("reference configuration name");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  const std::string urdf_path = program.get<std::string>("urdf");
  const std::string srdf_path = program.get<std::string>("srdf");
  const std::string robot_name = program.get<std::string>("--robot");
  const std::string fidelity = program.get<std::string>("--fidelity");
  const std::string config_name = program.get<std::string>("--config");

  std::cout << "URDF file: " << urdf_path << "\n";
  std::cout << "SRDF file: " << srdf_path << "\n";
  std::cout << "Robot: " << robot_name << "\n";
  std::cout << "Fidelity: " << fidelity << "\n";
  std::cout << "Configuration: " << config_name << "\n";

  // Load model and geometry
  Model model;
  GeometryModel geom_model;
  pinocchio::urdf::buildModel(urdf_path, model);
  pinocchio::urdf::buildGeom(model, urdf_path, COLLISION, geom_model);

  geom_model.addAllCollisionPairs();
  srdf::removeCollisionPairs(model, geom_model, srdf_path);
  srdf::loadReferenceConfigurations(model, srdf_path, true);

  std::cout << "model name: " << model.name << std::endl;
  std::cout << "nq: " << model.nq << std::endl;
  std::cout << "nv: " << model.nv << std::endl;
  std::cout << "collision pairs: " << geom_model.collisionPairs.size() << std::endl;

  Data data(model);
  GeometryData geom_data(geom_model);

  // Get model info and verify compatibility
  try {
    auto model_info = cg_sd_runtime::dispatcher::SdGradDispatcher::get_model_info(robot_name, fidelity);

    if (model_info.ndof != model.nv) {
      std::cerr << "Error: Model mismatch. Expected ndof=" << model_info.ndof
                << ", but URDF has nv=" << model.nv << "\n";
      return 1;
    }
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << "\n";
    std::cerr << "Available fidelities for " << robot_name << ": ";
    auto fidelities = cg_sd_runtime::dispatcher::SdGradDispatcher::list_fidelities(robot_name);
    for (const auto& f : fidelities) {
      std::cerr << f << " ";
    }
    std::cerr << "\n";
    return 1;
  }

  // Get configuration
  Eigen::VectorXd q;
  if (model.referenceConfigurations.count(config_name) == 0) {
    std::cerr << "Error: Configuration '" << config_name << "' not found in SRDF.\n";
    std::cerr << "Available configurations: ";
    for (const auto& cfg : model.referenceConfigurations) {
      std::cerr << cfg.first << " ";
    }
    std::cerr << "\n";
    return 1;
  }
  q = model.referenceConfigurations[config_name];

  size_t N_CP = geom_model.collisionPairs.size();
  Eigen::VectorXd pin_sd(N_CP);
  Eigen::MatrixXd pin_grad(N_CP, model.nv);

  std::cout << "\n=== Running Performance Evaluation ===\n\n";

  PinocchioTicToc timer(PinocchioTicToc::NS);
  const int NBT = 10000;
  const size_t SIMD_WIDTH = 8;

  // Benchmark Pinocchio (run SIMD_WIDTH times to match batched codegen)
  timer.tic();
  SMOOTH(NBT)
  {
    for (size_t i = 0; i < SIMD_WIDTH; i++) {
      computeCollisionGradients(model, data, geom_model, geom_data, q, pin_sd, pin_grad);
    }
  }
  std::cout << "Pinocchio SD+Grad (x" << SIMD_WIDTH << ") avg time (ns):     \t";
  timer.toc(std::cout, NBT);

  // Get dispatch function for the robot
  Eigen::MatrixXd cg_sd = Eigen::MatrixXd::Zero(SIMD_WIDTH, N_CP);
  Eigen::MatrixXd cg_grad = Eigen::MatrixXd::Zero(SIMD_WIDTH * N_CP, model.nv);

  // Benchmark codegen - dispatch based on robot type
  if (robot_name == "panda") {
    auto func = cg_sd_runtime::dispatcher::SdGradDispatcher::get_panda_function(fidelity);
    if (!func) {
      std::cerr << "Error: No implementation found for panda with fidelity '" << fidelity << "'\n";
      return 1;
    }

    // Prepare batched configuration
    cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::Panda> q_batched;
    for (size_t i = 0; i < cg_sd_runtime::robots::Panda::ndim; i++) {
      q_batched[i] = q(i);
    }

    // Benchmark
    timer.tic();
    SMOOTH(NBT)
    {
      func(q_batched, cg_sd, cg_grad);
    }
    std::cout << "Codegen SD+Grad (batched x" << SIMD_WIDTH << ") avg time (ns):\t";
    timer.toc(std::cout, NBT);
  }
  else if (robot_name == "ur5") {
    auto func = cg_sd_runtime::dispatcher::SdGradDispatcher::get_ur5_function(fidelity);
    if (!func) {
      std::cerr << "Error: No implementation found for ur5 with fidelity '" << fidelity << "'\n";
      return 1;
    }

    cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::UR5> q_batched;
    for (size_t i = 0; i < cg_sd_runtime::robots::UR5::ndim; i++) {
      q_batched[i] = q(i);
    }

    timer.tic();
    SMOOTH(NBT)
    {
      func(q_batched, cg_sd, cg_grad);
    }
    std::cout << "Codegen SD+Grad (batched x" << SIMD_WIDTH << ") avg time (ns):\t";
    timer.toc(std::cout, NBT);
  }
  else {
    std::cerr << "Error: Unknown robot '" << robot_name << "'\n";
    return 1;
  }

  std::cout << "\n=== Final Results ===\n\n";

  // Compare signed distances
  Eigen::VectorXd cg_sd_first_row = cg_sd.row(0);
  double sd_error = (pin_sd - cg_sd_first_row).norm();
  std::cout << "Signed distance error: " << sd_error << "\n";

  // Compare gradients (first collision pair)
  Eigen::VectorXd pin_grad_first = pin_grad.row(0);
  Eigen::VectorXd cg_grad_first = cg_grad.row(0);
  double grad_error = (pin_grad_first - cg_grad_first).norm();
  std::cout << "Gradient error (first pair): " << grad_error << "\n";

  std::cout << "\nPinocchio gradient (first pair): " << pin_grad_first.transpose() << "\n";
  std::cout << "Codegen gradient (first pair):   " << cg_grad_first.transpose() << "\n";

  // Check if errors are acceptable
  if (sd_error < 1e-6 && grad_error < 1e-6) {
    std::cout << "\nSUCCESS: Results match within tolerance!\n";
    return 0;
  } else {
    std::cout << "\nWARNING: Large error detected!\n";
    return 1;
  }
}
