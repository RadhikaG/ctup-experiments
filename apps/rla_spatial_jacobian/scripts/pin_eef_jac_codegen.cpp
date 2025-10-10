#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
#include <argparse/argparse.hpp>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("pin_eef_jac_codegen");

  program.add_argument("urdf")
      .help("path to the URDF file")
      .default_value(std::string(PINOCCHIO_MODEL_DIR) + "/others/robots/ur_description/urdf/ur5_robot.urdf");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  const int N_ITER = 100000;
  //const int N_ITER = 1;

  using namespace CppAD;
  using namespace CppAD::cg;
  using namespace pinocchio;

  // using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;

  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs; // Nx1 joint configuration type
  typedef Eigen::Matrix<ADCG, 6, Eigen::Dynamic> ADMatrixDyn6xN; // 6xN jacobian type
  
  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = program.get<std::string>("urdf");
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;

  // make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);
  ADVectorXs ad_X = ADVectorXs(ad_model.nq);

  ADMatrixDyn6xN ad_J;
  ad_J.resize(6, model.nv);

  Independent(ad_X);

  computeJointJacobians(ad_model, ad_data, ad_X);
  // last joint jac
  ad_J = getJointJacobian(ad_model, ad_data, model.njoints-1, WORLD);

  // flatten to output vector
  ADVectorXs ad_Y_flat(6 * model.nv);

  // col major storage so Eigen::Map can deserialize correctly
  for (int jv = 0; jv < model.nv; jv++) {
    for (int i = 0; i < 6; i++) {
      ad_Y_flat[jv * 6 + i] = ad_J.coeffRef(i, jv);
    }
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
  Eigen::VectorXd q = randomConfiguration(model);
  Eigen::VectorXd y = g_model->ForwardZero(q);

  //std::cout << y << "\n";
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < N_ITER; i++) {
    y = g_model->ForwardZero(q);
  }
  auto end = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

  std::cout << "y: " << y << "\n";

  Eigen::Matrix<double, 6, Eigen::Dynamic> final_jac_res;
  final_jac_res.resize(6, model.nv);
  final_jac_res = Eigen::Map<const Eigen::MatrixXd>(y.data(), 6, model.nv);

  std::cout << final_jac_res << "\n";
  std::cout << "pin cg: avg time taken (ns): " << elapsed.count() / N_ITER << "\n";
}
