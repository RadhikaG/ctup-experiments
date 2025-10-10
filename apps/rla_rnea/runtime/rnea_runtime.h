#pragma once

#include "Eigen/Dense"
#include <iostream>

namespace rla_rnea_runtime {

static void print_string(const char* str) {
  std::cout << str << "\n";
}

template<typename Derived>
static void print_matrix(const Eigen::MatrixBase<Derived>& matrix) {
  std::cout << matrix << "\n";
}

} // namespace rla_rnea_runtime
