#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/rnea.hpp"
#include "rla_rnea/runtime/runtime_dispatcher.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_rnea");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa", "hyq", "baxter", "fetch");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  //typedef Eigen::Matrix<double, 6, 6> EigenSpatialXform;
  using namespace pinocchio;
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string robot_name = program.get<std::string>("--robot");
  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  // Get RNEA function from dispatcher
  auto rnea_func = RneaDispatcher::get_rnea_function(robot_name);

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;

  size_t last_joint = model.njoints - 1;
  
  // Create data required by the algorithms
  Data data(model);
  
  // Sample a random configuration
  Eigen::VectorXd q(model.njoints-1);
  q << -0.3369, 1.2966, -0.6775, -1.4218, -0.7067, -0.135, -1.1495;
  Eigen::VectorXd qd(model.nv);
  qd << 0.433, -0.4216, -0.6454, -1.8605, -0.0131, -0.4583, 0.7412;
  //Eigen::VectorXd q = randomConfiguration(model);
  //Eigen::VectorXd qd = randomConfiguration(model);

  Eigen::VectorXd qdd = Eigen::VectorXd::Zero(model.nv);

  std::cout << "q: " << q.transpose() << std::endl;
  std::cout << "qd: " << qd.transpose() << std::endl;

  // Perform rnea over the kinematic tree
  rnea(model, data, q, qd, qdd);

  // Pinocchio debug

  std::cout << "---PINOCCHIO DEBUG---\n";

  //for (size_t i = 1; i < (JointIndex)model.njoints-1; i++) {
  //  std::cout << "v " << i << "\n" << data.v[i] << "\n";
  //  std::cout << "a " << i << "\n" << data.a[i] << "\n";
  //}

  std::cout << "-------------------\n";

  // CTUP debug

  Eigen::VectorXd ctup_res, pin_res;

  std::cout << "---CTUP DEBUG---\n";

  ctup_res = rnea_func(q, qd);

  std::cout << "-------------------\n";

  std::cout << "--------FINAL RES--------\n";

  pin_res = data.tau;

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}
