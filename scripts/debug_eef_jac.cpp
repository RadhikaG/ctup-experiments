#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <Eigen/src/Core/util/Constants.h>
#include <iostream>
#include "jac_gen.h"

int main(int argc, char ** argv)
{
  using namespace pinocchio;

  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;

  Data data(model);

  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;

  Eigen::Matrix<double, 6, Eigen::Dynamic> J;
  J.resize(6, model.nv);

  computeJointJacobians(model, data, q);
  getJointJacobian(model, data, model.njoints-1, WORLD, J);

  std::cout << "---PINOCCHIO DEBUG---\n";

  std::cout << J << "\n";

  std::cout << "-------------------\n";

  //=======================================
  Eigen::MatrixXd ctup_res(6, model.nv);

  std::cout << "--- CTUP DEBUG---\n";

  ctup_res = ctup_gen::get_eef_world_jacobian(q);

  std::cout << ctup_res << "\n";

  std::cout << "-------------------\n";
}
