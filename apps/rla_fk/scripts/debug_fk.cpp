#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "rla_fk/rla_fk_dispatcher/fk_dispatcher.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_fk");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa", "hyq", "baxter");

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

  // Get command-line arguments
  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string robot_name = program.get<std::string>("--robot");
  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  // Get FK function from dispatcher
  auto fk_func = FkDispatcher::get_fk_scalar_function(robot_name);

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  // Create data required by the algorithms
  Data data(model);

  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;

  // Perform the forward kinematics over the kinematic tree
  forwardKinematics(model, data, q);

  // Pinocchio debug

  std::cout << "---PINOCCHIO DEBUG---\n";

  for (size_t i = 1; i < (size_t)model.njoints; i++) {
    if (i <= 4) {
      std::cout << "XT\n" << (EigenSpatialXform)(model.jointPlacements[i]) << "\n";
      std::cout << "XJ\n" << (EigenSpatialXform)(data.joints[i].M()) << "\n";
      std::cout << "Xpi\n" << (EigenSpatialXform)(data.liMi[i])  << "\n";
      std::cout << "Xpar\n" << (EigenSpatialXform)(data.oMi[model.parents[i]])  << "\n";
    }
    std::cout << "X " << i << "\n" << (EigenSpatialXform)(data.oMi[i]) << "\n";
  }

  std::cout << "-------------------\n";

  // CTUP debug

  Eigen::Matrix<double, 6, 6> ctup_res, pin_res;

  std::cout << "---CTUP DEBUG---\n";

  ctup_res = fk_func(q);

  std::cout << "-------------------\n";

  pin_res = data.oMi[model.njoints-1];

  std::cout << "--------FINAL RES--------\n";

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}
