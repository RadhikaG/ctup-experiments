#ifndef CTUP_FKCC_TYPEDEFS_H
#define CTUP_FKCC_TYPEDEFS_H

#include "ctup/typedefs.h"
#include <type_traits>
#include <array>
#include "blaze/Math.h"
#include <immintrin.h>

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

// todo: remove intrinsics and make backend agnostic
static inline bool is_any_negative(const blaze::StaticVector<float, 8UL>& v) {
  __m256 vec = _mm256_loadu_ps(v.data());         // Load 8 floats
  int mask = _mm256_movemask_ps(vec);             // Extract sign bits from all 8 lanes
  return mask != 0;                               // Any negative if any sign bit set
}

//static inline bool is_any_negative(const blaze::StaticVector<float, 8UL>& v) {
//  return blaze::min(v) <= 0;
//}

}

#endif
