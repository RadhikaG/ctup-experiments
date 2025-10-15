#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include "rla_spatial_jacobian/rla_spatial_jac_dispatcher/jac_dispatcher.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_jac");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("panda", "iiwa", "hyq", "baxter");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  using namespace pinocchio;
  using namespace rla_jac_runtime::dispatcher;

  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string robot_name = program.get<std::string>("--robot");
  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  // Get RLA Jacobian function from dispatcher
  auto rla_jac_func = JacDispatcher::get_jac_scalar_function(robot_name);

  PinocchioTicToc timer(PinocchioTicToc::NS);
  const int NBT = 10000;

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;
  std::cout << "nq: " << model.nq << std::endl;
  std::cout << "nv: " << model.nv << std::endl;

  // Sample random configurations
  PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(NBT);
  for (size_t i = 0; i < NBT; ++i) {
    qs[i] = randomConfiguration(model);
  }

  std::cout << "\n=== Running Performance Evaluation ===\n\n";

  Eigen::MatrixXd rla_res(6, model.nv);
  Eigen::MatrixXd pin_res(6, model.nv);

  Data data(model);

  // Benchmark RLA Jacobian
  try {
    timer.tic();
    SMOOTH(NBT)
    {
      rla_jac_func(qs[_smooth], rla_res);
    }
    std::cout << "RLA Jacobian avg time (ns):           \t\t";
    timer.toc(std::cout, NBT);
  } catch (const std::runtime_error& e) {
    std::cerr << "Error running RLA Jacobian: " << e.what() << "\n";
    std::cerr << "Skipping RLA benchmark.\n";
    // Initialize to zeros for comparison
    rla_res = Eigen::MatrixXd::Zero(6, model.nv);
  }

  // Benchmark vanilla Pinocchio Jacobian
  timer.tic();
  SMOOTH(NBT)
  {
    // Compute joint Jacobians
    computeJointJacobians(model, data, qs[_smooth]);
    // Get world-frame Jacobian for last joint (end-effector)
    pin_res = getJointJacobian(model, data, model.njoints - 1, WORLD);
  }
  std::cout << "Pinocchio vanilla Jacobian avg time (ns):      \t";
  timer.toc(std::cout, NBT);

  // RLA outputs [angular; linear] while Pinocchio outputs [linear; angular]
  // Reorder Pinocchio to match RLA convention
  Eigen::MatrixXd pin_res_reordered(6, model.nv);
  pin_res_reordered.topRows(3) = pin_res.bottomRows(3);     // angular (Pinocchio rows 3-5 -> rows 0-2)
  pin_res_reordered.bottomRows(3) = pin_res.topRows(3);     // linear (Pinocchio rows 0-2 -> rows 3-5)

  std::cout << "\n=== Final Results (Last Configuration) ===\n\n";
  std::cout << "RLA Jacobian result (6x" << model.nv << "):\n" << rla_res << "\n\n";
  std::cout << "Pinocchio Jacobian result (6x" << model.nv << "):\n" << pin_res << "\n\n";
  std::cout << "Pinocchio Jacobian (reordered to RLA convention):\n" << pin_res_reordered << "\n\n";

  // Compute error with reordered Pinocchio result
  double error = (rla_res - pin_res_reordered).norm();
  std::cout << "Error between RLA and Pinocchio Jacobian: " << error << "\n";

  // Check if error is acceptable
  if (error < 1e-6) {
    std::cout << "SUCCESS: Jacobians match within tolerance!\n";
    return 0;
  } else {
    std::cout << "WARNING: Large error between Jacobians!\n";
    return 1;
  }
}
