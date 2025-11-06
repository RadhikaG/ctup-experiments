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

struct UR5 {
  static constexpr size_t ndim = 6;
};

struct iiwa {
  static constexpr size_t ndim = 7;
};

struct Hyq {
  static constexpr size_t ndim = 12;
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
  blaze::StaticMatrix<Scalar, 3, 3> skew_mat; 
  skew_mat(0, 1) = -trans[2];
  skew_mat(1, 0) =  trans[2];
  skew_mat(0, 2) =  trans[1];
  skew_mat(2, 0) = -trans[1];
  skew_mat(1, 2) = -trans[0];
  skew_mat(2, 1) =  trans[0];
  skew_mat(0, 0) = 0;
  skew_mat(1, 1) = 0;
  skew_mat(2, 2) = 0;
  return skew_mat;
}

static void compute_sph_sph_cp_sd(
    size_t cp_it,
    const avx256f &sph_x1, const avx256f &sph_y1, const avx256f &sph_z1,
    float sph_radius1,
    const avx256f &sph_x2, const avx256f &sph_y2, const avx256f &sph_z2,
    float sph_radius2,
    // these are modified in-place
    Eigen::MatrixXd &signed_distances) // shape: (batch_dim, n_collision_pairs)
{

  blaze::StaticVector<avx256f, 3> delta;
  delta[0] = sph_x1 - sph_x2;
  delta[1] = sph_y1 - sph_y2;
  delta[2] = sph_z1 - sph_z2;

  avx256f dist = blaze::sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);

  // signed distance
  avx256f signed_distance = dist - (sph_radius1 + sph_radius2);

  // signed_distances need to be populated in
  // a particular order for batched outputs
  // signed_distances is of shape: (batch_dim, n_collision_pairs)

  const size_t SIMD_WIDTH = 8;
  // todo: find a more efficient way to do this
  for (size_t i = 0; i < SIMD_WIDTH; i++) {
    signed_distances(i, cp_it) = (double)signed_distance[i];
  }
}

template <size_t NV>
static void compute_sph_sph_cp_sd_grad(
    size_t cp_it,
    const blaze::StaticMatrix<avx256f, 6, NV> &jac1,
    const blaze::StaticMatrix<avx256f, 6, NV> &jac2,
    const avx256f &sph_x1, const avx256f &sph_y1, const avx256f &sph_z1,
    float sph_radius1,
    const avx256f &sph_x2, const avx256f &sph_y2, const avx256f &sph_z2,
    float sph_radius2,
    // these are modified in-place
    Eigen::MatrixXd &signed_distances, // shape: (batch_dim, n_collision_pairs)
    Eigen::MatrixXd &constraint_jacobian) // shape: (batch_dim * n_collision_pairs, NV)
{

  blaze::StaticVector<avx256f, 3> delta;
  delta[0] = sph_x1 - sph_x2;
  delta[1] = sph_y1 - sph_y2;
  delta[2] = sph_z1 - sph_z2;

  avx256f dist = blaze::sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);

  // signed distance
  avx256f signed_distance = dist - (sph_radius1 + sph_radius2);

  // normal would ordinarily be a column vector, but since we're
  // assigning elements individually anyway and we need to transpose it later
  // we treat it as a row vector
  blaze::StaticMatrix<avx256f, 1, 3> normal;
  normal(0, 0) = delta[0] / dist;
  normal(0, 1) = delta[1] / dist;
  normal(0, 2) = delta[2] / dist;

  blaze::StaticVector<avx256f, 3> witness_pt1;
  witness_pt1[0] = sph_x1 + sph_radius1 * normal(0, 0);
  witness_pt1[1] = sph_y1 + sph_radius1 * normal(0, 1);
  witness_pt1[2] = sph_z1 + sph_radius1 * normal(0, 2);

  blaze::StaticVector<avx256f, 3> witness_pt2;
  witness_pt2[0] = sph_x2 + sph_radius2 * normal(0, 0);
  witness_pt2[1] = sph_y2 + sph_radius2 * normal(0, 1);
  witness_pt2[2] = sph_z2 + sph_radius2 * normal(0, 2);

  blaze::StaticMatrix<avx256f, 3, NV> jac1_w = blaze::rows<0UL, 1UL, 2UL>(jac1);
  blaze::StaticMatrix<avx256f, 3, NV> jac1_v = blaze::rows<3UL, 4UL, 5UL>(jac1);

  blaze::StaticMatrix<avx256f, 3, NV> jac2_w = blaze::rows<0UL, 1UL, 2UL>(jac2);
  blaze::StaticMatrix<avx256f, 3, NV> jac2_v = blaze::rows<3UL, 4UL, 5UL>(jac2);

  blaze::StaticMatrix<avx256f, 3, NV> ptJac1 =
      jac1_v - hat(witness_pt1) * jac1_w;

  blaze::StaticMatrix<avx256f, 3, NV> ptJac2 =
      jac2_v - hat(witness_pt2) * jac2_w;

  // gradient of signed distance
  //sd_jac = blaze::transpose(normal) * (ptJac1 - ptJac2);
  blaze::StaticMatrix<avx256f, 1, NV> sd_jac = normal * (ptJac1 - ptJac2);

  // signed_distances and the constraint_jacobian need to be populated in
  // a particular order for batched outputs
  // signed_distances is of shape: (batch_dim, n_collision_pairs)
  // constraint_jacobian is of shape: (batch_dim * n_collision_pairs, NV)

  const size_t SIMD_WIDTH = 8;
  size_t N_CP = signed_distances.cols();

  // todo: find a more efficient way to do this
  for (size_t i = 0; i < SIMD_WIDTH; i++) {
    signed_distances(i, cp_it) = (double)signed_distance[i];
    for (size_t v = 0; v < NV; v++) {
      constraint_jacobian(i * N_CP + cp_it, v) = (double)sd_jac(0, v)[i];
    }
  }
}

}

#endif
