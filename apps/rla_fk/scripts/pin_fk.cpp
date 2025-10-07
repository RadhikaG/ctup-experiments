#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include <iostream>
// PINOCCHIO_MODEL_DIR is defined by the CMake but you can define your own directory here.
#ifndef PINOCCHIO_MODEL_DIR
  #define PINOCCHIO_MODEL_DIR "path_to_the_model_dir"
#endif
int main(int argc, char ** argv)
{
  using namespace pinocchio;
  
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;
  
  // Create data required by the algorithms
  Data data(model);
  
  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;
  // Perform the forward kinematics over the kinematic tree
  forwardKinematics(model,data,q);
  // Print out the placement of each joint of the kinematic tree
  for(JointIndex joint_id = 0; joint_id < (JointIndex)model.njoints; ++joint_id)
    std::cout << std::setw(24) << std::left
              << model.names[joint_id] << ": "
              << std::fixed << std::setprecision(2)
              << data.oMi[joint_id].translation().transpose()
              << std::endl;

  for(JointIndex joint_id = 0; joint_id < (JointIndex)model.njoints; ++joint_id) {
    std::cout << model.names[joint_id] << "\n";
    Eigen::Matrix<double, 6, 6> X_T = model.jointPlacements[joint_id];
    Eigen::Matrix<double, 6, 6> X_pi = data.liMi[joint_id];
    Eigen::Matrix<double, 6, 6> X_Oi = data.oMi[joint_id];
    std::cout << "X_T:\n" << X_T << "\n";
    std::cout << "X_pi:\n" << X_pi << "\n";
    std::cout << "X_Oi:\n" << X_Oi << "\n";
    std::cout << "-------\n";
  }
}
