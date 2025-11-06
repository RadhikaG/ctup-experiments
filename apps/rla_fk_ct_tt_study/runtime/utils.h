#ifndef RLA_FK_CT_TT_STUDY_RUNTIME_H
#define RLA_FK_CT_TT_STUDY_RUNTIME_H

#include "blaze/Math.h"
#include "Eigen/Dense"
#include <iostream>
#include <cstddef>

namespace ctup_runtime {

namespace robots {
struct iiwa {
  static constexpr size_t ndof = 7;
};

struct hyq {
  static constexpr size_t ndof = 12;
};

struct baxter {
  static constexpr size_t ndof = 19;
};
}

// Prim is blaze::StaticVector<float, 8> (AVX256 batch size)
template <typename Robot, typename Prim>
using ConfigurationBlock = std::array<Prim, Robot::ndof>;

using EigenMatrixXd = Eigen::MatrixXd;

template <typename Scalar, size_t BatchSize>
static void map_blaze_avxtype_to_eigen_batch_dim(
    size_t flattened_idx,
    const blaze::StaticVector<Scalar, BatchSize> &blaze_sv,
    Eigen::MatrixXd &eigen_matrix) {
  for (size_t i = 0; i < BatchSize; i++) {
    eigen_matrix(i, flattened_idx) = blaze_sv[i];
  }
}

// Dummy functions required by generated code (not actually called)
inline void print_string(const char* str) {
  std::cout << str << std::endl;
}

inline void print_matrix(const Eigen::MatrixXd& mat) {
  std::cout << mat << std::endl;
}

}

#endif
