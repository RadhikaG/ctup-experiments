#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/jacobian.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "rla_spatial_jacobian/rla_spatial_jac_dispatcher/jac_dispatcher.h"
#include "blaze/Math.h"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_batched_jac");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("panda", "iiwa", "hyq", "baxter");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  using namespace pinocchio;
  using namespace rla_jac_runtime::dispatcher;
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
  std::cout << "nq: " << model.nq << std::endl;
  std::cout << "nv: " << model.nv << std::endl;

  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "\nq: " << q.transpose() << std::endl;

  // Result matrices
  Eigen::MatrixXd pin_vanilla_res(6, model.nv);
  Eigen::MatrixXd pin_codegen_res(6, model.nv);
  Eigen::MatrixXd rla_res(6, model.nv);

  std::cout << "\n=== Running Debug Evaluation ===\n\n";

  // ============================================
  // 1. Vanilla Pinocchio Jacobian
  // ============================================
  std::cout << "---PINOCCHIO VANILLA DEBUG---\n";

  Data data(model);
  computeJointJacobians(model, data, q);
  pin_vanilla_res = getJointJacobian(model, data, model.njoints-1, WORLD);

  // Reorder vanilla Pinocchio to match RLA convention [angular; linear]
  Eigen::MatrixXd pin_vanilla_reordered(6, model.nv);
  pin_vanilla_reordered.topRows(3) = pin_vanilla_res.bottomRows(3);     // angular
  pin_vanilla_reordered.bottomRows(3) = pin_vanilla_res.topRows(3);     // linear

  std::cout << pin_vanilla_reordered << "\n\n";

  // ============================================
  // 2. Pinocchio Codegen Jacobian
  // ============================================
  std::cout << "---PINOCCHIO CODEGEN DEBUG---\n";

  // Using symbolic scalar for source code gen
  using CGD = CG<double>;
  using ADCG = AD<CGD>;
  typedef ModelTpl<ADCG> ADModel;
  typedef DataTpl<ADCG> ADData;
  typedef Eigen::Matrix<ADCG, Eigen::Dynamic, 1> ADVectorXs;
  typedef Eigen::Matrix<ADCG, 6, Eigen::Dynamic> ADMatrixDyn6xN;

  // Make symbolic model
  ADModel ad_model = model.cast<ADCG>();
  ADData ad_data(ad_model);
  ADVectorXs ad_X = ADVectorXs(ad_model.nq);

  ADMatrixDyn6xN ad_J;
  ad_J.resize(6, model.nv);

  Independent(ad_X);

  computeJointJacobians(ad_model, ad_data, ad_X);
  ad_J = getJointJacobian(ad_model, ad_data, model.njoints-1, WORLD);

  // Flatten to output vector (col major storage)
  ADVectorXs ad_Y_flat(6 * model.nv);
  for (int jv = 0; jv < model.nv; jv++) {
    for (int i = 0; i < 6; i++) {
      ad_Y_flat[jv * 6 + i] = ad_J.coeffRef(i, jv);
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
  pin_codegen_res = Eigen::Map<const Eigen::MatrixXd>(y.data(), 6, model.nv);

  // Reorder Pinocchio codegen to match RLA convention [angular; linear]
  Eigen::MatrixXd pin_codegen_reordered(6, model.nv);
  pin_codegen_reordered.topRows(3) = pin_codegen_res.bottomRows(3);     // angular
  pin_codegen_reordered.bottomRows(3) = pin_codegen_res.topRows(3);     // linear

  std::cout << pin_codegen_reordered << "\n\n";

  // ============================================
  // 3. RLA Batched Jacobian
  // ============================================
  std::cout << "---RLA BATCHED DEBUG---\n";

  // Batched Jacobian output: BatchSize rows x (6 * nv) columns (flattened Jacobians)
  const size_t BATCH_SIZE = 8;
  Eigen::MatrixXd rla_res_batched = Eigen::MatrixXd::Zero(BATCH_SIZE, 6 * model.nv);

  // Dispatch to the appropriate robot batched Jacobian
  // Using float precision with batch size 8 (only supported combination currently)
  if (robot_name == "panda") {
    auto jac_batched_func = PandaTraits::jac_batched_float_8;
    rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Panda, float, BATCH_SIZE> q_batched;
    for (size_t d = 0; d < PandaTraits::ndim; ++d) {
      q_batched[d] = q[d];  // Blaze automatically broadcasts scalar to vector
    }
    jac_batched_func(q_batched, rla_res_batched);
  } else if (robot_name == "iiwa") {
    auto jac_batched_func = iiwaTraits::jac_batched_float_8;
    rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::iiwa, float, BATCH_SIZE> q_batched;
    for (size_t d = 0; d < iiwaTraits::ndim; ++d) {
      q_batched[d] = q[d];
    }
    jac_batched_func(q_batched, rla_res_batched);
  } else if (robot_name == "hyq") {
    auto jac_batched_func = hyqTraits::jac_batched_float_8;
    rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Hyq, float, BATCH_SIZE> q_batched;
    for (size_t d = 0; d < hyqTraits::ndim; ++d) {
      q_batched[d] = q[d];
    }
    jac_batched_func(q_batched, rla_res_batched);
  } else if (robot_name == "baxter") {
    auto jac_batched_func = baxterTraits::jac_batched_float_8;
    rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Baxter, float, BATCH_SIZE> q_batched;
    for (size_t d = 0; d < baxterTraits::ndim; ++d) {
      q_batched[d] = q[d];
    }
    jac_batched_func(q_batched, rla_res_batched);
  } else {
    throw std::runtime_error("Unknown robot: " + robot_name);
  }

  // Extract first batch of batched result and reshape to 6 x nv
  for (size_t r = 0; r < 6; ++r) {
    for (size_t c = 0; c < (size_t)model.nv; ++c) {
      rla_res(r, c) = rla_res_batched(0, r * model.nv + c);
    }
  }

  std::cout << rla_res << "\n\n";

  // ============================================
  // Comparison (only RLA vs vanilla)
  // ============================================
  std::cout << "---COMPARISON---\n\n";

  double error = (rla_res - pin_vanilla_reordered).norm();
  std::cout << "Error between RLA batched and Pinocchio vanilla: " << error << "\n";

  const double tolerance = 1e-5;
  if (error < tolerance) {
    std::cout << "SUCCESS: RLA batched and vanilla Pinocchio match within tolerance!\n";
    return 0;
  } else {
    std::cout << "WARNING: Large error between RLA batched and vanilla Pinocchio!\n";
    return 1;
  }
}
