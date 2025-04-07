#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "Eigen/Dense"
#include "pinocchio/utils/timer.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <cppad/cg/model/llvm/llvm.hpp>
#include "pinocchio/algorithm/rnea.hpp"
#include "rnea_gen.h"
#include <iostream>

int main(int argc, char ** argv)
{
  using namespace pinocchio;
  using namespace CppAD;
  using namespace CppAD::cg;
  
  PinocchioTicToc timer(PinocchioTicToc::NS);
  //const int NBT = 100 * 100;
  const int NBT = 100000;

  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = (argc<=1) ? PINOCCHIO_MODEL_DIR + std::string("/others/robots/ur_description/urdf/ur5_robot.urdf") : argv[1];
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;

  size_t last_joint = model.njoints - 1;
  
  // Create data required by the algorithms
  Data data(model);
  
  //Eigen::VectorXd q(model.njoints-1);
  //q << -0.3369, 1.2966, -0.6775, -1.4218, -0.7067, -0.135, -1.1495;
  //Eigen::VectorXd qd(model.nv);
  //qd << 0.433, -0.4216, -0.6454, -1.8605, -0.0131, -0.4583, 0.7412;
  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);
  Eigen::VectorXd qd = randomConfiguration(model);

  Eigen::VectorXd qdd = Eigen::VectorXd::Zero(model.nv);

  std::cout << "q: " << q.transpose() << std::endl;
  std::cout << "qd: " << qd.transpose() << std::endl;

  // ----------- PINOCCHIO CODEGEN START ----------- //

  // using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;

  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs;

  // make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);

  ADVectorXs ad_X;
  ADVectorXs ad_Y;
  ad_X = ADVectorXs(ad_model.nq + ad_model.nv);
  ad_Y = ADVectorXs(ad_model.nv);

  ADVectorXs zeros = ADVectorXs::Zero(ad_model.nv);
  Independent(ad_X);
  rnea(
      ad_model, ad_data, ad_X.head(ad_model.nq), ad_X.segment(ad_model.nq, ad_model.nv), zeros);
  ad_Y = ad_data.tau;
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

  // ----------- PINOCCHIO CODEGEN END ----------- //

  Eigen::VectorXd ctup_res, pin_res;

  Eigen::VectorXd joined(q.size() + qd.size());
  joined << q, qd;

  timer.tic();
  SMOOTH(NBT) {
    pin_res = g_model->ForwardZero(joined);
  }
  std::cout << "pin cg avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);

  //ctup_gen::set_X_T();
  //ctup_gen::robot_data * rd = new ctup_gen::robot_data;
  //ctup_gen::init_rd(rd);

  timer.tic();
  SMOOTH(NBT) {
    //ctup_gen::init_gl();
    ctup_res = ctup_gen::rnea(q, qd);
    //ctup_res = ctup_gen::rnea(rd, q, qd);
  }
  std::cout << "ctup gen avg time taken (us): \t\t\t\t";
  timer.toc(std::cout, NBT);

  std::cout << "--------FINAL RES--------\n";

  std::cout << "ctup_res: \n" << ctup_res << std::endl;
  std::cout << "pin_res: \n" << pin_res << std::endl;
}
