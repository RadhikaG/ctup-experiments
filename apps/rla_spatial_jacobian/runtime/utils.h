#ifndef RLA_SPATIAL_JACOBIAN_H
#define RLA_SPATIAL_JACOBIAN_H

#include "blaze/Math.h"
#include "Eigen/Dense"
#include <iostream>

namespace rla_jac_runtime {

// Debug print functions (used by generated code)
template<typename MT>
static void print_matrix(const blaze::DenseMatrix<MT, blaze::rowMajor>& matrix) {
  std::cout << matrix << "\n";
}

template<typename Derived>
static void print_matrix(const Eigen::MatrixBase<Derived>& matrix) {
  std::cout << matrix << "\n";
}

static void print_string(const char* str) {
  std::cout << str << "\n";
}

// SIMD vector types for different scalar types and batch sizes
template<typename Scalar, size_t BatchSize>
using SIMDVector = blaze::StaticVector<Scalar, BatchSize>;

// Legacy aliases for backward compatibility (float types)
using avx256f = blaze::StaticVector<float, 8>;
using avx512f = blaze::StaticVector<float, 16>;

// Double precision SIMD types
using avx256d = blaze::StaticVector<double, 4>;
using avx512d = blaze::StaticVector<double, 8>;

namespace robots {

struct Panda {
  static constexpr size_t ndim = 7;
};

struct iiwa {
  static constexpr size_t ndim = 7;
};

struct Hyq {
  static constexpr size_t ndim = 12;
};

struct Baxter {
  static constexpr size_t ndim = 19;
};

}

// Generic configuration block parameterized by Robot, Scalar type, and batch size
template <typename Robot, typename Scalar = float, size_t BatchSize = 8>
using ConfigurationBlock = std::array<SIMDVector<Scalar, BatchSize>, Robot::ndim>;

// Legacy alias for backward compatibility (float, batch size 8)
template <typename Robot>
using ConfigurationBlockRobot = ConfigurationBlock<Robot, float, 8>;

template <size_t ndim>
using ConfigurationBlockDim = std::array<avx256f, ndim>;

// Generic mapping function for different batch sizes with type conversion support
template <typename BlazeScalar, typename EigenScalar, size_t BatchSize>
static void map_blaze_avxtype_to_eigen_batch_dim(
    size_t flattened_idx,
    const blaze::StaticVector<BlazeScalar, BatchSize> &blaze_sv,
    Eigen::Matrix<EigenScalar, Eigen::Dynamic, Eigen::Dynamic> &eigen_matrix) {
  for (size_t i = 0; i < BatchSize; i++) {
    eigen_matrix(i, flattened_idx) = static_cast<EigenScalar>(blaze_sv[i]);
  }
}

// Legacy version for backward compatibility (hardcoded batch size 8)
template <typename Scalar>
static void map_blaze_avxtype_to_eigen_batch_dim_legacy(
    size_t flattened_idx,
    const blaze::StaticVector<Scalar, 8> &blaze_sv,
    Eigen::Matrix<Scalar, 8, -1> &eigen_matrix) {
  for (size_t i = 0; i < 8; i++) {
    eigen_matrix(i, flattened_idx) = blaze_sv[i];
  }
}

}

#endif
