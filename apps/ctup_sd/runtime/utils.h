#ifndef CTUP_SD_COLLISION_H
#define CTUP_SD_COLLISION_H

#include "blaze/Math.h"
#include "Eigen/Dense"

namespace cg_sd_runtime {

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

template <typename Scalar>
static blaze::StaticMatrix<Scalar, 3, 3> hat(const blaze::StaticVector<Scalar, 3> &trans) {
  blaze::StaticMatrix<Scalar, 3, 3> skew_mat {
    {0, -trans(2), trans(1)},
    {trans(2), 0, -trans(0)},
    {-trans(1), trans(0), 0}};
  return skew_mat;
}

template <size_t NV>
static void compute_sph_sph_cp_sd_grad(
    const blaze::StaticMatrix<avx256f, 6, NV> &jac1,
    const blaze::StaticMatrix<avx256f, 6, NV> &jac2,
    const blaze::StaticVector<avx256f, 3> &sph_c1,
    const blaze::StaticVector<avx256f, 3> &sph_c2,
    float sph_radius1, float sph_radius2,
    avx256f &signed_distance,
    blaze::StaticVector<avx256f, NV> &sd_jac) {

  blaze::StaticVector<avx256f, 3> &delta = sph_c2 - sph_c1;

  avx256f &dist = blaze::sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);

  // signed distance
  signed_distance = dist - (sph_radius1 + sph_radius2);

  blaze::StaticVector<avx256f, 3> normal;
  normal[0] = delta[0] / dist;
  normal[1] = delta[1] / dist;
  normal[2] = delta[2] / dist;

  blaze::StaticVector<avx256f, 3> &witness_pt1 = sph_c1 + sph_radius1 * normal;
  blaze::StaticVector<avx256f, 3> &witness_pt2 = sph_c2 - sph_radius2 * normal;

  blaze::StaticMatrix<avx256f, 3, NV> &jac1_w = blaze::rows<0UL, 1UL, 2UL>(jac1);
  blaze::StaticMatrix<avx256f, 3, NV> &jac1_v = blaze::rows<3UL, 4UL, 5UL>(jac1);

  blaze::StaticMatrix<avx256f, 3, NV> &jac2_w = blaze::rows<0UL, 1UL, 2UL>(jac2);
  blaze::StaticMatrix<avx256f, 3, NV> &jac2_v = blaze::rows<3UL, 4UL, 5UL>(jac2);

  blaze::StaticMatrix<avx256f, 3, NV> &ptJac1 =
      jac1_v - hat(witness_pt1) * jac1_w;

  blaze::StaticMatrix<avx256f, 3, NV> &ptJac2 =
      jac2_v - hat(witness_pt2) * jac2_w;

  // gradient of signed distance
  //sd_jac = blaze::transpose(normal) * (ptJac1 - ptJac2);
  sd_jac = normal * (ptJac1 - ptJac2);
}

}

#endif
