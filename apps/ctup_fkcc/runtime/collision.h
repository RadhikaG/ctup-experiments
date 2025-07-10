#ifndef CTUP_FKCC_COLLISION_H
#define CTUP_FKCC_COLLISION_H

#include "ctup/typedefs.h"
#include "blaze/Math.h"
#include <vector>

#include <vamp/collision/environment.hh>
#include <vamp/collision/validity.hh>

namespace ctup_runtime {

template <typename SV>
using AlignedVec = AlignedVec<SV>;

template <typename Prim>
using inner_type_t = typename inner_type<Prim>::type;

template<typename SV>
static bool self_collision_link_vs_link(
    size_t geom_id_1,
    SV& coarse_1_x, 
    SV& coarse_1_y, 
    SV& coarse_1_z, 
    inner_type_t<SV> coarse_1_r,
    AlignedVec<SV>& fine_1_x, 
    AlignedVec<SV>& fine_1_y, 
    AlignedVec<SV>& fine_1_z, 
    std::vector<inner_type_t<SV>>& fine_1_r,
    size_t geom_id_2,
    SV& coarse_2_x, 
    SV& coarse_2_y, 
    SV& coarse_2_z, 
    inner_type_t<SV> coarse_2_r,
    AlignedVec<SV>& fine_2_x, 
    AlignedVec<SV>& fine_2_y, 
    AlignedVec<SV>& fine_2_z, 
    std::vector<inner_type_t<SV>>& fine_2_r) {

  bool is_coarse_collide = false;

  //std::cout << "coarse sphere " << geom_id_1 << " translation: \n";
  //std::cout << coarse_1_x[0] << " " <<
  //  coarse_1_y[0] << " " <<
  //  coarse_1_z[0] << "\n";
  //std::cout << "coarse sphere " << geom_id_2 << " translation: \n";
  //std::cout << coarse_2_x[0] << " " <<
  //  coarse_2_y[0] << " " <<
  //  coarse_2_z[0] << "\n";

  // checking 8 course sphs at once

  // coarse CC check, see if coarse spheres intersect
  SV xs = coarse_1_x - coarse_2_x;
  SV ys = coarse_1_y - coarse_2_y;
  SV zs = coarse_1_z - coarse_2_z;

  SV sum = xs*xs + ys*ys + zs*zs;
  inner_type_t<SV> rs = coarse_1_r + coarse_2_r;

  sum = sum - rs*rs;

  is_coarse_collide = (blaze::min(sum) < 0.0);

  // coarse spheres do not intersect, no fine check needed
  if (!is_coarse_collide)
    return false;

  if (is_coarse_collide) {
    // no fine spheres for either link, link geoms do intersect
    if(fine_1_x.size() == 0 and fine_2_x.size() == 0) {
      return true;
    }
    else if (fine_1_x.size() == 0) {
      for (size_t j = 0; j < fine_2_x.size(); j++) {
        xs = (coarse_1_x - fine_2_x[j]);
        ys = (coarse_1_y - fine_2_y[j]);
        zs = (coarse_1_z - fine_2_z[j]);

        sum = xs*xs + ys*ys + zs*zs;
        rs = coarse_1_r + fine_2_r[j];

        sum = sum - rs*rs;

        if (blaze::min(sum) < 0.0)
          return true;
      }
    }
    else if (fine_2_x.size() == 0) {
      for(size_t i = 0; i < fine_1_x.size(); i++) {
        xs = (fine_1_x[i] - coarse_2_x);
        ys = (fine_1_y[i] - coarse_2_y);
        zs = (fine_1_z[i] - coarse_2_z);

        sum = xs*xs + ys*ys + zs*zs;
        rs = fine_1_r[i] + coarse_2_r;

        sum = sum - rs*rs;

        if (blaze::min(sum) < 0.0)
          return true;
      }
    }
    else {
      for (size_t j = 0; j < fine_2_x.size(); j++) {
        for (size_t i = 0; i < fine_1_x.size(); i++) {
          xs = (fine_1_x[i] - fine_2_x[j]);
          ys = (fine_1_y[i] - fine_2_y[j]);
          zs = (fine_1_z[i] - fine_2_z[j]);

          sum = xs*xs + ys*ys + zs*zs;
          rs = fine_1_r[i] + fine_2_r[j];

          sum = sum - rs*rs;

          if (blaze::min(sum) < 0.0) 
            return true;
        }
      }
    }
  }

  // if control flow gets here, means none of the fine checks collided
  return false;
}

template<typename SV>
static bool link_vs_environment_collision(
    SV& coarse_x, 
    SV& coarse_y, 
    SV& coarse_z, 
    inner_type_t<SV> coarse_r,
    AlignedVec<SV>& fine_x, 
    AlignedVec<SV>& fine_y, 
    AlignedVec<SV>& fine_z, 
    std::vector<inner_type_t<SV>>& fine_r,
    const vamp::collision::Environment<SV> &environment) {

  SV sv_coarse_r = SV(coarse_r);
  //if (vamp::sphere_environment_in_collision(environment, coarse_x, coarse_y, coarse_z, coarse_r)) {
  if (vamp::sphere_environment_in_collision(environment, coarse_x, coarse_y, coarse_z, sv_coarse_r)) {
    for (size_t i = 0; i < fine_r.size(); i++) {
      SV sv_fine_r = SV(fine_r[i]);
      //if (vamp::sphere_environment_in_collision(environment, fine_x[i], fine_y[i], fine_z[i], fine_r[i])) {
      if (vamp::sphere_environment_in_collision(environment, fine_x[i], fine_y[i], fine_z[i], sv_fine_r)) {
        return true;
      }
    }
  }
  return false;
}

}

#endif
