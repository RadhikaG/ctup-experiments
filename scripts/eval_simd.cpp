//#include "fk_gen_dense.h"
//#include "fk_gen_unrolled.h"
#include "fk_gen_unrolled_simd.h"
//#include "fk_gen_unrolled_simd_size16.h"
//#include "fk_gen_unrolled_simd_cpy.h"
#include <iostream>
#include <chrono>
#include "Eigen/Dense"
#include <blaze/Math.h>

int main(int argc, char ** argv)
{
  std::cout << "Eigen version: "
              << EIGEN_WORLD_VERSION << "."
              << EIGEN_MAJOR_VERSION << "."
              << EIGEN_MINOR_VERSION << std::endl;

  const int NBT = 16;
  int it=1000000;

  Eigen::VectorXd qs[16];

  
  for (int i = 0; i < NBT; ++i){
    //BAXTER
    //qs[i].resize(19);
    //qs[i]<<3.0, 6.2, 3.56, 5.67,3.76, 9.2,13.56, 55.67, 3.12, 6.22, 3.556, 5.767,3.706, 9.12, 13.516166, 15.67, 16.23, 9.32, 10.11;

    //HYQ
    //qs[i].resize(12);
    //qs[i]<<3.0, 6.2, 3.56, 5.67,3.76, 9.2,13.56, 55.67, 3.12, 6.22, 3.556, 5.767;

    //iiwa
    qs[i].resize(7);
    qs[i]<<3.0, 6.2, 3.56, 5.67,3.76, 9.2,13.56;
  }
  
 /*
 for (int i = 0; i < NBT; ++i){
    qs[i].resize(2);
    qs[i]<<3.0, 6.2;
  }
  */
  
  Eigen::Matrix<float, 6, 6> ctup_res,ctup_res2,ctup_res_3,pin_res, pin_cg_res;
  Eigen::VectorXd y;
  blaze::StaticMatrix<blaze::StaticVector<float, 16>, 6, 6> res;
  Eigen::Array<Eigen::Array<float, 16,1>, 6, 6> res_2;
  blaze::StaticVector<blaze::StaticVector<float, 16>, 7> q_gen;
  Eigen::Array<Eigen::Array<float, 16,1>, 7,1> q_gen_2;
  
  for(int n=0;n<16;++n){
    for(int k=0;k<7;++k){
      (q_gen[k])[n]=(qs[n])(k);
      (q_gen_2(k,0))(n,0)=(qs[n])(k);
    }
  }
  
  //std::cout<<q_gen<<std::endl<<std::endl;
  
  
  auto start = std::chrono::steady_clock::now();
  for(int i=0;i<it;++i){
    res=ctup_gen::fk(q_gen);
  }
  auto end = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "SIMD BLAZE (ns): \t\t\t\t" << elapsed.count()/(it)<<std::endl;
  
  /*
  for(int k=0;k<36;++k){
    ctup_res(k/6,k%6)=(res(k/6,k%6))[15];
  }
  */
  /*
  auto start2 = std::chrono::steady_clock::now();
  for(int i=0;i<it;++i){
    res_2=ctup_gen2::fk(q_gen_2);
  }
  auto end2 = std::chrono::steady_clock::now();
  auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
  std::cout << "SIMD EIGEN(ns): \t\t\t\t" << elapsed2.count()/(it)<<std::endl;
  
  
  for(int k=0;k<36;++k){
    ctup_res_3(k/6,k%6)=(res_2(k/6,k%6))(15,0);
  }
  */

  //ctup_gen1::set_X_T();

  /*
  auto start1 = std::chrono::steady_clock::now();
  for(int l=0;l<NBT;++l)
  {
    for(int i=0;i<it;++i){
      ctup_res2 = ctup_gen::fk(qs[i%16]);
    }
  }
  
  
  auto end1 = std::chrono::steady_clock::now();
  auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
  
  
  
  std::cout << "Dense (ns): \t\t\t\t" << elapsed1.count()/(it)<<std::endl;
  */
  
  //std::cout << "Dense per iteration(ns): \t\t\t\t" << elapsed1.count()/(it*NBT)<<std::endl;
  /*
  std::cout << "SIMD BLAZE: \n" << ctup_res << std::endl;

  //std::cout << "SIMD EIGEN: \n" << ctup_res_3 << std::endl;
  */
  //std::cout << "DENSE_res: \n" << ctup_res2 << std::endl;
  
}
