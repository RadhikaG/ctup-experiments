#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include <cppad/cg/model/llvm/llvm.hpp>
#include "blaze/Math.h"
#include "rla_fk/gen/fk_gen_batched.h"
#include <iostream>
#include <argparse/argparse.hpp>

#define NQ 7 // change for iiwa - 7, hyq - 12, baxter - 19
#define SIMD_WIDTH 4

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_fk_batched");

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
  using namespace CppAD;
  using namespace CppAD::cg;

  PinocchioTicToc timer(PinocchioTicToc::NS);
  //const int NBT = 100 * 100;
  const int NBT = 10000;

  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = program.get<std::string>("urdf");
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;
  
  // Sample a random configuration
  PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(NBT);

  for (size_t i = 0; i < NBT; ++i) {
    qs[i] = randomConfiguration(model);
  }

  blaze::StaticVector<blaze::StaticVector<double, SIMD_WIDTH>, NQ> qs_blaze[NBT];

  for (size_t i = 0; i < NBT; ++i) {
    for (size_t d = 0; d < NQ; ++d) {
      // broadcasting single double qs[i][d] entry to wide blaze array
      qs_blaze[i][d] = qs[i][d];
    }
  }


  std::cout << "initializing pinocchio codegen...\n";

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
  ADVectorXs ad_X = ADVectorXs(ad_model.nq); // input is a function of actuated dofs
  ADMatrix6x6 ad_Ys[model.njoints]; // output is a function of # robot geoms

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

  blaze::StaticMatrix<blaze::StaticVector<double, 4>, 6, 6> ctup_res;
  Eigen::Matrix<double, 6, 6> pin_res, pin_cg_res;
  Eigen::VectorXd y; // for flattened pin cg output

  //ctup_gen::set_X_T();

  timer.tic();
  SMOOTH(NBT)
  {
    ctup_res = ctup_gen::fk(qs_blaze[_smooth]);
  }
  std::cout << "ctup gen avg time taken (ns): \t\t\t\t";
  timer.toc(std::cout, NBT);

  // we know ctup_res has broadcasted entries
  Eigen::Matrix<double, 6, 6> ctup_res_single;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      ctup_res_single(j, i) = ctup_res(i, j)[0];

  std::cout << "ctup_res: \n" << ctup_res_single << std::endl;

  std::cout << "running pinocchio...\n";

  Data data(model);

  timer.tic();
  SMOOTH(NBT)
  {
    for (size_t w = 0; w < SIMD_WIDTH; w++)
      y = g_model->ForwardZero(qs[_smooth]);
  }
  std::cout << "pin cg avg time taken (ns): \t\t\t\t";
  timer.toc(std::cout, NBT);

  timer.tic();
  SMOOTH(NBT)
  {
    for (size_t w = 0; w < SIMD_WIDTH; w++)
      forwardKinematics(model,data,qs[_smooth]);
  }
  std::cout << "pin vanilla avg time taken (ns): \t\t\t\t";
  timer.toc(std::cout, NBT);

  pin_res = data.oMi[model.njoints-1];
  pin_cg_res = Eigen::Map<const Eigen::MatrixXd>(y.data() + y.size() - 36, 6, 6);

  std::cout << "pin_cg_res: \n" << pin_cg_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}

