#ifndef XFORM_LAYOUTS_H
#define XFORM_LAYOUTS_H

#include "backend.h"
#include "matrix_layout_composite.h"
#include "spatial_algebra.h"

#include "blocks/block_visitor.h"
#include "blocks/c_code_generator.h"
#include "builder/builder_base.h"
#include "builder/builder_context.h"
#include "builder/dyn_var.h"
#include "builder/forward_declarations.h"
#include "Eigen/Dense"
#include "builder/static_var.h"

// ignore unused header warning in IDE, this is needed
#include "pinocchio/multibody/joint/joint-collection.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <memory>
#include <string>

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;

namespace ctup {

////// SPARSE, BLOCKED //////
/// Combos tested:
/// * SPARSE, UNROLLED, UNCOMPRESSED
/// * SPARSE, FLATTENED, UNCOMPRESSED
/// * SPARSE, FLATTENED, COMPRESSED
/// * TILE, EIGENMATRIX, UNCOMPRESSED

template <typename Scalar>
struct Translation : public matrix_layout<Scalar> {
  typedef std::shared_ptr<Translation<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;

  Translation() : matrix_layout<Scalar>(3, 3, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_zero();
  }

  dyn_var<Scalar> x;
  dyn_var<Scalar> y;
  dyn_var<Scalar> z;

  static_var<int> joint_xform_axis;

  void jcalc(const dyn_var<Scalar> &q_i) {
    if (joint_xform_axis == 'X') {
      set_entry_to_nonconstant(1, 2, q_i);
      set_entry_to_nonconstant(2, 1, -q_i);
    }
    else if (joint_xform_axis == 'Y') {
      set_entry_to_nonconstant(2, 0, q_i);
      set_entry_to_nonconstant(0, 2, -q_i);
    }
    else if (joint_xform_axis == 'Z') {
      set_entry_to_nonconstant(0, 1, q_i);
      set_entry_to_nonconstant(1, 0, -q_i);
    }
  }
};

template <typename Scalar>
struct Rotation : public matrix_layout<Scalar> {
  typedef std::shared_ptr<Rotation<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_xform_axis;

  Rotation() : matrix_layout<Scalar>(3, 3, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_identity();
  }

  void jcalc(const dyn_var<Scalar> &q_i) {
    sinq = backend::sin<Scalar>(q_i);
    cosq = backend::cos<Scalar>(q_i);

    if (joint_xform_axis == 'X') {
      set_entry_to_nonconstant(1, 1, cosq);
      set_entry_to_nonconstant(1, 2, sinq);
      set_entry_to_nonconstant(2, 1, -sinq);
      set_entry_to_nonconstant(2, 2, cosq);
    }
    else if (joint_xform_axis == 'Y') {
      set_entry_to_nonconstant(0, 0, cosq);
      set_entry_to_nonconstant(0, 2, -sinq);
      set_entry_to_nonconstant(2, 0, sinq);
      set_entry_to_nonconstant(2, 2, cosq);
    }
    else if (joint_xform_axis == 'Z') {
      set_entry_to_nonconstant(0, 0, cosq);
      set_entry_to_nonconstant(0, 1, sinq);
      set_entry_to_nonconstant(1, 0, -sinq);
      set_entry_to_nonconstant(1, 1, cosq);
    }
    else {
      assert(false && "jcalc called on non joint xform or joint unset");
    }
  }
};

template <typename Scalar>
struct XformBlocked : public blocked_layout<Scalar> {
  using blocked_layout<Scalar>::set_partitions;
  using blocked_layout<Scalar>::set_new_block;
  using blocked_layout<Scalar>::operator=;

  typename Rotation<Scalar>::Ptr rot;
  typename Translation<Scalar>::Ptr trans;
  typename matrix_layout<Scalar>::Ptr minus_E_rcross;

  static_var<int> joint_type;

  XformBlocked() : blocked_layout<Scalar>(6, 6), 
    rot(new Rotation<Scalar>()), trans(new Translation<Scalar>()), 
    minus_E_rcross(new matrix_layout<Scalar>(3, 3, SPARSE, FLATTENED, COMPRESSED)) {

    minus_E_rcross->set_zero();
    set_partitions({0, 3}, {0, 3});
    set_new_block(0, 0, rot);
    set_new_block(1, 1, rot);
    set_new_block(1, 0, minus_E_rcross);
  }

  void set_revolute_axis(char axis) {
    assert((axis == 'X' || axis == 'Y' || axis == 'Z') && "axis must be X,Y,Z");
    rot->joint_xform_axis = axis;
    joint_type = 'R';
  }

  void set_prismatic_axis(char axis) {
    assert((axis == 'X' || axis == 'Y' || axis == 'Z') && "axis must be X,Y,Z");
    trans->joint_xform_axis = axis;
    joint_type = 'P';
  }

  void jcalc(const dyn_var<Scalar> &q_i) {
    if (joint_type == 'R')
      rot->jcalc(q_i);
    else
      trans->jcalc(q_i);

    *minus_E_rcross = -(*rot) * (*trans);
  }
};

////// NON-BLOCKED //////
/// Combos tested:
/// * SPARSE, UNROLLED, UNCOMPRESSED
/// * SPARSE, FLATTENED, UNCOMPRESSED
/// * SPARSE, FLATTENED, COMPRESSED
/// * TILE, EIGENMATRIX, UNCOMPRESSED

template <typename Scalar>
struct XformNonBlocked : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_type;
  static_var<int> joint_xform_axis;

  XformNonBlocked() : matrix_layout<Scalar>(6, 6, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_identity();
  }

  void set_revolute_axis(char axis) {
    assert((axis == 'X' || axis == 'Y' || axis == 'Z') && "axis must be X,Y,Z");
    joint_xform_axis = axis;
    joint_type = 'R';
  }

  void set_prismatic_axis(char axis) {
    assert((axis == 'X' || axis == 'Y' || axis == 'Z') && "axis must be X,Y,Z");
    joint_xform_axis = axis;
    joint_type = 'P';
  }

  void jcalc(const dyn_var<Scalar> &q_i) {
    sinq = backend::sin<Scalar>(q_i);
    cosq = backend::cos<Scalar>(q_i);

    if (joint_type == 'R') {
      if (joint_xform_axis == 'X') {
        set_entry_to_nonconstant(1, 1, cosq);
        set_entry_to_nonconstant(1, 2, sinq);
        set_entry_to_nonconstant(2, 1, -sinq);
        set_entry_to_nonconstant(2, 2, cosq);
        // symm E
        set_entry_to_nonconstant(3+1, 3+1, cosq);
        set_entry_to_nonconstant(3+1, 3+2, sinq);
        set_entry_to_nonconstant(3+2, 3+1, -sinq);
        set_entry_to_nonconstant(3+2, 3+2, cosq);
      }
      else if (joint_xform_axis == 'Y') {
        set_entry_to_nonconstant(0, 0, cosq);
        set_entry_to_nonconstant(0, 2, -sinq);
        set_entry_to_nonconstant(2, 0, sinq);
        set_entry_to_nonconstant(2, 2, cosq);
        // symm E
        set_entry_to_nonconstant(3+0, 3+0, cosq);
        set_entry_to_nonconstant(3+0, 3+2, -sinq);
        set_entry_to_nonconstant(3+2, 3+0, sinq);
        set_entry_to_nonconstant(3+2, 3+2, cosq);
      }
      else if (joint_xform_axis == 'Z') {
        set_entry_to_nonconstant(0, 0, cosq);
        set_entry_to_nonconstant(0, 1, sinq);
        set_entry_to_nonconstant(1, 0, -sinq);
        set_entry_to_nonconstant(1, 1, cosq);
        // symm E
        set_entry_to_nonconstant(3+0, 3+0, cosq);
        set_entry_to_nonconstant(3+0, 3+1, sinq);
        set_entry_to_nonconstant(3+1, 3+0, -sinq);
        set_entry_to_nonconstant(3+1, 3+1, cosq);
      }
    }
    else if (joint_type == 'P') {
      // negative r-cross, opp signs of featherstone 2.23
      if (joint_xform_axis == 'X') {
        set_entry_to_nonconstant(3+1, 2, q_i);
        set_entry_to_nonconstant(3+2, 1, -q_i);
      }
      else if (joint_xform_axis == 'Y') {
        set_entry_to_nonconstant(3+2, 0, q_i);
        set_entry_to_nonconstant(3+0, 2, -q_i);
      }
      else if (joint_xform_axis == 'Z') {
        set_entry_to_nonconstant(3+0, 1, q_i);
        set_entry_to_nonconstant(3+1, 0, -q_i);
      }
    }
    else {
      assert(false && "jcalc called on non joint xform or joint unset");
    }
  }

  using matrix_layout<Scalar>::operator=;
};

}

#endif
