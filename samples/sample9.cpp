// ./build/sample9 ./deps/pinocchio/models/baxter_simple.urdf ../ctup-experiments/gen/fk_gen_unrolled.h
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
    sinq = backend::sin(q_i);
    cosq = backend::cos(q_i);

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
struct Xform : public blocked_layout<Scalar> {
  using blocked_layout<Scalar>::set_partitions;
  using blocked_layout<Scalar>::set_new_block;
  using blocked_layout<Scalar>::operator=;

  typename Rotation<Scalar>::Ptr rot;
  typename Translation<Scalar>::Ptr trans;
  typename matrix_layout<Scalar>::Ptr minus_E_rcross;

  static_var<int> joint_type;

  Xform() : blocked_layout<Scalar>(6, 6), 
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

}

/** helpers **/

using ctup::Xform;
using ctup::EigenMatrix;

builder::dyn_var<void(EigenMatrix<double> &)> print_matrix = builder::as_global("print_matrix");
builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

static int get_jtype(const Model &model, Model::JointIndex i) {
  std::string joint_name = model.joints[i].shortname();

  bool is_revolute = joint_name.find("JointModelR") != std::string::npos;
  bool is_prismatic = joint_name.find("JointModelP") != std::string::npos;

  if (is_revolute)
    return 'R';
  if (is_prismatic)
    return 'P';
  else
    return 'N';
}

static int get_joint_axis(const Model &model, Model::JointIndex i) {
  std::string joint_name = model.joints[i].shortname();
  char axis = joint_name.back();

  switch(axis) {
    case 'X': return 'X';
    case 'Y': return 'Y';
    case 'Z': return 'Z';
    default: assert(false && "should never happen"); return -1;
  }
}

template <typename Scalar, int Rows_, int Cols_>
static void toPinEigen(dyn_var<EigenMatrix<Scalar, Rows_, Cols_>> &mat, Xform<Scalar> &xform) {
  static_var<int> r, c;

  for (r = 0; r < 6; r = r + 1)
    for (c = 0; c < 6; c = c + 1)
      mat.coeffRef(r, c) = xform.get_entry(c, r);
}

template <typename Scalar>
static void print_Xmat(std::string prefix, Xform<Scalar> &xform) {
  print_string(prefix.c_str());
  print_matrix(xform.denseify());
}

template <typename Scalar>
static void print_Xmat_pin_order(std::string prefix, Xform<Scalar> &xform) {
  print_string(prefix.c_str());
  dyn_var<EigenMatrix<Scalar>> mat;
  mat.set_matrix_fixed_size(xform.shape[0], xform.shape[1]);
  toPinEigen(mat, xform);
  print_matrix(mat);
}

/** helpers end **/

template <typename Scalar>
static void set_X_T(Xform<Scalar> X_T[], const Model &model) {
  typedef typename Model::JointIndex JointIndex;

  static_var<int> r;
  static_var<int> c;

  for (static_var<size_t> i = 1; i < (JointIndex)model.njoints; i = i+1) {
    Eigen::Matrix<double, 6, 6> pin_X_T = model.jointPlacements[i];

    for (r = 0; r < 6; r = r + 1) {
      for (c = 0; c < 6; c = c + 1) {
        double entry = pin_X_T.coeffRef(c, r);
        X_T[i].set_entry_to_constant(r, c, entry);
      }
    }
  }
}

static dyn_var<EigenMatrix<double, 6, 6>> fk(const Model &model, dyn_var<builder::eigen_vectorXd_t &> q) {
  typedef typename Model::JointIndex JointIndex;

  Xform<double> X_T[model.njoints];
  Xform<double> X_J[model.njoints];
  Xform<double> X_0[model.njoints];

  static_var<JointIndex> i;

  set_X_T(X_T, model);

  static_var<int> jtype;
  static_var<int> axis;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    jtype = get_jtype(model, i);
    axis = get_joint_axis(model, i);

    if (jtype == 'R') {
      X_J[i].set_revolute_axis(axis);
    }
    if (jtype == 'P') {
      X_J[i].set_prismatic_axis(axis);
    }
  }

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    Xform<double> X_pi;
    X_J[i].jcalc(q(i-1));

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::blocked_layout_expr_leaf<double>(X_pi);
    }
  }

  //for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
  //  if (i <= 4) {
  //    Xform<double> X_pi;
  //    print_Xmat_pin_order("XT ", X_T[i]);
  //    print_Xmat_pin_order("XJ ", X_J[i]);
  //    X_pi = X_J[i] * X_T[i];
  //    print_Xmat_pin_order("Xpi ", X_pi);
  //    print_Xmat_pin_order("Xpar ", X_0[model.parents[i]]);
  //  }

  //  std::string prefix("X ");
  //  print_Xmat_pin_order(prefix + std::to_string(i), X_0[i]);
  //}

  dyn_var<EigenMatrix<double, 6, 6>> final_ans;
  toPinEigen(final_ans, X_0[model.njoints-1]);

  return final_ans;
}

int main(int argc, char* argv[]) {
  const std::string urdf_filename = argv[1];
  std::cout << urdf_filename << "\n";

  const std::string header_filename = (argc <= 2) ? "./fk_gen.h" : argv[2];
  std::cout << header_filename << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  of << "#include \"Eigen/Dense\"\n\n";
  of << "#include <iostream>\n\n";
  of << "namespace ctup_gen {\n\n";

  of << "static void print_string(const char* str) {\n";
  of << "  std::cout << str << \"\\n\";\n";
  of << "}\n\n";

  of << "template<typename Derived>\n";
  of << "static void print_matrix(const Eigen::MatrixBase<Derived>& matrix) {\n";
  of << "  std::cout << matrix << \"\\n\";\n";
  of << "}\n\n";

  builder::builder_context context;

  auto ast = context.extract_function_ast(fk, "fk", model);
  of << "static ";
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
