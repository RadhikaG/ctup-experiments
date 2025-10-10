#include "rla_spatial_jacobian/runtime/utils.h"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/frames.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <Eigen/src/Core/util/Constants.h>
#include <iostream>
#include <argparse/argparse.hpp>
#include "rla_spatial_jacobian/gen/jac_gen.h"
#include "rla_spatial_jacobian/gen/batched_jac_panda.h"

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_eef_jac");

  program.add_argument("urdf")
      .help("path to the URDF file");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  using namespace pinocchio;

  size_t N_IT = 10000;

  const std::string urdf_filename = program.get<std::string>("urdf");
  std::cout << urdf_filename << "\n";

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;

  Data data(model);

  Eigen::VectorXd q(model.nq);
  q = randomConfiguration(model);
  //q << 2.01874, -0.387108, 1.67997, -0.563517, 2.4428, 0.685047, -0.977821;
  std::cout << "q: " << q.transpose() << std::endl;

  Eigen::Matrix<double, 6, Eigen::Dynamic> J;
  J.resize(6, model.nv);
  J.setZero();

  {
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < N_IT; ++i) {
      computeJointJacobians(model, data, q);
      J = getJointJacobian(model, data, model.njoints-1, WORLD);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "PIN NONCG JAC (ns): \t\t\t\t" << elapsed.count()/(N_IT)<<std::endl;
  }

  std::cout << "---PINOCCHIO DEBUG---\n";

  Eigen::Matrix<double, 6, Eigen::Dynamic> J_reord;
  J_reord.resize(6, model.nv);
  J_reord.bottomRows<3>() = J.topRows<3>();
  J_reord.topRows<3>() = J.bottomRows<3>();
  std::cout << J_reord << "\n";

  //typedef Eigen::Matrix<double, 4, 4> EigenHomogXform;
  //typedef Eigen::Matrix<double, 6, 6> AdjMat;

  //EigenHomogXform X_0;
  //AdjMat adj;

  //std::cout << "forward kin:" << "\n";
  //for (size_t i = 1; i < (size_t)model.njoints; i++) {
  //  if (i <= 4) {
  //    X_0 = data.oMi[i].toHomogeneousMatrix();
  //    std::cout << i << ":\n";
  //    std::cout << data.oMi[i].toHomogeneousMatrix() << "\n";

  //    Eigen::Matrix3d rot = data.oMi[i].rotation();
  //    Eigen::Matrix3d skew_trans = skew(data.oMi[i].translation());
  //    adj = data.oMi[i].toActionMatrix();

  //    std::cout << "rot:\n" << rot << "\n";
  //    std::cout << "skew-trans:\n" << skew_trans << "\n";
  //    std::cout << "prod:\n" << skew_trans * rot << "\n";

  //    std::cout << "adj:\n" << adj << "\n";
  //    std::cout << "-------------------\n";
  //  }
  //}

  //std::cout << "-------------------\n";

  //=======================================

  Eigen::MatrixXd ctup_res(6, model.nv);

  std::cout << "--- CTUP DEBUG---\n";


  {
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < N_IT; ++i) {
      ctup_res = ctup_gen::get_eef_world_jacobian(q);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "CTUP JAC (ns): \t\t\t\t" << elapsed.count()/(N_IT)<<std::endl;
  }

  std::cout << ctup_res << "\n";

  std::cout << "-------------------\n";

  //=======================================

  const size_t SIMD_WIDTH = 8;
  Eigen::Matrix<float, SIMD_WIDTH, Eigen::Dynamic> batched_ctup_res(SIMD_WIDTH, 6 * model.nv);

  rla_jac_runtime::ConfigurationBlockRobot<rla_jac_runtime::robots::Panda> batched_q;
  for (size_t i = 0; i < (size_t)model.nq; i++) {
    batched_q[i] = q(i);
  }

  std::cout << "--- CTUP BATCHED DEBUG---\n";

  {
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < N_IT; ++i) {
      rla_jac_gen::batched_jac(batched_q, batched_ctup_res);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "CTUP BATCHED JAC (ns): \t\t\t\t" << elapsed.count()/(N_IT)<<std::endl;
  }

  Eigen::MatrixXd slice(6, model.nq);
  for (int r = 0; r < 6; r++)
    for (int c = 0; c < model.nq; c++)
      slice(r, c) = batched_ctup_res(0, r * model.nq + c);

  std::cout << slice << "\n";

  std::cout << "-------------------\n";
}
