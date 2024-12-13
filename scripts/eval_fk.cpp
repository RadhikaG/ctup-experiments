#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/utils/timer.hpp"
#include <cppad/cg/model/llvm/llvm.hpp>
#include "fk_gen_dense.h"
//#include "fk_gen_unrolled.h"
#include <iostream>

int main(int argc, char ** argv)
{
  using namespace pinocchio;
  using namespace CppAD;
  using namespace CppAD::cg;

  PinocchioTicToc timer(PinocchioTicToc::NS);
  //const int NBT = 100 * 100;
  const int NBT = 10000;
  
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

  Eigen::Matrix<double, 6, 6> ctup_res, pin_res, pin_cg_res;
  Eigen::VectorXd y; // for flattened pin cg output

  Data data(model);

  ctup_gen::set_X_T();

  timer.tic();
  SMOOTH(NBT)
  {
    ctup_res = ctup_gen::fk(qs[_smooth]);
  }
  std::cout << "ctup gen avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);

  timer.tic();
  SMOOTH(NBT)
  {
    y = g_model->ForwardZero(qs[_smooth]);
  }
  std::cout << "pin cg avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);

  timer.tic();
  SMOOTH(NBT)
  {
    forwardKinematics(model,data,qs[_smooth]);
  }
  std::cout << "pin vanilla avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);


  pin_res = data.oMi[model.njoints-1];
  pin_cg_res = Eigen::Map<const Eigen::MatrixXd>(y.data() + y.size() - 36, 6, 6);

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_cg_res: \n" << pin_cg_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}
