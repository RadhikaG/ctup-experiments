#include <iostream>
#include <chrono>

#include "rla_grad_self_collision/runtime/utils.h"
#include "../gen/panda_spherized_sd.h"

int main() {
  constexpr int NBT = 100000;

  // Hardcode Panda configuration: all joints at pi/4
  constexpr size_t PANDA_NDOF = cg_sd_runtime::robots::Panda::ndim;
  constexpr float PI_OVER_4 = 0.785398163f;

  cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::Panda> q_batched;
  for (size_t i = 0; i < PANDA_NDOF; i++) {
    q_batched[i] = PI_OVER_4;
  }

  constexpr size_t SIMD_WIDTH = 8;
  constexpr size_t N_CP = 690;

  Eigen::MatrixXd signed_distances = Eigen::MatrixXd::Zero(SIMD_WIDTH, N_CP);

  std::cout << "Running " << NBT << " iterations...\n";

  // Benchmark the generated function
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < NBT; i++) {
    ctup_gen_panda::self_collision_signed_distances(q_batched, signed_distances);
  }
  auto end = std::chrono::high_resolution_clock::now();

  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
  double avg_time_ns = static_cast<double>(duration_ns) / NBT;

  std::cout << "Batched FK+CC (x" << SIMD_WIDTH << ") avg time (ns): " << avg_time_ns << "\n";
  std::cout << "Batched FK+CC (x" << SIMD_WIDTH << ") avg time (us): " << avg_time_ns / 1000.0 << "\n";

  // Check if any collisions detected
  bool has_collision = (signed_distances.row(0).array() < 0.0).any();
  std::cout << "Collision status: " << (has_collision ? "COLLISION" : "collision-free") << "\n";

  return 0;
}
