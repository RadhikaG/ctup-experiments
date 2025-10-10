#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
#include <argparse/argparse.hpp>
// PINOCCHIO_MODEL_DIR is defined by the CMake but you can define your own directory here.
#ifndef PINOCCHIO_MODEL_DIR
  #define PINOCCHIO_MODEL_DIR "path_to_the_model_dir"
#endif

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("pin_fk_codegen_vectorized_comp");

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

  const int N_ITER = 1000000;
  const int NBT = 16;

  using namespace CppAD;
  using namespace CppAD::cg;
  using namespace pinocchio;

  // using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;

  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs;
  //typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 36> ADMatrixDyn6x6; // spatial Xdorm
  typedef Eigen::Matrix<ADCG, 6, 6> ADMatrixDyn6x6; // spatial Xdorm
  
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = program.get<std::string>("urdf");
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << ", njoints: " << model.njoints << "\n";

  // Sample a random configuration
  //PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(N_ITER);
  //for (size_t i = 0; i < N_ITER; ++i)
  //  qs[i] = randomConfiguration(model).cast<double>();
  Eigen::VectorXd q = randomConfiguration(model);

  // make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);
  ADVectorXs ad_X = ADVectorXs(ad_model.nq);
  ADMatrixDyn6x6 ad_Ys[model.njoints];

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
  Eigen::VectorXd y; // for flattened pin cg output

  std::cout << y << "\n";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < N_ITER; i++) {
    for (int j = 0; j < NBT; j++) {
      y = g_model->ForwardZero(q);
    }
  }
  auto end = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  Eigen::Matrix<double, 6, 6> final_fk_res;
  final_fk_res = Eigen::Map<const Eigen::MatrixXd>(y.data() + y.size() - 36, 6, 6);
  std::cout << final_fk_res << "\n";
  std::cout << "pin cg: avg time taken (ns): " << elapsed.count() / N_ITER << "\n";
  // JIT done

  // for C++ stdout
  //CodeHandler<double> handler;
  //CppAD::vector<CGD> indVars((size_t)ad_X.size());
  //handler.makeVariables(indVars);

  //CppAD::vector<CGD> fwd_zero = fun.Forward(0, indVars);

  //LanguageC<double> langC("double");
  //LangCDefaultVariableNameGenerator<double> nameGen;

  //std::ostringstream code;
  //handler.generateCode(code, langC, fwd_zero, nameGen);
  //std::cout << code.str();
  // C++ stdout done
}

