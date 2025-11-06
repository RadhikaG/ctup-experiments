// Batched FK study comparing CT structure, TT sparsity, and no optimizations
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

using ctup::BlazeStaticVector;
using ctup::BlazeStaticMatrix;
using ctup::backend::blaze_avx256f;

////////////////////////////////////////////////////////////////////////
/// DATA STRUCTURES FOR TURNING CT STRUCT AND TT SPARSITY ON-OFF ///////
///////////////////////////////////////////////////////////////////////

namespace ctup {

////////////// Only Compile-Time (CT) Structure /////////////

/** Xform with no trace-time sparsity **/
// So: DENSE, FLATTENED, UNCOMPRESSED
// We do keep trace-time const prop just to isolate effects
// of stage 1 compile-time sparsity ("structure") and
// stage 1 run-time sparsity ("sparsity")

template <typename Scalar>
struct TranslationCT : public matrix_layout<Scalar> {
  typedef std::shared_ptr<TranslationCT<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;

  TranslationCT() : matrix_layout<Scalar>(3, 3, DENSE, FLATTENED, UNCOMPRESSED) {
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
struct RotationCT : public matrix_layout<Scalar> {
  typedef std::shared_ptr<RotationCT<Scalar>> Ptr;

  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_xform_axis;

  RotationCT() : matrix_layout<Scalar>(3, 3, DENSE, FLATTENED, UNCOMPRESSED) {
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
struct XformBlockedCT : public blocked_layout<Scalar> {
  using blocked_layout<Scalar>::set_partitions;
  using blocked_layout<Scalar>::set_new_block;
  using blocked_layout<Scalar>::operator=;

  typename RotationCT<Scalar>::Ptr rot;
  typename TranslationCT<Scalar>::Ptr trans;
  typename matrix_layout<Scalar>::Ptr minus_E_rcross;

  static_var<int> joint_type;

  XformBlockedCT() : blocked_layout<Scalar>(6, 6),
    rot(new RotationCT<Scalar>()), trans(new TranslationCT<Scalar>()),
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

/////////////////////////////////////////////

////////////// Only Trace-Time (TT) Sparsity /////////////

template <typename Scalar>
struct XformTT : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_type;
  static_var<int> joint_xform_axis;

  XformTT() : matrix_layout<Scalar>(6, 6, SPARSE, UNROLLED, UNCOMPRESSED) {
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

/////////////////////////////////////////////

////////////// No CT structure or TT sparsity /////////////

template <typename Scalar>
struct XformNoCTNoTT : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_type;
  static_var<int> joint_xform_axis;

  XformNoCTNoTT() : matrix_layout<Scalar>(6, 6, DENSE, FLATTENED, UNCOMPRESSED) {
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

/////////////////////////////////////////////

}

/////////////////////////////////////////////
////////////   HELPER FUNCTIONS /////////////
/////////////////////////////////////////////

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

/** Robot type declarations **/
namespace runtime {
namespace robots {
constexpr char iiwa_name[] = "ctup_runtime::robots::iiwa";
constexpr char hyq_name[] = "ctup_runtime::robots::hyq";
constexpr char baxter_name[] = "ctup_runtime::robots::baxter";

using iiwa = typename builder::name<iiwa_name>;
using hyq = typename builder::name<hyq_name>;
using baxter = typename builder::name<baxter_name>;
}

constexpr char configuration_block_name[] = "ctup_runtime::ConfigurationBlock";
template <typename RobotT>
using configuration_block_t = typename builder::name<configuration_block_name, RobotT, blaze_avx256f>;

builder::dyn_var<void (
    size_t flattened_idx,
    blaze_avx256f&, ctup::EigenMatrixXd&
        )> map_blaze_avxtype_to_eigen_batch_dim = builder::as_global("ctup_runtime::map_blaze_avxtype_to_eigen_batch_dim");
}

template <typename Xform>
static void toRawMatrix(Xform &xform, dyn_var<ctup::EigenMatrixXd&> &raw_mat) {
  static_var<int> r, c;

  for (r = 0; r < 6; r = r + 1) {
    for (c = 0; c < 6; c = c + 1) {
      if (xform.is_nonzero(r, c))
        runtime::map_blaze_avxtype_to_eigen_batch_dim(r*6 + c, xform.get_entry(r, c), raw_mat);
    }
  }
}

/** helpers end **/

template <typename Xform>
static void set_X_T(builder::array<Xform> &X_T, const Model &model) {
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

/////////////////////////////////////////////
////////////   FK IMPLEMENTATIONS  //////////
/////////////////////////////////////////////

// FK with only trace-time sparsity (TT)
template <typename RobotT>
static void batched_fk_tt(
    const Model &model,
    dyn_var<const runtime::configuration_block_t<RobotT>&> q,
    dyn_var<ctup::EigenMatrixXd&> result)
{
  typedef typename Model::JointIndex JointIndex;

  builder::array<ctup::XformTT<blaze_avx256f>> X_T;
  builder::array<ctup::XformTT<blaze_avx256f>> X_J;
  builder::array<ctup::XformTT<blaze_avx256f>> X_0;

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

  ctup::XformTT<blaze_avx256f> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::matrix_layout_expr_leaf<blaze_avx256f>(X_pi);
    }
  }

  toRawMatrix(X_0[model.njoints-1], result);
}

// FK with only compile-time structure (CT)
template <typename RobotT>
static void batched_fk_ct(
    const Model &model,
    dyn_var<const runtime::configuration_block_t<RobotT>&> q,
    dyn_var<ctup::EigenMatrixXd&> result)
{
  typedef typename Model::JointIndex JointIndex;

  builder::array<ctup::XformBlockedCT<blaze_avx256f>> X_T;
  builder::array<ctup::XformBlockedCT<blaze_avx256f>> X_J;
  builder::array<ctup::XformBlockedCT<blaze_avx256f>> X_0;

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

  ctup::XformBlockedCT<blaze_avx256f> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::blocked_layout_expr_leaf<blaze_avx256f>(X_pi);
    }
  }

  toRawMatrix(X_0[model.njoints-1], result);
}

// FK with neither CT structure nor TT sparsity
template <typename RobotT>
static void batched_fk_no_ct_no_tt(
    const Model &model,
    dyn_var<const runtime::configuration_block_t<RobotT>&> q,
    dyn_var<ctup::EigenMatrixXd&> result)
{
  typedef typename Model::JointIndex JointIndex;

  builder::array<ctup::XformNoCTNoTT<blaze_avx256f>> X_T;
  builder::array<ctup::XformNoCTNoTT<blaze_avx256f>> X_J;
  builder::array<ctup::XformNoCTNoTT<blaze_avx256f>> X_0;

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

  ctup::XformNoCTNoTT<blaze_avx256f> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::matrix_layout_expr_leaf<blaze_avx256f>(X_pi);
    }
  }

  toRawMatrix(X_0[model.njoints-1], result);
}

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program("batched_rla_fk_ct_tt_study");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("-o", "--output")
      .default_value(std::string("./fk_gen.h"))
      .help("output header file path");

  program.add_argument("-r", "--robot")
      .required()
      .help("robot name (iiwa, hyq, baxter)");

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
  std::string robot_name = program.get<std::string>("--robot");

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Output header: " << header_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  std::string namespace_name = "ctup_gen_" + robot_name;

  of << "// clang-format off\n\n";
  of << "#include \"Eigen/Dense\"\n";
  of << "#include \"blaze/Math.h\"\n";
  of << "#include \"rla_fk_ct_tt_study/runtime/utils.h\"\n\n";
  of << "namespace " << namespace_name << " {\n\n";


  // Generate all 3 variants for the specified robot
  if (robot_name == "iiwa") {
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_ct<runtime::robots::iiwa>, "batched_fk_ct", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n\n";
    }
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_tt<runtime::robots::iiwa>, "batched_fk_tt", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n\n";
    }
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_no_ct_no_tt<runtime::robots::iiwa>, "batched_fk_no_ct_no_tt", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n";
    }
  } 
  else if (robot_name == "hyq") {
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_ct<runtime::robots::hyq>, "batched_fk_ct", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n\n";
    }
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_tt<runtime::robots::hyq>, "batched_fk_tt", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n\n";
    }
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_no_ct_no_tt<runtime::robots::hyq>, "batched_fk_no_ct_no_tt", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n";
    }
  }
  else if (robot_name == "baxter") {
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_ct<runtime::robots::baxter>, "batched_fk_ct", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n\n";
    }
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_tt<runtime::robots::baxter>, "batched_fk_tt", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n\n";
    }
    {
      builder::builder_context context;
      context.run_rce = true;
      auto ast = context.extract_function_ast(batched_fk_no_ct_no_tt<runtime::robots::baxter>, "batched_fk_no_ct_no_tt", model);
      of << "static ";
      block::c_code_generator::generate_code(ast, of, 0);
      of << "\n";
    }
  } 
  else {
    std::cerr << "Unknown robot: " << robot_name << "\n";
    return 1;
  }

  of << "}\n";
}
