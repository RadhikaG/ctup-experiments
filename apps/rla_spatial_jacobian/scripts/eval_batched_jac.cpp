#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include "rla_spatial_jacobian/rla_spatial_jac_dispatcher/jac_dispatcher.h"
#include "blaze/Math.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

using namespace rla_jac_runtime::dispatcher;

// Template function to run batched Jacobian evaluation for any RobotTraits, Scalar, and BatchSize
template<typename RobotTraits, typename Scalar, size_t BatchSize>
void run_batched_evaluation(const std::string& urdf_filename,
                             const std::string& robot_name,
                             pinocchio::Model& model) {
  using namespace pinocchio;
  using RobotType = typename RobotTraits::RobotType;

  PinocchioTicToc timer(PinocchioTicToc::NS);
  const int NBT = 10000;

  // Sample random configurations
  PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(NBT);
  for (size_t i = 0; i < NBT; ++i) {
    qs[i] = randomConfiguration(model);
  }

  std::cout << "\n=== Running Performance Evaluation ===\n\n";

  // Result matrices
  // Batched Jacobian output: BatchSize rows x (6 * nv) columns (flattened Jacobians)
  Eigen::MatrixXd rla_res_batched = Eigen::MatrixXd::Zero(BatchSize, 6 * model.nv);
  Eigen::MatrixXd pin_res(6, model.nv);
  Data data(model);

  // Get batched Jacobian function from dispatcher
  auto jac_batched_func = RobotTraits::jac_batched_float_8;

  // Benchmark batched RLA Jacobian
  try {
    timer.tic();
    SMOOTH(NBT)
    {
      rla_jac_runtime::ConfigurationBlock<RobotType, Scalar, BatchSize> q_batched;
      // Broadcast each joint value to all SIMD lanes (same config for all batch elements)
      for (size_t d = 0; d < RobotTraits::ndim; ++d) {
        q_batched[d] = qs[_smooth][d];  // Blaze automatically broadcasts scalar to vector
      }
      jac_batched_func(q_batched, rla_res_batched);
    }
    std::cout << "RLA batched Jacobian avg time (ns):                        \t";
    timer.toc(std::cout, NBT);
  } catch (const std::runtime_error& e) {
    std::cerr << "Error running RLA batched Jacobian: " << e.what() << "\n";
    std::cerr << "Skipping RLA benchmark.\n";
  }

  // Benchmark vanilla Pinocchio Jacobian (BatchSize consecutive calls)
  timer.tic();
  SMOOTH(NBT)
  {
    for (size_t w = 0; w < BatchSize; w++) {
      // Compute joint Jacobians
      computeJointJacobians(model, data, qs[_smooth]);
      // Get world-frame Jacobian for last joint (end-effector)
      pin_res = getJointJacobian(model, data, model.njoints - 1, WORLD);
    }
  }
  std::cout << "Pinocchio vanilla (" << BatchSize << " consecutive calls) avg time (ns): \t";
  timer.toc(std::cout, NBT);

  // Get final Pinocchio result for comparison
  computeJointJacobians(model, data, qs[NBT-1]);
  pin_res = getJointJacobian(model, data, model.njoints - 1, WORLD);

  // Extract first row of batched result and reshape to 6 x nv
  Eigen::MatrixXd rla_res(6, model.nv);
  for (size_t r = 0; r < 6; ++r) {
    for (size_t c = 0; c < (size_t)model.nv; ++c) {
      rla_res(r, c) = rla_res_batched(0, r * model.nv + c);
    }
  }

  // RLA outputs [angular; linear] while Pinocchio outputs [linear; angular]
  // Reorder Pinocchio to match RLA convention
  Eigen::MatrixXd pin_res_reordered(6, model.nv);
  pin_res_reordered.topRows(3) = pin_res.bottomRows(3);     // angular (Pinocchio rows 3-5 -> rows 0-2)
  pin_res_reordered.bottomRows(3) = pin_res.topRows(3);     // linear (Pinocchio rows 0-2 -> rows 3-5)

  std::cout << "\n=== Final Results (Last Configuration) ===\n\n";
  std::cout << "RLA batched Jacobian result (first batch, 6x" << model.nv << "):\n" << rla_res << "\n\n";
  std::cout << "Pinocchio vanilla Jacobian result (6x" << model.nv << "):\n" << pin_res << "\n\n";
  std::cout << "Pinocchio vanilla Jacobian (reordered to RLA convention):\n" << pin_res_reordered << "\n\n";

  // Compute error with reordered Pinocchio result
  double error = (rla_res - pin_res_reordered).norm();
  std::cout << "Error between RLA and Pinocchio Jacobian: " << error << "\n";

  // Check if error is acceptable
  if (error < 1e-5) {
    std::cout << "SUCCESS: Jacobians match within tolerance!\n";
  } else {
    std::cout << "WARNING: Large error between Jacobians!\n";
  }
}

// Helper to dispatch based on robot name
template<typename Scalar, size_t BatchSize>
void dispatch_robot(const std::string& robot_name, const std::string& urdf_filename) {
  using namespace pinocchio;

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;
  std::cout << "nq: " << model.nq << std::endl;
  std::cout << "nv: " << model.nv << std::endl;

  if (robot_name == "panda") {
    run_batched_evaluation<PandaTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else if (robot_name == "iiwa") {
    run_batched_evaluation<iiwaTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else if (robot_name == "hyq") {
    run_batched_evaluation<hyqTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else if (robot_name == "baxter") {
    run_batched_evaluation<baxterTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else {
    throw std::runtime_error("Unknown robot: " + robot_name);
  }
}

// Main dispatcher - only instantiate supported combinations
static void dispatch_batched_jac(int batch_size, const std::string& dtype, const std::string& robot_name, const std::string& urdf_filename) {
  // Currently only float with batch size 8 is implemented
  if (dtype == "float" && batch_size == 8) {
    dispatch_robot<float, 8>(robot_name, urdf_filename);
  } else {
    throw std::runtime_error("Unsupported combination: dtype=" + dtype + ", batch_size=" + std::to_string(batch_size) +
                              ". Only float with batch_size=8 is currently supported.");
  }

  // When adding new implementations, add explicit instantiations here:
  // Example for float with batch_size=16:
  // else if (dtype == "float" && batch_size == 16) {
  //   dispatch_robot<float, 16>(robot_name, urdf_filename);
  // }
  // Example for double with batch_size=8:
  // else if (dtype == "double" && batch_size == 8) {
  //   dispatch_robot<double, 8>(robot_name, urdf_filename);
  // }
}

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_batched_jac");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("panda", "iiwa", "hyq", "baxter");

  program.add_argument("--dtype")
      .default_value(std::string("float"))
      .help("data type (double or float)")
      .choices("double", "float");

  program.add_argument("--batch-size")
      .default_value(8)
      .scan<'i', int>()
      .help("SIMD batch size (4, 8, 16, 32)")
      .choices(4, 8, 16, 32);

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string robot_name = program.get<std::string>("--robot");
  const std::string dtype = program.get<std::string>("--dtype");
  const int batch_size = program.get<int>("--batch-size");

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";
  std::cout << "Dtype: " << dtype << "\n";
  std::cout << "Batch size: " << batch_size << "\n\n";

  // Check if the requested configuration is supported
  if (dtype != "float" || batch_size != 8) {
    std::cerr << "Warning: Only float precision with batch size 8 is currently implemented.\n";
    std::cerr << "Requested: " << dtype << " with batch size " << batch_size << "\n";
    std::cerr << "This will fail at runtime.\n\n";
  }

  try {
    dispatch_batched_jac(batch_size, dtype, robot_name, urdf_filename);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
