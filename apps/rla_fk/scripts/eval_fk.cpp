#include "Eigen/Dense"
#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include "rla_fk/rla_fk_dispatcher/fk_dispatcher.h"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_fk");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa", "hyq", "baxter");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  using namespace pinocchio;
  using namespace CppAD;
  using namespace CppAD::cg;
  using namespace ctup_runtime::dispatcher;

  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string robot_name = program.get<std::string>("--robot");
  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  // Get RLA FK function from dispatcher
  auto rla_fk_func = FkDispatcher::get_fk_scalar_function(robot_name);

  PinocchioTicToc timer(PinocchioTicToc::NS);
  const int NBT = 10000;

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  // Sample random configurations
  PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(NBT);
  for (size_t i = 0; i < NBT; ++i) {
    qs[i] = randomConfiguration(model);
  }

  std::cout << "Initializing Pinocchio JIT codegen...\n";

  /** Pinocchio codegen start **/
  // using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;

  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs;
  typedef Eigen::Matrix<ADCG, 6, 6> ADMatrix6x6;

  // make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);
  ADVectorXs ad_X = ADVectorXs(ad_model.nq);
  ADMatrix6x6 ad_Ys[model.njoints];

  Independent(ad_X);

  forwardKinematics(ad_model, ad_data, ad_X);

  for (int i = 0; i < model.njoints; i++) {
    ad_Ys[i] = ad_data.oMi[i];
  }

  ADVectorXs ad_Y_flat(model.njoints * 36);
  for (int jid = 0; jid < model.njoints; jid++) {
    int joint_xform_start = jid * 36;
    for (int i = 0; i < 36; i++)
      ad_Y_flat(joint_xform_start + i) = ad_Ys[jid](i);
  }

  // ADFun only takes ADVectorXs as input
  ADFun<CGD> fun(ad_X, ad_Y_flat);

  // for JIT
  ModelCSourceGen<double> cgen(fun, "model");
  cgen.setCreateForwardZero(true);
  ModelLibraryCSourceGen<double> libcgen(cgen);

  LlvmModelLibraryProcessor<double> p(libcgen);

  std::unique_ptr<LlvmModelLibrary<double>> llvmModelLib = p.create();
  SaveFilesModelLibraryProcessor<double> p2(libcgen);
  p2.saveSources();

  std::unique_ptr<GenericModel<double>> g_model = llvmModelLib->model("model");
  /** Pinocchio codegen end **/

  std::cout << "\n=== Running Performance Evaluation ===\n\n";

  Eigen::Matrix<double, 6, 6> rla_res, pin_cg_res, pin_res;
  Eigen::VectorXd y; // for flattened pin cg output

  Data data(model);

  // Benchmark RLA FK
  timer.tic();
  SMOOTH(NBT)
  {
    rla_res = rla_fk_func(qs[_smooth]);
  }
  std::cout << "RLA FK avg time (ns):           \t\t";
  timer.toc(std::cout, NBT);

  // Benchmark Pinocchio JIT codegen FK
  timer.tic();
  SMOOTH(NBT)
  {
    y = g_model->ForwardZero(qs[_smooth]);
  }
  std::cout << "Pinocchio JIT codegen avg time (ns):    \t";
  timer.toc(std::cout, NBT);

  // Benchmark vanilla Pinocchio FK
  timer.tic();
  SMOOTH(NBT)
  {
    forwardKinematics(model, data, qs[_smooth]);
  }
  std::cout << "Pinocchio vanilla avg time (ns):        \t";
  timer.toc(std::cout, NBT);

  // Extract final results
  pin_res = data.oMi[model.njoints-1];
  pin_cg_res = Eigen::Map<const Eigen::MatrixXd>(y.data() + y.size() - 36, 6, 6);

  std::cout << "\n=== Final Results (Last Configuration) ===\n\n";
  std::cout << "RLA FK result:\n" << rla_res << "\n\n";
  std::cout << "Pinocchio JIT codegen result:\n" << pin_cg_res << "\n\n";
  std::cout << "Pinocchio vanilla result:\n" << pin_res << "\n\n";

  // Compare RLA with transpose of Pinocchio outputs
  std::cout << "\n=== Transpose Comparison ===\n\n";
  std::cout << "Pinocchio JIT codegen result (transposed):\n" << pin_cg_res.transpose() << "\n\n";
  std::cout << "Pinocchio vanilla result (transposed):\n" << pin_res.transpose() << "\n\n";

  double error_cg = (rla_res - pin_cg_res.transpose()).norm();
  double error_vanilla = (rla_res - pin_res.transpose()).norm();

  std::cout << "Error between RLA and Pinocchio JIT codegen: " << error_cg << "\n";
  std::cout << "Error between RLA and Pinocchio vanilla: " << error_vanilla << "\n";

  return 0;
}
