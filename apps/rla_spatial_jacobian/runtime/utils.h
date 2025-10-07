#ifndef RLA_SPATIAL_JACOBIAN_H
#define RLA_SPATIAL_JACOBIAN_H

#include "blaze/Math.h"
#include "Eigen/Dense"

namespace rla_jac_runtime {

using avx256f = blaze::StaticVector<float, 8>;
using avx512f = blaze::StaticVector<float, 16>;

namespace robots {
struct Panda {
  static constexpr size_t ndim = 7;
};
}

template <typename Robot>
using ConfigurationBlockRobot = std::array<avx256f, Robot::ndim>;

template <size_t ndim>
using ConfigurationBlockDim = std::array<avx256f, ndim>;

template <typename Scalar>
static void map_blaze_avxtype_to_eigen_batch_dim(
    size_t flattened_idx,
    const blaze::StaticVector<Scalar, 8> &blaze_sv, 
    Eigen::Matrix<Scalar, 8, -1> &eigen_matrix) {
  for (size_t i = 0; i < 8; i++) {
    eigen_matrix(i, flattened_idx) = blaze_sv[i];
  }
}

}

#endif
