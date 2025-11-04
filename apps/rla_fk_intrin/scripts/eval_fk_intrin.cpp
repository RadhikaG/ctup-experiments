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
      .choices("iiwa", "synth_12");

  program.add_argument("--rla-only")
      .help("only run RLA FK benchmarks, skip Pinocchio")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--pin-vanilla-only")
      .help("only run vanilla Pinocchio FK benchmarks")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--pin-cg-only")
      .help("only run Pinocchio codegen FK benchmarks")
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
  const bool pin_vanilla_only = program.get<bool>("--pin-vanilla-only");
  const bool pin_cg_only = program.get<bool>("--pin-cg-only");

  // Validate flags
  int exclusive_count = rla_only + pin_vanilla_only + pin_cg_only;
  if (exclusive_count > 1) {
    std::cerr << "Error: Only one of --rla-only, --pin-vanilla-only, or --pin-cg-only can be specified\n";
    return 1;
  }

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";
  if (rla_only) std::cout << "Mode: RLA only\n\n";
  else if (pin_vanilla_only) std::cout << "Mode: Vanilla Pinocchio only\n\n";
  else if (pin_cg_only) std::cout << "Mode: Pinocchio codegen only\n\n";
  else std::cout << "Mode: All benchmarks\n\n";

  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  std::cout << "model name: " << model.name << std::endl;

  // Determine ndof and FK function based on robot name
  size_t ndof;
  std::function<void(const float*, Eigen::MatrixXd&)> rla_fk_func;

  if (robot_name == "iiwa") {
    ndof = 7;
    rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<iiwaTraits>();
  } else if (robot_name == "synth_12") {
    ndof = 12;

    // Extract URDF base filename to determine which synth_12 robot
    size_t last_slash = urdf_filename.find_last_of("/\\");
    size_t last_dot = urdf_filename.find_last_of(".");
    std::string base_filename = urdf_filename.substr(last_slash + 1, last_dot - last_slash - 1);

    std::cout << "Detected synth_12 robot: " << base_filename << "\n\n";

    if (base_filename == "serial_12dof") {
      rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<Serial12dofTraits>();
    } else if (base_filename == "dual_6dof") {
      rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<Dual6dofTraits>();
    } else if (base_filename == "triple_4dof") {
      rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<Triple4dofTraits>();
    } else if (base_filename == "quad_3dof") {
      rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<Quad3dofTraits>();
    } else if (base_filename == "tree_2_5_5") {
      rla_fk_func = FkIntrinDispatcher::get_fk_intrin_function<Tree255Traits>();
    } else {
      std::cerr << "Unknown synth_12 robot: " << base_filename << "\n";
      return 1;
    }
  } else {
    std::cerr << "Unknown robot: " << robot_name << "\n";
    return 1;
  }

  PinocchioTicToc timer(PinocchioTicToc::NS);
  const int N_IT = 100000;
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
    qs_batched[i].resize(ndof * BATCH_SIZE, 0.0f);  // Initialize all to zero
    for (size_t joint = 0; joint < ndof; ++joint) {
      qs_batched[i][joint * BATCH_SIZE + 0] = static_cast<float>(qs[i][joint]);  // Only batch 0
    }
  }

  // Result matrices
  EigenSpatialXform rla_intrin_res;
  EigenSpatialXform pin_vanilla_res;
  EigenSpatialXform pin_codegen_res;

  // Pinocchio vanilla data (for all modes except rla-only and pin-cg-only)
  std::unique_ptr<Data> pin_data;
  if (!rla_only && !pin_cg_only) {
    pin_data = std::make_unique<Data>(model);
  }

  // Pinocchio codegen setup (only if not in rla-only or pin-vanilla-only mode)
  std::unique_ptr<GenericModel<double>> g_model;
  std::unique_ptr<LlvmModelLibrary<double>> llvmModelLib;  // Keep library alive

  if (!rla_only && !pin_vanilla_only) {
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

  // ============================================
  // Benchmark Vanilla Pinocchio FK (8 consecutive calls)
  // ============================================
  if (!rla_only && !pin_cg_only) {
    std::cout << "Benchmarking vanilla Pinocchio FK (" << BATCH_SIZE << " consecutive calls)...\n";

    timer.tic();
    SMOOTH(N_IT)
    {
      for (size_t w = 0; w < BATCH_SIZE; w++) {
        forwardKinematics(model, *pin_data, qs[_smooth]);
      }
    }
    std::cout << "Vanilla Pinocchio (" << BATCH_SIZE << " consecutive calls) avg time (ns): \t";
    timer.toc(std::cout, N_IT);

    // Extract final result for comparison
    pin_vanilla_res = pin_data->oMi[model.njoints-1];
  }

  // ============================================
  // Benchmark RLA Intrinsic FK (single batched call)
  // ============================================
  if (!pin_vanilla_only && !pin_cg_only) {
    std::cout << "Benchmarking RLA batched FK (batch size " << BATCH_SIZE << ")...\n";

    Eigen::MatrixXd rla_result(BATCH_SIZE, 36);

    timer.tic();
    SMOOTH(N_IT)
    {
      rla_fk_func(qs_batched[_smooth].data(), rla_result);
    }
    std::cout << "RLA batched FK (single call) avg time (ns):                             \t";
    timer.toc(std::cout, N_IT);

    // Extract first batch for final result comparison
    Eigen::VectorXd batch0_flat = rla_result.row(0);
    rla_intrin_res = Eigen::Map<const Eigen::MatrixXd>(batch0_flat.data(), 6, 6);
  }

  // ============================================
  // Benchmark Pinocchio Codegen FK (8 consecutive calls)
  // ============================================
  if (!rla_only && !pin_vanilla_only) {
    std::cout << "Benchmarking Pinocchio codegen FK (" << BATCH_SIZE << " consecutive calls)...\n";

    Eigen::VectorXd y;

    timer.tic();
    SMOOTH(N_IT)
    {
      for (size_t w = 0; w < BATCH_SIZE; w++) {
        y = g_model->ForwardZero(qs[_smooth]);
      }
    }
    std::cout << "Pinocchio codegen (" << BATCH_SIZE << " consecutive calls) avg time (ns):  \t";
    timer.toc(std::cout, N_IT);

    // Extract final result for comparison
    pin_codegen_res = Eigen::Map<const Eigen::MatrixXd>(y.data(), 6, 6);
  }

  // ============================================
  // Comparison (only for all benchmarks mode)
  // ============================================
  if (!rla_only && !pin_vanilla_only && !pin_cg_only) {
    std::cout << "\n=== Final Results (Last Configuration) ===\n\n";
    std::cout << "RLA batched FK result (first batch):\n" << rla_intrin_res << "\n\n";
    std::cout << "Pinocchio codegen result:\n" << pin_codegen_res << "\n\n";

    double error = (rla_intrin_res - pin_codegen_res).norm();
    std::cout << "Error between RLA and Pinocchio codegen: " << error << "\n";

    const double tolerance = 1e-4;
    if (error < tolerance) {
      std::cout << "SUCCESS: Results match within tolerance!\n";
    } else {
      std::cout << "WARNING: Large error between results!\n";
    }
  }

  return 0;
}
