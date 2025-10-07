// export CXX=/home/ubuntu/build/gcc-15.1-build/gcc-15.1.0-install/bin/g++
// $CXX -std=c++17 -O3 -ffast-math -gno-as-locview-support -I../gen -I../deps/compile-time-urdf-parser/deps/eigen -I../deps/compile-time-urdf-parser/deps/blaze ../scripts/ctup_fk_batched.cpp -o ctup_fk_batched
// export LD_LIBRARY_PATH=/home/ubuntu/build/gcc-15.1-build/gcc-15.1.0-install/lib64/
#include "rla_fk/gen/fk_gen_batched.h"
#include "blaze/Math.h"
#include <iostream>
#include <chrono>

#define SMOOTH(s) for (size_t _smooth = 0; _smooth < s; ++_smooth)
#define NQ 7 // change for iiwa - 7, hyq - 12, baxter - 19
#define SIMD_WIDTH 4

int main(int argc, char ** argv)
{
  const int iterations = 1000000;
  const int NBT = 1;

  assert(argc == 2 && "missing urdf filename");

  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = argv[1];
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
  
  blaze::DynamicVector<blaze::StaticVector<blaze::StaticVector<double, SIMD_WIDTH>, NQ>> qs_blaze(NBT);

  for (size_t i = 0; i < NBT; ++i) {
    for (size_t d = 0; d < NQ; ++d) {
      // broadcasting single double qs[i][d] entry to wide blaze array
      qs_blaze[i][d] = d;
    }
  }

  blaze::StaticMatrix<blaze::StaticVector<double, SIMD_WIDTH>, 6, 6> ctup_res;

  auto start = std::chrono::steady_clock::now();
  SMOOTH(iterations)
  {
    ctup_res = ctup_gen::fk(qs_blaze[0]);
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "ctup gen avg time taken (ns): \t\t\t\t";
  //std::cout << elapsed.count() / (NBT) << std::endl;
  std::cout << elapsed.count() / (iterations) << std::endl;

  // we know ctup_res has broadcasted entries
  Eigen::Matrix<double, 6, 6> ctup_res_single;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      ctup_res_single(j, i) = ctup_res(i, j)[0];

  std::cout << "ctup_res: \n" << ctup_res_single << std::endl;
}
