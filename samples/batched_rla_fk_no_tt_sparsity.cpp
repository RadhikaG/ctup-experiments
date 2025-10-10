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
#include "builder/static_var.h"

// ignore unused header warning in IDE, this is needed
#include "pinocchio/multibody/joint/joint-collection.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <string>
#include <argparse/argparse.hpp>

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;

/** Xform with no trace-time sparsity **/
// So: DENSE, FLATTENED, UNCOMPRESSED
// We do keep trace-time const prop just to isolate effects
// of stage 1 compile-time sparsity ("structure") and
// stage 1 run-time sparsity ("sparsity")

namespace ctup {

template <typename Scalar>
struct Translation : public matrix_layout<Scalar> {
  typedef std::shared_ptr<Translation<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;

  Translation() : matrix_layout<Scalar>(3, 3, DENSE, FLATTENED, UNCOMPRESSED) {
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

  Rotation() : matrix_layout<Scalar>(3, 3, DENSE, FLATTENED, UNCOMPRESSED) {
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
    minus_E_rcross(new matrix_layout<Scalar>(3, 3, DENSE, FLATTENED, UNCOMPRESSED)) {

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

template <typename Scalar>
struct XformNonBlocked : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_type;
  static_var<int> joint_xform_axis;

  XformNonBlocked() : matrix_layout<Scalar>(6, 6, DENSE, FLATTENED, UNCOMPRESSED) {
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

template <typename Scalar>
using Xform = ctup::XformBlocked<Scalar>;

/** --------------------------------- **/

/** helpers **/

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

using ctup::BlazeStaticVector;
using ctup::BlazeStaticMatrix;
using ctup::backend::blaze_avx512d;

builder::dyn_var<void(BlazeStaticMatrix<double> &)> print_matrix = builder::as_global("print_matrix");
builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

template <typename Scalar>
static void print_Xmat(std::string prefix, Xform<Scalar> &xform) {
  print_string(prefix.c_str());
  print_matrix(xform.denseify());
}

static void toRawMatrix(dyn_var<BlazeStaticMatrix<blaze_avx512d>> &raw_mat, Xform<blaze_avx512d> &xform) {
  static_var<int> r, c;

  for (r = 0; r < 6; r = r + 1)
    for (c = 0; c < 6; c = c + 1)
      raw_mat(r, c) = xform.get_entry(r, c);
}

/** helpers end **/

template <typename Prim>
static void set_X_T(builder::array<Xform<Prim>> &X_T, const Model &model) {
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

static dyn_var<BlazeStaticMatrix<blaze_avx512d>> fk(const Model &model, dyn_var<BlazeStaticVector<blaze_avx512d> &> q) {
  typedef typename Model::JointIndex JointIndex;

  builder::array<Xform<blaze_avx512d>> X_T;
  builder::array<Xform<blaze_avx512d>> X_J;
  builder::array<Xform<blaze_avx512d>> X_0;

  X_T.set_size(model.njoints);
  X_J.set_size(model.njoints);
  X_0.set_size(model.njoints);

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

  Xform<blaze_avx512d> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::blocked_layout_expr_leaf<blaze_avx512d>(X_pi);
    }
  }

  // CTUP debug
  //for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
  //  if (i <= 4) {
  //    print_Xmat("XT ", X_T[i]);
  //    print_Xmat("XJ ", X_J[i]);
  //    X_pi = X_J[i] * X_T[i];
  //    print_Xmat("Xpi ", X_pi);
  //    print_Xmat("Xpar ", X_0[model.parents[i]]);
  //  }

  //  std::string prefix("X ");
  //  print_Xmat(prefix + std::to_string(i), X_0[i]);
  //}

  dyn_var<BlazeStaticMatrix<blaze_avx512d>> final_ans;
  final_ans.set_matrix_fixed_size(6, 6);
  toRawMatrix(final_ans, X_0[model.njoints-1]);

  return final_ans;
}

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program("batched_rla_fk_no_tt_sparsity");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("-o", "--output")
      .default_value(std::string("./fk_gen.h"))
      .help("output header file path");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string header_filename = program.get<std::string>("--output");

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Output header: " << header_filename << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  of << "// clang-format off\n\n";
  of << "#include \"Eigen/Dense\"\n\n";
  of << "#include \"blaze/Math.h\"\n\n";
  of << "#include <iostream>\n\n";
  of << "namespace ctup_gen {\n\n";

  of << "static void print_string(const char* str) {\n";
  of << "  std::cout << str << \"\\n\";\n";
  of << "}\n\n";

  //----- todo fix print funcs

  of << "static void print_matrix(const blaze::StaticMatrix<blaze::StaticVector<double, 8>, 6, 6>& matrix) {\n";
  of << "  for (int i = 0; i < 6; i++) {\n";
  of << "    for (int j = 0; j < 6; j++) {\n";
  of << "      blaze::StaticVector<double, 8> colVec(matrix(i, j));\n";
  of << "      blaze::StaticVector<double, 8, blaze::rowVector> rowVec;\n";
  of << "      for (int k = 0; k < 8; k++)\n";
  of << "        rowVec[k] = colVec[k];\n";
  of << "      std::cout << rowVec;\n";
  of << "    }\n";
  of << "  }\n";
  of << "}\n\n";

  of << "template<typename MT>\n";
  of << "static void print_matrix(const blaze::DenseMatrix<MT, blaze::rowMajor>& matrix) {\n";
  of << "  std::cout << matrix << \"\\n\";\n";
  of << "}\n\n";

  of << "template<typename Derived>\n";
  of << "static void print_matrix(const Eigen::MatrixBase<Derived>& matrix) {\n";
  of << "  std::cout << matrix << \"\\n\";\n";
  of << "}\n\n";

  //-------------------------

  builder::builder_context context;
  context.run_rce = true;

  auto ast = context.extract_function_ast(fk, "fk", model);
  of << "static ";
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
