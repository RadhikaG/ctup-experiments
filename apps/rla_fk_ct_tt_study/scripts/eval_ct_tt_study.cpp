#include "Eigen/Dense"
#include "blaze/Math.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <chrono>

// Include all generated headers
#include "rla_fk_ct_tt_study/gen/fk_gen_iiwa.h"
#include "rla_fk_ct_tt_study/gen/fk_gen_hyq.h"
#include "rla_fk_ct_tt_study/gen/fk_gen_baxter.h"

#include "rla_fk_ct_tt_study/runtime/utils.h"

using namespace ctup_runtime;

// Batch size is fixed at 8 for AVX256
constexpr size_t BatchSize = 8;
using Prim = blaze::StaticVector<float, BatchSize>;

// Template helper to run benchmark
template<typename Robot>
double benchmark_fk(const std::vector<std::vector<float>>& qs,
                    int n_iterations,
                    int ndof,
                    void (*fk_func)(const ConfigurationBlock<Robot, Prim>&, Eigen::MatrixXd&)) {
  // Pre-allocate batched inputs and outputs (outside timing loop)
  std::vector<ConfigurationBlock<Robot, Prim>> q_batches;
  q_batches.reserve(n_iterations);

  // Pre-populate all batch configurations
  for (int i = 0; i < n_iterations; ++i) {
    ConfigurationBlock<Robot, Prim> q_batch;
    for (int dof_idx = 0; dof_idx < ndof; ++dof_idx) {
      for (size_t b = 0; b < BatchSize; ++b) {
        int config_idx = (i * BatchSize + b) % qs.size();
        q_batch[dof_idx][b] = qs[config_idx][dof_idx];
      }
    }
    q_batches.push_back(q_batch);
  }

  Eigen::MatrixXd result(BatchSize, 36);

  // Time only the FK function calls
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < n_iterations; ++i) {
    fk_func(q_batches[i], result);
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  return static_cast<double>(elapsed_ns) / n_iterations; // avg time per call in ns
}

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_ct_tt_study");

  program.add_argument("--robot")
      .required()
      .help("robot name (iiwa, hyq, baxter)");

  program.add_argument("--variant")
      .help("variant (ct, tt, no_ct_no_tt). If not specified, runs all variants");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  std::string robot = program.get<std::string>("--robot");
  std::string variant = program.present("--variant") ? program.get<std::string>("--variant") : "all";

  const int n_iterations = 1000000;

  // Determine ndof based on robot
  int ndof;
  if (robot == "iiwa") {
    ndof = 7;
  } else if (robot == "hyq") {
    ndof = 12;
  } else if (robot == "baxter") {
    ndof = 19;
  } else {
    std::cerr << "Unknown robot: " << robot << "\n";
    return 1;
  }

  // Set all configurations to pi/3
  const float pi_over_3 = 3.14159265f / 3.0f;
  const size_t total_configs = static_cast<size_t>(n_iterations) * BatchSize;
  std::vector<std::vector<float>> qs(total_configs);
  for (size_t i = 0; i < total_configs; ++i) {
    qs[i].resize(ndof);
    for (int j = 0; j < ndof; ++j) {
      qs[i][j] = pi_over_3;
    }
  }

  // Dispatch to the correct robot and variant
  if (robot == "iiwa") {
    if (variant == "all") {
      std::cout << robot;
      std::cout << "," << benchmark_fk<robots::iiwa>(qs, n_iterations, ndof, ctup_gen_iiwa::batched_fk_ct);
      std::cout << "," << benchmark_fk<robots::iiwa>(qs, n_iterations, ndof, ctup_gen_iiwa::batched_fk_tt);
      std::cout << "," << benchmark_fk<robots::iiwa>(qs, n_iterations, ndof, ctup_gen_iiwa::batched_fk_no_ct_no_tt);
      std::cout << "\n";
    } else if (variant == "ct") {
      std::cout << robot << ",ct," << benchmark_fk<robots::iiwa>(qs, n_iterations, ndof, ctup_gen_iiwa::batched_fk_ct) << "\n";
    } else if (variant == "tt") {
      std::cout << robot << ",tt," << benchmark_fk<robots::iiwa>(qs, n_iterations, ndof, ctup_gen_iiwa::batched_fk_tt) << "\n";
    } else if (variant == "no_ct_no_tt") {
      std::cout << robot << ",no_ct_no_tt," << benchmark_fk<robots::iiwa>(qs, n_iterations, ndof, ctup_gen_iiwa::batched_fk_no_ct_no_tt) << "\n";
    } else {
      std::cerr << "Unknown variant: " << variant << "\n";
      return 1;
    }
    return 0;
  }

  if (robot == "hyq") {
    if (variant == "all") {
      std::cout << robot;
      std::cout << "," << benchmark_fk<robots::hyq>(qs, n_iterations, ndof, ctup_gen_hyq::batched_fk_ct);
      std::cout << "," << benchmark_fk<robots::hyq>(qs, n_iterations, ndof, ctup_gen_hyq::batched_fk_tt);
      std::cout << "," << benchmark_fk<robots::hyq>(qs, n_iterations, ndof, ctup_gen_hyq::batched_fk_no_ct_no_tt);
      std::cout << "\n";
    } else if (variant == "ct") {
      std::cout << robot << ",ct," << benchmark_fk<robots::hyq>(qs, n_iterations, ndof, ctup_gen_hyq::batched_fk_ct) << "\n";
    } else if (variant == "tt") {
      std::cout << robot << ",tt," << benchmark_fk<robots::hyq>(qs, n_iterations, ndof, ctup_gen_hyq::batched_fk_tt) << "\n";
    } else if (variant == "no_ct_no_tt") {
      std::cout << robot << ",no_ct_no_tt," << benchmark_fk<robots::hyq>(qs, n_iterations, ndof, ctup_gen_hyq::batched_fk_no_ct_no_tt) << "\n";
    } else {
      std::cerr << "Unknown variant: " << variant << "\n";
      return 1;
    }
    return 0;
  }

  if (robot == "baxter") {
    if (variant == "all") {
      std::cout << robot;
      std::cout << "," << benchmark_fk<robots::baxter>(qs, n_iterations, ndof, ctup_gen_baxter::batched_fk_ct);
      std::cout << "," << benchmark_fk<robots::baxter>(qs, n_iterations, ndof, ctup_gen_baxter::batched_fk_tt);
      std::cout << "," << benchmark_fk<robots::baxter>(qs, n_iterations, ndof, ctup_gen_baxter::batched_fk_no_ct_no_tt);
      std::cout << "\n";
    } else if (variant == "ct") {
      std::cout << robot << ",ct," << benchmark_fk<robots::baxter>(qs, n_iterations, ndof, ctup_gen_baxter::batched_fk_ct) << "\n";
    } else if (variant == "tt") {
      std::cout << robot << ",tt," << benchmark_fk<robots::baxter>(qs, n_iterations, ndof, ctup_gen_baxter::batched_fk_tt) << "\n";
    } else if (variant == "no_ct_no_tt") {
      std::cout << robot << ",no_ct_no_tt," << benchmark_fk<robots::baxter>(qs, n_iterations, ndof, ctup_gen_baxter::batched_fk_no_ct_no_tt) << "\n";
    } else {
      std::cerr << "Unknown variant: " << variant << "\n";
      return 1;
    }
    return 0;
  }

  std::cerr << "Unknown robot: " << robot << "\n";
  return 1;
}
