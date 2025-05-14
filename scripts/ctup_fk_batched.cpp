#include "fk_gen_batched.h"
#include "blaze/Math.h"
#include <iostream>
#include <chrono>

#define SMOOTH(s) for (size_t _smooth = 0; _smooth < s; ++_smooth)

int main(int argc, char ** argv)
{
  //const int NBT = 100 * 100;
  const int NBT = 10000;

  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";

  size_t nq = 0;
  if (urdf_filename.find("iiwa_rbd_accel.urdf") != std::string::npos)
    nq = 7;
  else if (urdf_filename.find("hyq_simple.urdf") != std::string::npos)
    nq = 12;
  else if (urdf_filename.find("baxter_simple.urdf") != std::string::npos)
    nq = 19;
  else
    assert(false && "script doesn't work for other robots");
  
  blaze::StaticVector<blaze::StaticVector<double, 8>, 12> qs_blaze[NBT];

  for (size_t i = 0; i < NBT; ++i) {
    for (size_t d = 0; d < nq; ++d) {
      // broadcasting single double qs[i][d] entry to wide blaze array
      qs_blaze[i][d] = d;
    }
  }

  blaze::StaticMatrix<blaze::StaticVector<double, 8>, 6, 6> ctup_res;

  auto start = std::chrono::steady_clock::now();
  SMOOTH(NBT)
  {
    ctup_res = ctup_gen::fk(qs_blaze[_smooth]);
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "ctup gen avg time taken (ns): \t\t\t\t";
  std::cout << elapsed.count() / (NBT) << std::endl;

  // we know ctup_res has broadcasted entries
  Eigen::Matrix<double, 6, 6> ctup_res_single;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      ctup_res_single(j, i) = ctup_res(i, j)[0];

  std::cout << "ctup_res: \n" << ctup_res_single << std::endl;
}
