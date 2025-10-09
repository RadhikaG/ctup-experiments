#ifndef VAMP_COLLISION_H
#define VAMP_COLLISION_H

#include "ctup/typedefs.h"
#include "rla_fkcc_early_exit/runtime/typedefs.h"
#include "blaze/Math.h"

#include <vamp/vector.hh>
#include <vamp/collision/environment.hh>
#include <vamp/collision/validity.hh>

namespace ctup_runtime {


template<size_t rake, size_t N_FINE_SPH_1, size_t N_FINE_SPH_2>
static constexpr inline bool self_collision_link_vs_link(
    size_t geom_id_1,
    const vamp::FloatVector<rake>& coarse_1_x, 
    const vamp::FloatVector<rake>& coarse_1_y, 
    const vamp::FloatVector<rake>& coarse_1_z, 
    float coarse_1_r,
    size_t n_fine_1,
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH_1>& fine_1_x, 
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH_1>& fine_1_y, 
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH_1>& fine_1_z, 
    const std::array<float, N_FINE_SPH_1>& fine_1_r,
    size_t geom_id_2,
    const vamp::FloatVector<rake>& coarse_2_x, 
    const vamp::FloatVector<rake>& coarse_2_y, 
    const vamp::FloatVector<rake>& coarse_2_z, 
    float coarse_2_r,
    size_t n_fine_2,
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH_2>& fine_2_x, 
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH_2>& fine_2_y, 
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH_2>& fine_2_z, 
    const std::array<float, N_FINE_SPH_2>& fine_2_r) {

  bool is_coarse_collide, is_fine_collide;
  is_coarse_collide = false;
  is_fine_collide = false;

  vamp::FloatVector<rake> sv_1_r, sv_2_r;

  sv_1_r = static_cast<vamp::FloatVector<rake>>(coarse_1_r);
  sv_2_r = static_cast<vamp::FloatVector<rake>>(coarse_2_r);

  is_coarse_collide = vamp::sphere_sphere_self_collision<vamp::FloatVector<rake>>(
    coarse_1_x, coarse_1_y, coarse_1_z, sv_1_r,
    coarse_2_x, coarse_2_y, coarse_2_z, sv_2_r
  );

  //std::cout << "coarse: " << geom_id_1 << "," << geom_id_2 << " - collision: " 
  //    << (is_coarse_collide ? "yes" : "no") << "\n";

  // coarse spheres do not intersect, no fine check needed
  if (!is_coarse_collide)
    return false;

  if (is_coarse_collide) {
    // no fine spheres for either link, link geoms do intersect
    if constexpr (N_FINE_SPH_1 == 0 && N_FINE_SPH_2 == 0) {
      return true;
    }
    else if (N_FINE_SPH_1 == 0) {
      for (size_t j = 0; j < N_FINE_SPH_2; j++) {
        sv_2_r = static_cast<vamp::FloatVector<rake>>(fine_2_r[j]);

        is_fine_collide = vamp::sphere_sphere_self_collision<vamp::FloatVector<rake>>(
            coarse_1_x, coarse_1_y, coarse_1_z, sv_1_r,
            fine_2_x[j], fine_2_y[j], fine_2_z[j], sv_2_r
        );

        if (is_fine_collide)
          return true;
      }
    }
    else if (N_FINE_SPH_2 == 0) {
      for(size_t i = 0; i < N_FINE_SPH_1; i++) {
        sv_1_r = static_cast<vamp::FloatVector<rake>>(fine_1_r[i]);

        is_fine_collide = vamp::sphere_sphere_self_collision<vamp::FloatVector<rake>>(
            fine_1_x[i], fine_1_y[i], fine_1_z[i], sv_1_r,
            coarse_2_x, coarse_2_y, coarse_2_z, sv_2_r
        );

        if (is_fine_collide)
          return true;
      }
    }
    else {
      for (size_t j = 0; j < N_FINE_SPH_2; j++) {
        sv_2_r = static_cast<vamp::FloatVector<rake>>(fine_2_r[j]);

        for (size_t i = 0; i < N_FINE_SPH_1; i++) {
          sv_1_r = static_cast<vamp::FloatVector<rake>>(fine_1_r[i]);

          is_fine_collide = vamp::sphere_sphere_self_collision<vamp::FloatVector<rake>>(
              fine_1_x[i], fine_1_y[i], fine_1_z[i], sv_1_r,
              fine_2_x[j], fine_2_y[j], fine_2_z[j], sv_2_r
          );

          if (is_fine_collide)
            return true;
          }
      }
    }
  }

  // if control flow gets here, means none of the fine checks collided
  return false;
}

template<size_t rake, size_t N_FINE_SPH>
static constexpr inline bool link_vs_environment_collision(
    const vamp::FloatVector<rake>& coarse_x, 
    const vamp::FloatVector<rake>& coarse_y, 
    const vamp::FloatVector<rake>& coarse_z, 
    float coarse_r,
    size_t n_fine_sph,
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH>& fine_x, 
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH>& fine_y, 
    const std::array<vamp::FloatVector<rake>, N_FINE_SPH>& fine_z, 
    const std::array<float, N_FINE_SPH>& fine_r,
    const vamp::collision::Environment<vamp::FloatVector<rake>> &environment) {

  vamp::FloatVector<rake> sv_coarse_r = static_cast<vamp::FloatVector<rake>>(coarse_r);
  //if (vamp::sphere_environment_in_collision(environment, coarse_x, coarse_y, coarse_z, coarse_r)) {
  if (vamp::sphere_environment_in_collision<vamp::FloatVector<rake>>(environment, coarse_x, coarse_y, coarse_z, sv_coarse_r)) {
    for (size_t i = 0; i < N_FINE_SPH; i++) {
      vamp::FloatVector<rake> sv_fine_r = static_cast<vamp::FloatVector<rake>>(fine_r[i]);
      //if (vamp::sphere_environment_in_collision(environment, fine_x[i], fine_y[i], fine_z[i], fine_r[i])) {
      if (vamp::sphere_environment_in_collision<vamp::FloatVector<rake>>(environment, fine_x[i], fine_y[i], fine_z[i], sv_fine_r)) {
        return true;
      }
    }
  }
  return false;
}

}

#endif


