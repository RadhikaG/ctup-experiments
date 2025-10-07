#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
//#include "fk_gen_dense.h"
#include "rla_fk/gen/fk_gen_unrolled.h"
#include <iostream>

int main(int argc, char ** argv)
{
  typedef Eigen::Matrix<double, 6, 6> EigenSpatialXform;
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

  //ctup_gen::set_X_T();

  std::cout << "---CTUP  DEBUG---\n";

  ctup_res = ctup_gen::fk(q);

  std::cout << "-------------------\n";

  pin_res = data.oMi[model.njoints-1];

  std::cout << "--------FINAL RES--------\n";

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}

