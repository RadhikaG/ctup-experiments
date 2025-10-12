#ifndef RLA_FK_RUNTIME_H
#define RLA_FK_RUNTIME_H

#include "blaze/Math.h"
#include "Eigen/Dense"
#include <iostream>
#include <cstddef>

namespace ctup_runtime {

static void print_string(const char* str) {
  std::cout << str << "\n";
}

template<typename Derived>
static void print_matrix(const Eigen::MatrixBase<Derived>& matrix) {
  std::cout << matrix << "\n";
}

// SIMD vector types for different batch sizes
template<typename Scalar, size_t BatchSize>
using SIMDVector = blaze::StaticVector<Scalar, BatchSize>;

// Legacy alias for backward compatibility
using avx512d = blaze::StaticVector<double, 8>;

namespace robots {
struct iiwa {
  static constexpr size_t ndof = 7;
};

struct hyq {
  static constexpr size_t ndof = 12;
};

struct baxter {
  static constexpr size_t ndof = 14;
};
}

// Generic configuration block parameterized by Robot, Scalar type, and batch size
template <typename Robot, typename Scalar = double, size_t BatchSize = 8>
using ConfigurationBlock = std::array<SIMDVector<Scalar, BatchSize>, Robot::ndof>;

// Legacy alias for backward compatibility (double, batch size 8)
template <typename Robot>
using ConfigurationBlockRobot = ConfigurationBlock<Robot, double, 8>;

}

#endif
