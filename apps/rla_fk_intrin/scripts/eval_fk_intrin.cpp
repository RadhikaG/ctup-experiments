#include "Eigen/Dense"
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "pinocchio/codegen/cppadcg.hpp"
#include "cppad/cg.hpp"
#include "pinocchio/utils/timer.hpp"
#include "rla_fk_intrin/rla_fk_intrin_dispatcher/fk_dispatcher.h"
#include <cppad/cg/model/llvm/llvm.hpp>
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_fk_intrin");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("--robot")
      .required()
      .help("robot name")
      .choices("iiwa");

  program.add_argument("--rla-only")
      .help("only run RLA FK benchmarks, skip Pinocchio codegen")
      .default_value(false)
      .implicit_value(true);

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
  const bool rla_only = program.get<bool>("--rla-only");

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";
  std::cout << "RLA only mode: " << (rla_only ? "true" : "false") << "\n\n";

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  PinocchioTicToc timer(PinocchioTicToc::NS);
  const int N_IT = 10000;
  const size_t BATCH_SIZE = 8;

  // Sample random configurations
  PINOCCHIO_ALIGNED_STD_VECTOR(Eigen::VectorXd) qs(N_IT);
  for (size_t i = 0; i < N_IT; ++i) {
    qs[i] = randomConfiguration(model);
  }

  // Pre-generate batched inputs for RLA (outside timing loop)
  // Only batch 0 is populated with actual values, batches 1-7 are zeros
  std::vector<std::vector<float>> qs_batched(N_IT);
  for (size_t i = 0; i < N_IT; ++i) {
    qs_batched[i].resize(7 * BATCH_SIZE, 0.0f);  // Initialize all to zero
    for (size_t joint = 0; joint < 7; ++joint) {
      qs_batched[i][joint * BATCH_SIZE + 0] = static_cast<float>(qs[i][joint]);  // Only batch 0
    }
  }

  // Result matrices
  EigenSpatialXform rla_intrin_res;
  EigenSpatialXform pin_codegen_res;

  // Pinocchio codegen setup (only if not in rla-only mode)
  std::unique_ptr<GenericModel<double>> g_model;
  std::unique_ptr<LlvmModelLibrary<double>> llvmModelLib;  // Keep library alive

  if (!rla_only) {
    std::cout << "Initializing Pinocchio JIT codegen...\n";

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
    llvmModelLib = p.create();  // Store library to keep it alive

    g_model = llvmModelLib->model("model");
  }

  std::cout << "\n=== Running Performance Evaluation ===\n\n";

  // Get RLA FK function
  auto rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<iiwaTraits>();

  // ============================================
  // Benchmark RLA Intrinsic FK (single batched call)
  // ============================================
  std::cout << "Benchmarking RLA batched FK (batch size " << BATCH_SIZE << ")...\n";

  Eigen::MatrixXd rla_result = Eigen::MatrixXd::Zero(BATCH_SIZE, 36);

  // Warmup call to verify FK works correctly before benchmarking
  rla_fk_func(qs_batched[0].data(), rla_result);

  timer.tic();
  SMOOTH(N_IT)
  {
    rla_fk_func(qs_batched[_smooth].data(), rla_result);
  }
  std::cout << "RLA batched FK (single call) avg time (ns):             \t";
  timer.toc(std::cout, N_IT);

  // Extract first batch for final result comparison
  Eigen::VectorXd batch0_flat = rla_result.row(0);
  rla_intrin_res = Eigen::Map<const Eigen::MatrixXd>(batch0_flat.data(), 6, 6);

  // ============================================
  // Benchmark Pinocchio Codegen FK (8 consecutive calls)
  // ============================================
  if (!rla_only) {
    std::cout << "Benchmarking Pinocchio codegen FK (" << BATCH_SIZE << " consecutive calls)...\n";

    Eigen::VectorXd y;

    timer.tic();
    SMOOTH(N_IT)
    {
      for (size_t w = 0; w < BATCH_SIZE; w++) {
        y = g_model->ForwardZero(qs[_smooth]);
      }
    }
    std::cout << "Pinocchio codegen (" << BATCH_SIZE << " consecutive calls) avg time (ns): \t";
    timer.toc(std::cout, N_IT);

    // Extract final result for comparison
    pin_codegen_res = Eigen::Map<const Eigen::MatrixXd>(y.data(), 6, 6);

    // ============================================
    // Comparison
    // ============================================
    std::cout << "\n=== Final Results (Last Configuration) ===\n\n";
    std::cout << "RLA batched FK result (first batch):\n" << rla_intrin_res << "\n\n";
    std::cout << "Pinocchio JIT codegen result:\n" << pin_codegen_res << "\n\n";

    double error = (rla_intrin_res - pin_codegen_res).norm();
    std::cout << "Error between RLA and Pinocchio codegen: " << error << "\n";

    const double tolerance = 1e-4;
    if (error < tolerance) {
      std::cout << "SUCCESS: Results match within tolerance!\n";
    } else {
      std::cout << "WARNING: Large error between results!\n";
    }
  } else {
    std::cout << "\n=== Final Result (RLA only mode) ===\n\n";
    std::cout << "RLA batched FK result (first batch):\n" << rla_intrin_res << "\n\n";
  }

  return 0;
}
