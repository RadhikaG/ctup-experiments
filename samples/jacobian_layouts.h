#ifndef JACOBIAN_LAYOUTS_H
#define JACOBIAN_LAYOUTS_H

#include "backend.h"
#include "matrix_layout.h"
#include "matrix_layout_composite.h"

#include "builder/dyn_var.h"
#include "builder/forward_declarations.h"
#include "Eigen/Dense"
#include "builder/static_var.h"

#include "assert.h"

using builder::dyn_var;
using builder::static_var;

namespace ctup {

template <typename Scalar>
struct Rotation : public matrix_layout<Scalar> {
  typedef std::shared_ptr<Rotation<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  using matrix_layout<Scalar>::operator=;

  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_xform_axis;

  Rotation() : matrix_layout<Scalar>(3, 3, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_identity();
  }

  void jcalc(const dyn_var<Scalar> &q_i) {
    sinq = backend::sin<Scalar>(q_i);
    cosq = backend::cos<Scalar>(q_i);

    // feath
    //if (joint_xform_axis == 'X') {
    //  set_entry_to_nonconstant(1, 1, cosq);
    //  set_entry_to_nonconstant(1, 2, sinq);
    //  set_entry_to_nonconstant(2, 1, -sinq);
    //  set_entry_to_nonconstant(2, 2, cosq);
    //}
    //else if (joint_xform_axis == 'Y') {
    //  set_entry_to_nonconstant(0, 0, cosq);
    //  set_entry_to_nonconstant(0, 2, -sinq);
    //  set_entry_to_nonconstant(2, 0, sinq);
    //  set_entry_to_nonconstant(2, 2, cosq);
    //}
    //else if (joint_xform_axis == 'Z') {
    //  set_entry_to_nonconstant(0, 0, cosq);
    //  set_entry_to_nonconstant(0, 1, sinq);
    //  set_entry_to_nonconstant(1, 0, -sinq);
    //  set_entry_to_nonconstant(1, 1, cosq);
    //}
    //else {
    //  assert(false && "jcalc called on non joint xform or joint unset");
    //}

    // pin
    if (joint_xform_axis == 'X') {
      set_entry_to_nonconstant(1, 1, cosq);
      set_entry_to_nonconstant(1, 2, -sinq);
      set_entry_to_nonconstant(2, 1, sinq);
      set_entry_to_nonconstant(2, 2, cosq);
    }
    else if (joint_xform_axis == 'Y') {
      set_entry_to_nonconstant(0, 0, cosq);
      set_entry_to_nonconstant(0, 2, sinq);
      set_entry_to_nonconstant(2, 0, -sinq);
      set_entry_to_nonconstant(2, 2, cosq);
    }
    else if (joint_xform_axis == 'Z') {
      set_entry_to_nonconstant(0, 0, cosq);
      set_entry_to_nonconstant(0, 1, -sinq);
      set_entry_to_nonconstant(1, 0, sinq);
      set_entry_to_nonconstant(1, 1, cosq);
    }
    else {
      assert(false && "jcalc called on non joint xform or joint unset");
    }
  }
};

template <typename Scalar>
struct Translation : public matrix_layout<Scalar> {
  typedef std::shared_ptr<Translation<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  using matrix_layout<Scalar>::operator=;

  Translation() : matrix_layout<Scalar>(3, 1, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_zero();
  }

  static_var<int> joint_xform_axis;

  void jcalc(const dyn_var<Scalar> &q_i) {
    if (joint_xform_axis == 'X') {
      set_entry_to_nonconstant(0, 0, q_i);
    }
    else if (joint_xform_axis == 'Y') {
      set_entry_to_nonconstant(1, 0, q_i);
    }
    else if (joint_xform_axis == 'Z') {
      set_entry_to_nonconstant(2, 0, q_i);
    }
  }
};


template <typename Scalar>
struct Xform : public blocked_layout<Scalar> {
  using blocked_layout<Scalar>::set_partitions;
  using blocked_layout<Scalar>::set_new_block;
  using blocked_layout<Scalar>::operator=;

  typename Rotation<Scalar>::Ptr rot;
  typename Translation<Scalar>::Ptr trans;
  typename matrix_layout<Scalar>::Ptr one;

  static_var<int> joint_type;

  Xform() : blocked_layout<Scalar>(4, 4), 
    rot(new Rotation<Scalar>()), 
    trans(new Translation<Scalar>()),
    one(new matrix_layout<Scalar>(1, 1, DENSE, UNROLLED, UNCOMPRESSED)) {
    one->set_entry_to_constant(0, 0, 1);

    set_partitions({0, 3}, {0, 3});
    set_new_block(0, 0, rot);
    set_new_block(0, 1, trans);
    set_new_block(1, 1, one);

    blocked_layout<Scalar>::set_identity();
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
  }

  matrix_layout<Scalar>& get_rotation() const {
    return *rot;
  }

  matrix_layout<Scalar>& get_translation() const {
    return *trans;
  }
};

template <typename Scalar>
struct SkewTranslation : public matrix_layout<Scalar> {
  typedef std::shared_ptr<SkewTranslation<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  using matrix_layout<Scalar>::operator=;

  SkewTranslation() : matrix_layout<Scalar>(3, 3, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_zero();
  }

  static_var<int> joint_xform_axis;

  void set_from_xyz(const matrix_layout<Scalar> &trans) {
    assert(trans.get_n_rows() == 3 && trans.get_n_cols() == 1 && "trans must be 3x1");
    // feath
    // x
    if (trans.is_nonconstant(0, 0)) {
      set_entry_to_nonconstant(1, 2, -trans.get_entry(0, 0));
      set_entry_to_nonconstant(2, 1, trans.get_entry(0, 0));
    }
    else {
      set_entry_to_constant(1, 2, -trans.get_constant_entry(0, 0));
      set_entry_to_constant(2, 1, trans.get_constant_entry(0, 0));
    }

    // y 
    if (trans.is_nonconstant(1, 0)) {
      set_entry_to_nonconstant(2, 0, -trans.get_entry(1, 0));
      set_entry_to_nonconstant(0, 2, trans.get_entry(1, 0));
    }
    else {
      set_entry_to_constant(2, 0, -trans.get_constant_entry(1, 0));
      set_entry_to_constant(0, 2, trans.get_constant_entry(1, 0));
    }

    // z 
    if (trans.is_nonconstant(2, 0)) {
      set_entry_to_nonconstant(0, 1, -trans.get_entry(2, 0));
      set_entry_to_nonconstant(1, 0, trans.get_entry(2, 0));
    }
    else {
      set_entry_to_constant(0, 1, -trans.get_constant_entry(2, 0));
      set_entry_to_constant(1, 0, trans.get_constant_entry(2, 0));
    }
  }
};

template <typename Scalar>
struct Adjoint : public blocked_layout<Scalar> {
  using blocked_layout<Scalar>::set_partitions;
  using blocked_layout<Scalar>::set_new_block;
  using blocked_layout<Scalar>::operator=;

  typename Rotation<Scalar>::Ptr rot;
  typename SkewTranslation<Scalar>::Ptr skew_trans;
  typename matrix_layout<Scalar>::Ptr t_cross_R;

  static_var<int> joint_type;

  Adjoint() : blocked_layout<Scalar>(6, 6), 
    rot(new Rotation<Scalar>()), skew_trans(new SkewTranslation<Scalar>()), 
    t_cross_R(new matrix_layout<Scalar>(3, 3, SPARSE, FLATTENED, COMPRESSED)) {

    t_cross_R->set_zero();
    set_partitions({0, 3}, {0, 3});
    set_new_block(0, 0, rot);
    set_new_block(1, 1, rot);
    set_new_block(1, 0, t_cross_R); // feath
  }

  void set_rotation_and_translation(matrix_layout<Scalar> &_rot, matrix_layout<Scalar> &_trans) {
    assert(_rot.get_n_rows() == 3 && _rot.get_n_cols() == 3 && "rot must be 3x3");
    assert(_trans.get_n_rows() == 3 && _trans.get_n_cols() == 1 && "trans must be 3x1");

    *rot = _rot;
    skew_trans->set_from_xyz(_trans);

    *t_cross_R = (*skew_trans) * (*rot);
  }
};

template <typename Scalar>
struct SpatialVector : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  using matrix_layout<Scalar>::operator=;

  SpatialVector() : matrix_layout<Scalar>(6, 1, DENSE, FLATTENED, UNCOMPRESSED) {
    matrix_layout<Scalar>::set_zero();
  }
};

template <typename Scalar>
struct SingletonSpatialVector : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  using matrix_layout<Scalar>::operator=;

  static_var<int> motion_subspace_axis;

  SingletonSpatialVector() : matrix_layout<Scalar>(6, 1, SPARSE, FLATTENED, SINGLETON) {
    matrix_layout<Scalar>::set_zero();
  }

  void set_revolute_axis(char axis) {
    motion_subspace_axis = axis;

    // feath
    // rotational omega on top
    if (motion_subspace_axis == 'X')
      set_entry_to_constant(0, 0, 1);
    else if (motion_subspace_axis == 'Y')
      set_entry_to_constant(1, 0, 1);
    else if (motion_subspace_axis == 'Z')
      set_entry_to_constant(2, 0, 1);
  }

  void set_prismatic_axis(char axis) {
    motion_subspace_axis = axis;

    // feath
    // linear v on bottom
    if (motion_subspace_axis == 'X')
      set_entry_to_constant(3, 0, 1);
    else if (motion_subspace_axis == 'Y')
      set_entry_to_constant(4, 0, 1);
    else if (motion_subspace_axis == 'Z')
      set_entry_to_constant(5, 0, 1);
  }
};

}

#endif
