#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include "rla_fk/rla_fk_dispatcher/fk_dispatcher.h"
#include "blaze/Math.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

using namespace ctup_runtime::dispatcher;

// Template function to run batched FK evaluation for any RobotTraits, Scalar, and BatchSize
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

  Eigen::MatrixXd rla_res_batched = Eigen::MatrixXd::Zero(BatchSize, 36);
  Eigen::Matrix<double, 6, 6> pin_res;
  Data data(model);

  // Get batched FK function from dispatcher
  auto fk_batched_func = FkDispatcher::get_fk_batched_function<RobotTraits, Scalar, BatchSize>();

  // Benchmark batched RLA FK
  timer.tic();
  SMOOTH(NBT)
  {
    ctup_runtime::ConfigurationBlock<RobotType, Scalar, BatchSize> q_batched;
    // Broadcast each joint value to all SIMD lanes (same config for all 8 batch elements)
    for (size_t d = 0; d < RobotTraits::ndof; ++d) {
      q_batched[d] = qs[_smooth][d];  // Blaze automatically broadcasts scalar to vector
    }
    fk_batched_func(q_batched, rla_res_batched);
  }
  std::cout << "RLA batched FK avg time (ns):           \t";
  timer.toc(std::cout, NBT);

  // Benchmark Pinocchio FK (BatchSize consecutive calls)
  timer.tic();
  SMOOTH(NBT)
  {
    for (size_t w = 0; w < BatchSize; w++) {
      forwardKinematics(model, data, qs[_smooth]);
    }
  }
  std::cout << "Pinocchio FK (" << BatchSize << " consecutive calls) avg time (ns): \t";
  timer.toc(std::cout, NBT);

  // Get final Pinocchio result for comparison
  forwardKinematics(model, data, qs[NBT-1]);
  pin_res = data.oMi[model.njoints-1];

  // Extract first row of batched result and reshape to 6x6
  Eigen::Matrix<double, 6, 6> rla_res;
  for (size_t r = 0; r < 6; ++r) {
    for (size_t c = 0; c < 6; ++c) {
      rla_res(r, c) = rla_res_batched(0, r * 6 + c);
    }
  }

  std::cout << "\n=== Final Results (Last Configuration) ===\n\n";
  std::cout << "RLA batched FK result (first batch):\n" << rla_res << "\n\n";
  std::cout << "Pinocchio FK result:\n" << pin_res << "\n";
}

// Helper to dispatch based on robot name
template<typename Scalar, size_t BatchSize>
void dispatch_robot(const std::string& robot_name, const std::string& urdf_filename) {
  using namespace pinocchio;

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  if (robot_name == "iiwa") {
    run_batched_evaluation<iiwaTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else if (robot_name == "hyq") {
    run_batched_evaluation<HyqTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else if (robot_name == "baxter") {
    run_batched_evaluation<BaxterTraits, Scalar, BatchSize>(urdf_filename, robot_name, model);
  } else {
    throw std::runtime_error("Unknown robot: " + robot_name);
  }
}

// Main dispatcher - only instantiate supported combinations
static void dispatch_batched_fk(int batch_size, const std::string& dtype, const std::string& robot_name, const std::string& urdf_filename) {
  // Currently only double with batch size 8 is implemented
  if (dtype == "double" && batch_size == 8) {
    dispatch_robot<double, 8>(robot_name, urdf_filename);
  } else {
    throw std::runtime_error("Unsupported combination: dtype=" + dtype + ", batch_size=" + std::to_string(batch_size) +
                              ". Only double with batch_size=8 is currently supported.");
  }

  // When adding new implementations, add explicit instantiations here:
  // Example for float with batch_size=4:
  // else if (dtype == "float" && batch_size == 4) {
  //   dispatch_robot<float, 4>(robot_name, urdf_filename);
  // }
  // Example for double with batch_size=16:
  // else if (dtype == "double" && batch_size == 16) {
  //   dispatch_robot<double, 16>(robot_name, urdf_filename);
  // }
}

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_fk_batched");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa", "hyq", "baxter");

  program.add_argument("--dtype")
      .default_value(std::string("double"))
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
  if (dtype != "double" || batch_size != 8) {
    std::cerr << "Error: Only double precision with batch size 8 is currently implemented.\n";
    std::cerr << "Requested: " << dtype << " with batch size " << batch_size << "\n";
    std::cerr << "This will compile but fail at runtime due to static_assert in dispatcher.\n\n";
  }

  try {
    dispatch_batched_fk(batch_size, dtype, robot_name, urdf_filename);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
