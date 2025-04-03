#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/rnea.hpp"
#include "rnea_gen.h"
#include <iostream>

int main(int argc, char ** argv)
{
  //typedef Eigen::Matrix<double, 6, 6> EigenSpatialXform;
  using namespace pinocchio;
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";
  
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

  //ctup_gen::set_X_T();
  ctup_gen::robot_data * rd = new ctup_gen::robot_data;
  ctup_gen::init_rd(rd);

  std::cout << "---CTUP DEBUG---\n";

  ctup_res = ctup_gen::rnea(q, qd);
  //ctup_res = ctup_gen::rnea(rd, q, qd);

  std::cout << "-------------------\n";

  std::cout << "--------FINAL RES--------\n";

  pin_res = data.tau;

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}
