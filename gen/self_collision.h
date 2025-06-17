#ifndef SELF_COLLISION_H
#define SELF_COLLISION_H

#include "blaze/Math.h"
#include <vector>

using blazeVecSIMDd = blaze::StaticVector<double, 8>;
using Allocator = blaze::AlignedAllocator<blazeVecSIMDd>;
using AlignedSVd8Vector = std::vector<blazeVecSIMDd, Allocator>;

namespace runtime {

static bool self_collision_link_vs_link(
    blazeVecSIMDd& coarse_1_x, 
    blazeVecSIMDd& coarse_1_y, 
    blazeVecSIMDd& coarse_1_z, 
    double coarse_1_r,
    AlignedSVd8Vector& fine_1_x, 
    AlignedSVd8Vector& fine_1_y, 
    AlignedSVd8Vector& fine_1_z, 
    std::vector<double>& fine_1_r,
    blazeVecSIMDd& coarse_2_x, 
    blazeVecSIMDd& coarse_2_y, 
    blazeVecSIMDd& coarse_2_z, 
    double coarse_2_r,
    AlignedSVd8Vector& fine_2_x, 
    AlignedSVd8Vector& fine_2_y, 
    AlignedSVd8Vector& fine_2_z, 
    std::vector<double>& fine_2_r) {

  bool is_coarse_collide = false;

  // coarse CC check, see if coarse spheres intersect
  blazeVecSIMDd xs = coarse_1_x - coarse_2_x;
  blazeVecSIMDd ys = coarse_1_y - coarse_2_y;
  blazeVecSIMDd zs = coarse_1_z - coarse_2_z;

  blazeVecSIMDd sum = xs*xs + ys*ys + zs*zs;
  double rs = coarse_1_r + coarse_2_r;

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
      for (size_t j = 0; j< fine_2_x.size(); j++) {
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

}

#endif
