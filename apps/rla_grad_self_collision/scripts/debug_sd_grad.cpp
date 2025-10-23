#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/parsers/srdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/geometry.hpp>
#include <pinocchio/algorithm/jacobian.hpp>

#include <coal/shape/geometric_shapes.h>  // for coal::Sphere

#include <cassert>
#include <iostream>
#include <cmath>
#include <argparse/argparse.hpp>

#include "rla_grad_self_collision/runtime/utils.h"
#include "rla_grad_self_collision/rla_sd_grad_dispatcher/sd_grad_dispatcher.h"

using namespace pinocchio;

constexpr double EPSILON = 1e-6;

struct CollisionGradient {
  double signed_distance;
  Eigen::VectorXd gradient;
  std::pair<GeomIndex, GeomIndex> geom_pair;
};

static Eigen::Matrix3d skew(const Eigen::Vector3d &v) {
  Eigen::Matrix3d m;
  m <<     0, -v.z(),  v.y(),
        v.z(),     0, -v.x(),
       -v.y(),  v.x(),    0;
  return m;
}

static inline Eigen::Vector3d vee_skew(const Eigen::Matrix3d &S) {
  return Eigen::Vector3d( S(2,1),
                          S(0,2),
                          S(1,0));
}

static double computeDistance(
    const Model &model,
    Data &data,
    const GeometryModel &geom_model,
    GeometryData &geom_data,
    const Eigen::VectorXd &q,
    GeomIndex g1,
    GeomIndex g2) {

  updateGeometryPlacements(model, data, geom_model, geom_data, q);

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
  // oMg is placement of object in world frame
  Eigen::Vector3d p1 = geom_data.oMg[g1].translation();
  Eigen::Vector3d p2 = geom_data.oMg[g2].translation();
  Eigen::Vector3d delta = p1 - p2;
  double dist = delta.norm();
  double signed_dist = dist - (r1 + r2);

  return signed_dist;
}

static CollisionGradient computeDistanceAndGradientForPair(
    const Model &model,
    Data &data,
    const GeometryModel &geom_model,
    GeometryData &geom_data,
    const Eigen::VectorXd &q,
    GeomIndex g1,
    GeomIndex g2)
{
  std::cout << "pair: " << "(" << g1 << ", " << g2 << ")\n";

  computeJointJacobians(model, data, q);
  updateGeometryPlacements(model, data, geom_model, geom_data, q);

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
  // oMg is placement of object wrt world frame expressed in world frame
  Eigen::Vector3d p1 = geom_data.oMg[g1].translation();
  Eigen::Vector3d p2 = geom_data.oMg[g2].translation();
  Eigen::Vector3d delta = p1 - p2;
  double dist = delta.norm();
  double signed_dist = dist - (r1 + r2);

  // get witness points
  Eigen::Vector3d normal = delta / dist;
  Eigen::Vector3d witness_pt1 = p1 + r1 * normal;
  Eigen::Vector3d witness_pt2 = p2 - r2 * normal;

  Eigen::MatrixXd jac1(6, model.nv);
  Eigen::MatrixXd jac2(6, model.nv);
  jac1 = getJointJacobian(model, data, obj1.parentJoint, WORLD);
  jac2 = getJointJacobian(model, data, obj2.parentJoint, WORLD);

  Eigen::MatrixXd jac1_w(3, model.nv);
  Eigen::MatrixXd jac1_v(3, model.nv);
  Eigen::MatrixXd jac2_w(3, model.nv);
  Eigen::MatrixXd jac2_v(3, model.nv);

  jac1_w = jac1.bottomRows<3>();
  jac1_v = jac1.topRows<3>();
  jac2_w = jac2.bottomRows<3>();
  jac2_v = jac2.topRows<3>();

  // compute twist at witness_pt wrt world frame expressed in world frame
  Eigen::MatrixXd ptJac1(3, model.nv);
  Eigen::MatrixXd ptJac2(3, model.nv);

  ptJac1 = jac1_v - skew(witness_pt1) * jac1_w;
  ptJac2 = jac2_v - skew(witness_pt2) * jac2_w;

  ////// Gradient calc

  Eigen::VectorXd grad = Eigen::VectorXd::Zero(model.nv);
  grad = normal.transpose() * (ptJac1 - ptJac2);
  std::cout << "===============\n";
  std::cout << "grad: " << grad << "\n";
  std::cout << "===============\n";

  return {signed_dist, grad, {g1, g2}};
}

static Eigen::Matrix<double, 6, 1> get_spatial_twist_fd(
    Model &model,
    Data &data,
    GeometryModel &geom_model,
    GeometryData &geom_data,
    GeomIndex g_id,
    Eigen::VectorXd &q_minus,
    Eigen::VectorXd &q,
    Eigen::VectorXd &q_plus) {
  Eigen::Matrix<double, 6, 1> spatial_twist;

  Eigen::Matrix4d T_dot, T, T_plus, T_minus;

  Eigen::Vector3d omega_s, v_s;

  updateGeometryPlacements(model, data, geom_model, geom_data, q);
  T = geom_data.oMg[g_id].inverse().toHomogeneousMatrix();

  updateGeometryPlacements(model, data, geom_model, geom_data, q_plus);
  T_plus = geom_data.oMg[g_id].toHomogeneousMatrix();

  updateGeometryPlacements(model, data, geom_model, geom_data, q_minus);
  T_minus = geom_data.oMg[g_id].toHomogeneousMatrix();

  T_dot = (T_plus - T_minus) / (2 * EPSILON);

  Eigen::Matrix4d spatial_twist_hom;
  //spatial_twist_hom = T_dot * T.inverse();
  spatial_twist_hom = T_dot * T;

  omega_s = vee_skew(spatial_twist_hom.block<3, 3>(0, 0));
  v_s = spatial_twist_hom.block<3, 1>(0, 3);

  //spatial_twist.block<3, 1>(0, 0) = omega_s;
  //spatial_twist.block<3, 1>(3, 0) = v_s;
  //
  // pin order
  spatial_twist.block<3, 1>(0, 0) = v_s;
  spatial_twist.block<3, 1>(3, 0) = omega_s;

  return spatial_twist;
}

static void finiteDifferenceCheck(
    Model &model,
    Data &data,
    GeometryModel &geom_model,
    GeometryData &geom_data,
    Eigen::VectorXd &q,
    CollisionGradient &result)
{
  const auto &[g1, g2] = result.geom_pair;

  const auto &obj1 = geom_model.geometryObjects[g1];
  const auto &obj2 = geom_model.geometryObjects[g2];

  auto sph1 = std::dynamic_pointer_cast<coal::Sphere>(obj1.geometry);
  auto sph2 = std::dynamic_pointer_cast<coal::Sphere>(obj2.geometry);
  if (!sph1 || !sph2) {
    throw std::runtime_error("Non-sphere geometry detected in collision model.");
  }

  double r1 = sph1->radius;
  double r2 = sph2->radius;

  std::cout << "========= Finite Diff check =======\n";

  Eigen::VectorXd q_plus(q), q_minus(q);

  Eigen::MatrixXd J1_fd(6, model.nq);
  Eigen::MatrixXd J2_fd(6, model.nq);

  for (size_t i = 0; i < (size_t)model.nq; i++) {
    //std::cout << "pair: " << "(" << g1 << ", " << g2 << "), " << "i = " << i << "\n";
    q_plus = q; q_minus = q;
    //q_plus(i) += EPSILON;
    //q_minus(i) -= EPSILON;
    Eigen::VectorXd v(model.nv);
    v.setZero();
    v[i] = EPSILON;
    q_plus = integrate(model, q, v);
    q_minus = integrate(model, q, -v);

    Eigen::Matrix<double, 6, 1> v1 = get_spatial_twist_fd(model, data, geom_model, geom_data, g1, q_minus, q, q_plus);
    Eigen::Matrix<double, 6, 1> v2 = get_spatial_twist_fd(model, data, geom_model, geom_data, g2, q_minus, q, q_plus);

    J1_fd.col(i) = v1;
    J2_fd.col(i) = v2;
  }

  //const double threshold = 1e-15;
  //J1_fd = (threshold < J1_fd.array().abs()).select(J1_fd, 0.0f);
  //J2_fd = (threshold < J2_fd.array().abs()).select(J2_fd, 0.0f);

  Eigen::Matrix<double, 6, Eigen::Dynamic> J_pin(6, model.nv);

  std::cout << "====== Finite diff jacobians =========\n";
  std::cout << "J1: \n" << J1_fd << "\n";
  std::cout << "J2: \n" << J2_fd << "\n";
  std::cout << "===============================\n";

  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  // trans of objs wrt world frame expressed in world frame
  Eigen::Vector3d p1 = geom_data.oMg[g1].translation();
  Eigen::Vector3d p2 = geom_data.oMg[g2].translation();

  Eigen::Vector3d n = (p1 - p2).normalized();

  // todo: this calc is incorrect because this doesn't
  // account for frame shift to witness point.
  // haven't fixed it since we aren't using finite diff for
  // correctness checks atm
  Eigen::VectorXd grad_fd = n.transpose() * (J1_fd.topRows<3>() - J2_fd.topRows<3>());

  std::cout << "pair: " << "(" << g1 << ", " << g2 << ")\n";
  std::cout << "Analytical Gradient:\n" << result.gradient.transpose() << "\n";
  std::cout << "Finite Difference:\n" << grad_fd.transpose() << "\n";
  std::cout << "Relative Error:\n";
  for (int i = 0; i < model.nv; ++i) {
    double a = result.gradient(i), n = grad_fd(i);
    double err = std::abs(a - n) / std::max(1e-8, std::abs(a) + std::abs(n));
    std::cout << "Joint " << i << ": " << err << "\n";
  }
  std::cout << "===============\n";
}

static void run_cg_grad_sd(
    Model &model,
    Data &data,
    GeometryModel &geom_model,
    GeometryData &geom_data,
    Eigen::VectorXd &q,
    const std::string &robot_name,
    const std::string &fidelity)
{
  // expected shapes:
  // signed_distances: (batch_dim, n_collision_pairs)
  // constraint_jacobian: (batch_dim * n_collision_pairs, n_dof)
  const size_t SIMD_WIDTH = 8;
  size_t N_CP = geom_model.collisionPairs.size();

  Eigen::MatrixXd signed_distances = Eigen::MatrixXd::Zero(SIMD_WIDTH, N_CP);
  Eigen::MatrixXd constraint_jacobian = Eigen::MatrixXd::Zero(SIMD_WIDTH * N_CP, model.nv);

  // Dispatch based on robot type
  if (robot_name == "panda") {
    auto func = cg_sd_runtime::dispatcher::SdGradDispatcher::get_panda_function(fidelity);
    if (!func) {
      std::cerr << "Error: No implementation found for panda with fidelity '" << fidelity << "'\n";
      return;
    }

    cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::Panda> q_batched;
    for (size_t i = 0; i < cg_sd_runtime::robots::Panda::ndim; i++) {
      q_batched[i] = q(i);
    }

    func(q_batched, signed_distances, constraint_jacobian);
  }
  else if (robot_name == "ur5") {
    auto func = cg_sd_runtime::dispatcher::SdGradDispatcher::get_ur5_function(fidelity);
    if (!func) {
      std::cerr << "Error: No implementation found for ur5 with fidelity '" << fidelity << "'\n";
      return;
    }

    cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::UR5> q_batched;
    for (size_t i = 0; i < cg_sd_runtime::robots::UR5::ndim; i++) {
      q_batched[i] = q(i);
    }

    func(q_batched, signed_distances, constraint_jacobian);
  }
  else {
    std::cerr << "Error: Unknown robot '" << robot_name << "'\n";
    return;
  }

  std::cout << "cg_grad_sd SD: " << signed_distances.row(0) << "\n";
  std::cout << "cg_grad_sd grad: " << constraint_jacobian.row(0 * N_CP + 0) << "\n";
}

int main(int argc, char **argv) {
  argparse::ArgumentParser program("debug_sd_grad");

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

  // Load model and geometry
  Model model;
  GeometryModel geom_model;
  pinocchio::urdf::buildModel(urdf_path, model);
  pinocchio::urdf::buildGeom(model, urdf_path, COLLISION, geom_model);

  geom_model.addAllCollisionPairs();
  srdf::removeCollisionPairs(model, geom_model, srdf_path);

  srdf::loadReferenceConfigurations(model, srdf_path, true);

  Data data(model);
  GeometryData geom_data(geom_model);

  Eigen::VectorXd q;
  // Use reference configuration if available
  if (model.referenceConfigurations.count("ready") > 0) {
    q = model.referenceConfigurations["ready"];
  } else if (model.referenceConfigurations.count("home") > 0) {
    q = model.referenceConfigurations["home"];
  } else {
    std::cerr << "Error: No 'ready' or 'home' configuration found in SRDF.\n";
    std::cerr << "Available configurations: ";
    for (const auto& cfg : model.referenceConfigurations) {
      std::cerr << cfg.first << " ";
    }
    std::cerr << "\n";
    return 1;
  }

  std::cout << "======== config =========\n";
  std::cout << q << "\n";
  std::cout << "=============================\n";

  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  size_t N_CP = geom_model.collisionPairs.size();
  Eigen::VectorXd cp_sd(N_CP);
  Eigen::MatrixXd cp_sd_grad(N_CP, model.nv);

  size_t cp_it = 0;

  // Compute distance + gradient for all valid collision pairs
  for (const auto &cp : geom_model.collisionPairs) {
    auto result = computeDistanceAndGradientForPair(model, data, geom_model, geom_data, q, cp.first, cp.second);
    std::cout << "Collision Pair (" << cp.first << ", " << cp.second << ") -> Signed Distance: "
              "\n" << result.signed_distance << "\n";

    cp_sd(cp_it) = result.signed_distance;
    cp_sd_grad.row(cp_it) = result.gradient;

    cp_it++;

    // skipping finite diff check since there's no way
    // to actually check the cross product for the offset calc
    // and already verified spatial jacobian
    //finiteDifferenceCheck(model, data, geom_model, geom_data, q, result);
    std::cout << "----------------------------------------\n";
  }
  std::cout << "Pinocchio SD: " << cp_sd.transpose() << "\n";
  std::cout << "Pinocchio SD grad: " << cp_sd_grad.row(0) << "\n";

  run_cg_grad_sd(model, data, geom_model, geom_data, q, robot_name, fidelity);

  return 0;
}
