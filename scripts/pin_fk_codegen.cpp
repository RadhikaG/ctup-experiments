#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
// PINOCCHIO_MODEL_DIR is defined by the CMake but you can define your own directory here.
#ifndef PINOCCHIO_MODEL_DIR
  #define PINOCCHIO_MODEL_DIR "path_to_the_model_dir"
#endif

int main(int argc, char ** argv)
{
  using namespace CppAD;
  using namespace CppAD::cg;
  using namespace pinocchio;

  // using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;

  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs;
  
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;

  // make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);
  ADVectorXs ad_X = ADVectorXs(ad_model.nq);
  ADVectorXs ad_Y = ADVectorXs(3);//ad_model.nq);
  Independent(ad_X);

  forwardKinematics(ad_model, ad_data, ad_X);
  ad_Y = ad_data.oMi[(ad_model.njoints)-1].translation();
  ADFun<CGD> fun(ad_X, ad_Y);

  // for JIT
  ModelCSourceGen<double> cgen(fun, "model");
  cgen.setCreateForwardZero(true);
  ModelLibraryCSourceGen<double> libcgen(cgen);

  LlvmModelLibraryProcessor<double> p(libcgen);

  std::unique_ptr<LlvmModelLibrary<double>> llvmModelLib = p.create();
  SaveFilesModelLibraryProcessor<double> p2(libcgen);
  p2.saveSources();

  std::unique_ptr<GenericModel<double>> g_model = llvmModelLib->model("model");
  Eigen::VectorXd q = randomConfiguration(model);
  Eigen::VectorXd y = g_model->ForwardZero(q);

  std::cout << y << "\n";

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
}

