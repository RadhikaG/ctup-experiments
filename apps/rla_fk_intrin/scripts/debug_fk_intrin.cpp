#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "rla_fk_intrin/rla_fk_intrin_dispatcher/fk_dispatcher.h"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_fk_intrin");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  typedef Eigen::Matrix<double, 6, 6> EigenSpatialXform;
  using namespace pinocchio;
  using namespace ctup_runtime::dispatcher;
  using namespace CppAD;
  using namespace CppAD::cg;

  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string robot_name = program.get<std::string>("--robot");
  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  // Use π/4 for all joints instead of random configuration
  Eigen::VectorXd q = Eigen::VectorXd::Constant(model.nq, M_PI / 4.0);
  std::cout << "q: " << q.transpose() << std::endl;

  // Result matrices
  EigenSpatialXform pin_vanilla_res;
  EigenSpatialXform pin_codegen_res;
  EigenSpatialXform rla_intrin_res;

  std::cout << "\n=== Running Debug Evaluation ===\n\n";

  // ============================================
  // 1. Vanilla Pinocchio FK
  // ============================================
  std::cout << "---PINOCCHIO VANILLA DEBUG---\n";

  Data data(model);
  forwardKinematics(model, data, q);
  pin_vanilla_res = data.oMi[model.njoints-1];

  std::cout << pin_vanilla_res << "\n\n";

  // ============================================
  // 2. Pinocchio Codegen FK
  // ============================================
  std::cout << "---PINOCCHIO CODEGEN DEBUG---\n";

  // Using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;
  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs;
  typedef Eigen::Matrix<ADCG, 6, 6> ADMatrix6x6;

  // Make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);
  ADVectorXs ad_X = ADVectorXs(ad_model.nq);

  Independent(ad_X);

  forwardKinematics(ad_model, ad_data, ad_X);
  ADMatrix6x6 ad_oMi = ad_data.oMi[model.njoints-1].toActionMatrix();

  // Flatten to output vector (col major storage)
  ADVectorXs ad_Y_flat(36);
  for (int col = 0; col < 6; col++) {
    for (int row = 0; row < 6; row++) {
      ad_Y_flat[col * 6 + row] = ad_oMi.coeffRef(row, col);
    }
  }

  ADFun<CGD> fun(ad_X, ad_Y_flat);

  // JIT compilation
  ModelCSourceGen<double> cgen(fun, "model");
  cgen.setCreateForwardZero(true);
  ModelLibraryCSourceGen<double> libcgen(cgen);

  LlvmModelLibraryProcessor<double> p(libcgen);
  std::unique_ptr<LlvmModelLibrary<double>> llvmModelLib = p.create();

  std::unique_ptr<GenericModel<double>> g_model = llvmModelLib->model("model");

  // Single evaluation
  Eigen::VectorXd y = g_model->ForwardZero(q);

  // Reshape result
  pin_codegen_res = Eigen::Map<const Eigen::MatrixXd>(y.data(), 6, 6);

  std::cout << pin_codegen_res << "\n\n";

  // ============================================
  // 3. RLA Intrinsic FK (batched, extract first)
  // ============================================
  std::cout << "---RLA INTRINSIC FK DEBUG---\n";

  auto rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<iiwaTraits>();

  // Prepare batched input as float array with different values per batch
  // Layout: [ndof * 8] = [7 * 8] floats
  // Each joint's values for all 8 batch lanes are stored contiguously
  // joint 0: [batch0, batch1, ..., batch7], joint 1: [batch0, batch1, ..., batch7], ...
  // Batch 0 uses q, other batches use zeros for simplicity
  std::vector<float> q_batched_data(7 * 8, 0.0f);
  for (size_t joint = 0; joint < 7; ++joint) {
    q_batched_data[joint * 8 + 0] = static_cast<float>(q[joint]);  // Only batch 0 has non-zero values
  }

  // Compute batched FK
  Eigen::MatrixXd result = Eigen::MatrixXd::Zero(8, 36);
  rla_fk_func(q_batched_data.data(), result);

  // Extract first configuration (batch index 0)
  // Result is stored as (batch_size, 36) where 36 is the flattened 6x6 matrix
  // Need to copy row to contiguous memory since Eigen matrix is column-major
  Eigen::VectorXd batch0_flat = result.row(0);
  rla_intrin_res = Eigen::Map<const Eigen::MatrixXd>(batch0_flat.data(), 6, 6);

  std::cout << rla_intrin_res << "\n\n";

  // ============================================
  // 4. Compare results
  // ============================================
  std::cout << "--------COMPARISON--------\n";

  double error_vanilla = (rla_intrin_res - pin_vanilla_res).norm();
  std::cout << "Error (RLA Intrin vs Pinocchio Vanilla): " << error_vanilla << "\n";

  if (error_vanilla < 1e-4) {
    std::cout << "✓ Results match!\n";
  } else {
    std::cout << "✗ Results do not match!\n";
  }

  return 0;
}
