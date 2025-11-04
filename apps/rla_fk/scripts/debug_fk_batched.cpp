#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "rla_fk/rla_fk_dispatcher/fk_dispatcher.h"
#include "blaze/Math.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_fk_batched");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa", "hyq", "baxter", "synth_12");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  typedef Eigen::Matrix<double, 6, 6> EigenSpatialXform;
  using namespace pinocchio;
  using namespace ctup_runtime::dispatcher;

  const std::string urdf_filename = program.get<std::string>("urdf");
  std::string robot_name = program.get<std::string>("--robot");
  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  // For synth_12, extract URDF base filename to determine which variant
  if (robot_name == "synth_12") {
    size_t last_slash = urdf_filename.find_last_of("/\\");
    size_t last_dot = urdf_filename.find_last_of(".");
    robot_name = urdf_filename.substr(last_slash + 1, last_dot - last_slash - 1);

    std::cout << "Detected synth_12 robot: " << robot_name << "\n";
  }

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);

  std::cout << "---PINOCCHIO DEBUG---\n";

  Data data(model);
  forwardKinematics(model, data, q);
  Eigen::Matrix<double, 6, 6> pin_res = data.oMi[model.njoints-1];

  for (size_t i = 1; i < (size_t)model.njoints; i++) {
    if (i <= 4) {
      std::cout << "XT\n" << ((EigenSpatialXform)(model.jointPlacements[i])).transpose() << "\n";
      std::cout << "XJ\n" << ((EigenSpatialXform)(data.joints[i].M())).transpose() << "\n";
      std::cout << "Xpi\n" << ((EigenSpatialXform)(data.liMi[i])).transpose()  << "\n";
      std::cout << "Xpar\n" << ((EigenSpatialXform)(data.oMi[model.parents[i]])).transpose()  << "\n";
    }
    std::cout << "X " << i << "\n" << ((EigenSpatialXform)(data.oMi[i])).transpose() << "\n";
  }

  std::cout << "-------------------\n";

  std::cout << "---CTUP DEBUG---\n";

  Eigen::MatrixXd ctup_res_batched(6, 6);

  // Dispatch to the appropriate robot batched FK
  // Using double precision with batch size 8
  if (robot_name == "iiwa") {
    auto fk_batched_func = FkDispatcher::get_fk_batched_function<iiwaTraits, double, 8>();
    ctup_runtime::ConfigurationBlock<ctup_runtime::robots::iiwa, double, 8> q_batched;
    for (size_t d = 0; d < iiwaTraits::ndof; ++d) {
      q_batched[d] = q[d];
    }
    fk_batched_func(q_batched, ctup_res_batched);
  } else if (robot_name == "hyq") {
    auto fk_batched_func = FkDispatcher::get_fk_batched_function<HyqTraits, double, 8>();
    ctup_runtime::ConfigurationBlock<ctup_runtime::robots::hyq, double, 8> q_batched;
    for (size_t d = 0; d < HyqTraits::ndof; ++d) {
      q_batched[d] = q[d];
    }
    fk_batched_func(q_batched, ctup_res_batched);
  } else if (robot_name == "baxter") {
    auto fk_batched_func = FkDispatcher::get_fk_batched_function<BaxterTraits, double, 8>();
    ctup_runtime::ConfigurationBlock<ctup_runtime::robots::baxter, double, 8> q_batched;
    for (size_t d = 0; d < BaxterTraits::ndof; ++d) {
      q_batched[d] = q[d];
    }
    fk_batched_func(q_batched, ctup_res_batched);
  } else if (robot_name == "serial_12dof" || robot_name == "dual_6dof" ||
             robot_name == "triple_4dof" || robot_name == "quad_3dof" ||
             robot_name == "tree_2_5_5") {
    // All synth_12 robots share the same configuration block type
    ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8> q_batched;
    for (size_t d = 0; d < 12; ++d) {  // synth_12::ndof = 12
      q_batched[d] = q[d];
    }

    // Dispatch to specific FK function based on robot variant
    if (robot_name == "serial_12dof") {
      auto fk_batched_func = FkDispatcher::get_fk_batched_function<Serial12dofTraits, double, 8>();
      fk_batched_func(q_batched, ctup_res_batched);
    } else if (robot_name == "dual_6dof") {
      auto fk_batched_func = FkDispatcher::get_fk_batched_function<Dual6dofTraits, double, 8>();
      fk_batched_func(q_batched, ctup_res_batched);
    } else if (robot_name == "triple_4dof") {
      auto fk_batched_func = FkDispatcher::get_fk_batched_function<Triple4dofTraits, double, 8>();
      fk_batched_func(q_batched, ctup_res_batched);
    } else if (robot_name == "quad_3dof") {
      auto fk_batched_func = FkDispatcher::get_fk_batched_function<Quad3dofTraits, double, 8>();
      fk_batched_func(q_batched, ctup_res_batched);
    } else if (robot_name == "tree_2_5_5") {
      auto fk_batched_func = FkDispatcher::get_fk_batched_function<Tree255Traits, double, 8>();
      fk_batched_func(q_batched, ctup_res_batched);
    }
  } else {
    throw std::runtime_error("Unknown robot: " + robot_name);
  }

  std::cout << "-------------------\n";

  std::cout << "--------FINAL RES--------\n";

  std::cout << "ctup_res (batched, first SIMD lane):\n" << ctup_res_batched << std::endl;
  std::cout << "pin_res:\n" << pin_res << std::endl;

  return 0;
}
