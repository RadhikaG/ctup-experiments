#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include "blaze/Math.h"
#include "rla_fk/gen/fk_gen_batched.h"
#include <iostream>

#define NQ 7 // change to: iiwa - 7, hyq - 12, baxter - 19

//static blaze::StaticMatrix<blaze::StaticVector<double, 4>, 6, 6> fk (blaze::StaticVector<blaze::StaticVector<double, 4>, 19>& arg1) {
//  blaze::StaticVector<blaze::StaticVector<double, 4>, 19>& var0 = arg1;

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
  
  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);

  blaze::StaticVector<blaze::StaticVector<double, 4>, NQ> q_blaze;

  for (size_t d = 0; d < NQ; ++d) {
    // broadcasting single double qs[i][d] entry to wide blaze array
    q_blaze[d] = q[d];
  }

  blaze::StaticMatrix<blaze::StaticVector<double, 4>, 6, 6> ctup_res;
  Eigen::Matrix<double, 6, 6> pin_res;

  std::cout << "---PINOCCHIO DEBUG---\n";

  Data data(model);
  forwardKinematics(model,data,q);
  pin_res = data.oMi[model.njoints-1];

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

  std::cout << "---CTUP  DEBUG---\n";

  //ctup_gen::set_X_T();

  ctup_res = ctup_gen::fk(q_blaze);

  std::cout << "-------------------\n";

  std::cout << "--------FINAL RES--------\n";

  // we know ctup_res has broadcasted entries
  Eigen::Matrix<double, 6, 6> ctup_res_single;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      ctup_res_single(j, i) = ctup_res(i, j)[0];

  std::cout << "ctup_res: \n" << ctup_res_single << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;

}

