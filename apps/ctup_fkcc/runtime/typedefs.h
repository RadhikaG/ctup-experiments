#ifndef CTUP_FKCC_TYPEDEFS_H
#define CTUP_FKCC_TYPEDEFS_H

#include "ctup/typedefs.h"
#include <type_traits>
#include <array>
#include "blaze/Math.h"

namespace ctup_runtime {

namespace robots {

struct Sphere {
  static constexpr size_t ndim = 3;
};

struct UR5 {
  static constexpr size_t ndim = 6;
};

struct Panda {
  static constexpr size_t ndim = 7;
};

struct Baxter {
  static constexpr size_t ndim = 14;
};

struct Fetch {
  static constexpr size_t ndim = 8;
};

}

template <typename Robot>
using ConfigurationBlockRobot = std::array<avx256f, Robot::ndim>;

template <size_t ndim>
using ConfigurationBlockDim = std::array<avx256f, ndim>;

}

#endif
