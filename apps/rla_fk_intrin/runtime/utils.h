#pragma once

#include <Eigen/Dense>
#include <vamp/vector.hh>

namespace ctup_runtime {

// Robot definitions with DOF information
namespace robots {

struct Baxter {
    static constexpr int ndof = 14;
};

struct HyQ {
    static constexpr int ndof = 12;
};

struct iiwa {
    static constexpr int ndof = 7;
};

struct Panda {
    static constexpr int ndof = 7;
};

} // namespace robots

// Type alias for VAMP float vectors
// FloatVector<BatchSize, DOF> represents batched configurations
template<size_t BatchSize, size_t DOF>
using ConfigurationBlock = vamp::FloatVector<BatchSize, DOF>;

// Map VAMP SIMD vector to Eigen matrix batch dimension
// The VAMP vector contains one scalar value per batch (8 batches total)
// We write each batch's scalar to its corresponding row in the output matrix
// eigen_matrix layout: (batch_size=8, flattened_output_size=36)
// vamp_vec contains: [batch0_scalar, batch1_scalar, ..., batch7_scalar]
static void map_vamp_vector_to_eigen_batch_dim(
    size_t flattened_idx,
    const vamp::FloatVector<8, 1>& vamp_vec,
    Eigen::MatrixXd& eigen_matrix) {
  const auto arr = vamp_vec.to_array();
  // Each element in arr corresponds to one batch
  // Write each batch's scalar value to the corresponding row
  for (size_t batch_idx = 0; batch_idx < 8; batch_idx++) {
    eigen_matrix(batch_idx, flattened_idx) = arr[batch_idx];
  }
}

} // namespace ctup_runtime
