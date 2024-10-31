#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include "fk_gen.h"
#include <iostream>

int main(int argc, char ** argv)
{
  using namespace pinocchio;

  PinocchioTicToc timer(PinocchioTicToc::US);
  //const int NBT = 1000 * 100;
  const int NBT = 1;
  
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;
  
  // Sample a random configuration
  PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(NBT);

  for (size_t i = 0; i < NBT; ++i)
    qs[i] = randomConfiguration(model);

  //std::cout << "q: " << q.transpose() << std::endl;

  Eigen::Matrix<double, 6, 6> ctup_res, pin_res;

  Data data(model);

  ctup_gen::set_X_T();

  timer.tic();
  SMOOTH(NBT)
  {
    ctup_res = ctup_gen::fk(qs[_smooth]);
  }
  std::cout << "gen avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);

  timer.tic();
  SMOOTH(NBT)
  {
    forwardKinematics(model,data,qs[_smooth]);
  }
  std::cout << "pin avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);

  //model.joints[1].calc(data.joints[1].derived(), qs[0]);
  //pin_res = data.joints[1].M();

  pin_res = data.oMi[model.njoints-1];

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
  std::cout << "diff: \n" << ctup_res - pin_res << std::endl;
}
