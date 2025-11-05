#include "Eigen/Dense"
#include "blaze/Math.h"
#include <iostream>
#include <argparse/argparse.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <random>
#include <chrono>

// Include all generated headers
#include "rla_fk_batch_size_sweep/gen/f4/fk_gen_serial_12dof.h"
#include "rla_fk_batch_size_sweep/gen/f8/fk_gen_serial_12dof.h"
#include "rla_fk_batch_size_sweep/gen/f16/fk_gen_serial_12dof.h"
#include "rla_fk_batch_size_sweep/gen/f32/fk_gen_serial_12dof.h"

#include "rla_fk_batch_size_sweep/gen/f4/fk_gen_dual_6dof.h"
#include "rla_fk_batch_size_sweep/gen/f8/fk_gen_dual_6dof.h"
#include "rla_fk_batch_size_sweep/gen/f16/fk_gen_dual_6dof.h"
#include "rla_fk_batch_size_sweep/gen/f32/fk_gen_dual_6dof.h"

#include "rla_fk_batch_size_sweep/gen/f4/fk_gen_triple_4dof.h"
#include "rla_fk_batch_size_sweep/gen/f8/fk_gen_triple_4dof.h"
#include "rla_fk_batch_size_sweep/gen/f16/fk_gen_triple_4dof.h"
#include "rla_fk_batch_size_sweep/gen/f32/fk_gen_triple_4dof.h"

#include "rla_fk_batch_size_sweep/gen/f4/fk_gen_quad_3dof.h"
#include "rla_fk_batch_size_sweep/gen/f8/fk_gen_quad_3dof.h"
#include "rla_fk_batch_size_sweep/gen/f16/fk_gen_quad_3dof.h"
#include "rla_fk_batch_size_sweep/gen/f32/fk_gen_quad_3dof.h"

#include "rla_fk_batch_size_sweep/gen/f4/fk_gen_tree_2_5_5.h"
#include "rla_fk_batch_size_sweep/gen/f8/fk_gen_tree_2_5_5.h"
#include "rla_fk_batch_size_sweep/gen/f16/fk_gen_tree_2_5_5.h"
#include "rla_fk_batch_size_sweep/gen/f32/fk_gen_tree_2_5_5.h"

#include "rla_fk_batch_size_sweep/runtime/utils.h"

using namespace ctup_runtime;

// Template helper to run benchmark for a specific batch size
template<size_t BatchSize>
double benchmark_batch_size(const std::vector<std::vector<float>>& qs,
                             int n_iterations,
                             int ndof,
                             void (*fk_func)(const ConfigurationBlock<robots::synth_12, blaze::StaticVector<float, BatchSize>>&, Eigen::MatrixXd&)) {
  using Prim = blaze::StaticVector<float, BatchSize>;

  // Pre-allocate batched inputs and outputs (outside timing loop)
  std::vector<ConfigurationBlock<robots::synth_12, Prim>> q_batches;
  q_batches.reserve(n_iterations);

  // Pre-populate all batch configurations
  for (int i = 0; i < n_iterations; ++i) {
    ConfigurationBlock<robots::synth_12, Prim> q_batch;
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
  argparse::ArgumentParser program("eval_batch_size_sweep");

  program.add_argument("--robot")
      .required()
      .help("robot name (serial_12dof, dual_6dof, triple_4dof, quad_3dof, tree_2_5_5)");

  program.add_argument("--batch_size")
      .default_value(0)
      .scan<'i', int>()
      .help("batch size (4, 8, 16, 32). If not specified, runs all batch sizes");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  std::string robot = program.get<std::string>("--robot");
  int batch_size = program.get<int>("--batch_size");
  const int n_iterations = 1000000;

  // All synth_12 robots have 12 DOF
  const int ndof = 12;

  // Set all configurations to pi/3
  const float pi_over_3 = 3.14159265f / 3.0f;
  std::vector<std::vector<float>> qs(n_iterations * 32); // enough for all batch sizes
  for (int i = 0; i < n_iterations * 32; ++i) {
    qs[i].resize(ndof);
    for (int j = 0; j < ndof; ++j) {
      qs[i][j] = pi_over_3;
    }
  }

  // Dispatch to the correct robot and batch size
  if (robot == "serial_12dof") {
    if (batch_size == 0) {
      std::cout << robot;
      std::cout << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk);
      std::cout << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk);
      std::cout << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk);
      std::cout << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk);
      std::cout << "\n";
    } else if (batch_size == 4) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk) << "\n";
    } else if (batch_size == 8) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk) << "\n";
    } else if (batch_size == 16) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk) << "\n";
    } else if (batch_size == 32) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_serial_12dof::batched_fk) << "\n";
    } else {
      std::cerr << "Invalid batch size: " << batch_size << ". Must be 4, 8, 16, or 32\n";
      return 1;
    }
    return 0;
  }

  if (robot == "dual_6dof") {
    if (batch_size == 0) {
      std::cout << robot;
      std::cout << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk);
      std::cout << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk);
      std::cout << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk);
      std::cout << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk);
      std::cout << "\n";
    } else if (batch_size == 4) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk) << "\n";
    } else if (batch_size == 8) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk) << "\n";
    } else if (batch_size == 16) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk) << "\n";
    } else if (batch_size == 32) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_dual_6dof::batched_fk) << "\n";
    } else {
      std::cerr << "Invalid batch size: " << batch_size << ". Must be 4, 8, 16, or 32\n";
      return 1;
    }
    return 0;
  }

  if (robot == "triple_4dof") {
    if (batch_size == 0) {
      std::cout << robot;
      std::cout << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk);
      std::cout << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk);
      std::cout << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk);
      std::cout << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk);
      std::cout << "\n";
    } else if (batch_size == 4) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk) << "\n";
    } else if (batch_size == 8) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk) << "\n";
    } else if (batch_size == 16) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk) << "\n";
    } else if (batch_size == 32) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_triple_4dof::batched_fk) << "\n";
    } else {
      std::cerr << "Invalid batch size: " << batch_size << ". Must be 4, 8, 16, or 32\n";
      return 1;
    }
    return 0;
  }

  if (robot == "quad_3dof") {
    if (batch_size == 0) {
      std::cout << robot;
      std::cout << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk);
      std::cout << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk);
      std::cout << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk);
      std::cout << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk);
      std::cout << "\n";
    } else if (batch_size == 4) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk) << "\n";
    } else if (batch_size == 8) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk) << "\n";
    } else if (batch_size == 16) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk) << "\n";
    } else if (batch_size == 32) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_quad_3dof::batched_fk) << "\n";
    } else {
      std::cerr << "Invalid batch size: " << batch_size << ". Must be 4, 8, 16, or 32\n";
      return 1;
    }
    return 0;
  }

  if (robot == "tree_2_5_5") {
    if (batch_size == 0) {
      std::cout << robot;
      std::cout << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk);
      std::cout << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk);
      std::cout << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk);
      std::cout << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk);
      std::cout << "\n";
    } else if (batch_size == 4) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<4>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk) << "\n";
    } else if (batch_size == 8) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<8>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk) << "\n";
    } else if (batch_size == 16) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<16>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk) << "\n";
    } else if (batch_size == 32) {
      std::cout << robot << "," << batch_size << "," << benchmark_batch_size<32>(qs, n_iterations, ndof, ctup_gen_tree_2_5_5::batched_fk) << "\n";
    } else {
      std::cerr << "Invalid batch size: " << batch_size << ". Must be 4, 8, 16, or 32\n";
      return 1;
    }
    return 0;
  }

  std::cerr << "Unknown robot: " << robot << "\n";
  return 1;
}
