// ./build/sample9 ./deps/pinocchio/models/baxter_simple.urdf ../ctup-experiments/gen/fk_gen_unrolled.h
#include "xform_layouts.h"
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
#include <string>
#include <argparse/argparse.hpp>

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;

/** helpers **/

template <typename Scalar>
using Xform = ctup::XformBlocked<Scalar>;

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

static dyn_var<EigenMatrix<double, 6, 6>> fk(const Model &model, dyn_var<ctup::EigenVectorXd &> q) {
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

  Xform<double> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q(i-1));

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::blocked_layout_expr_leaf<double>(X_pi);
      //X_0[i] = ctup::matrix_layout_expr_leaf<double>(X_pi);
    }
  }

  // CTUP debug
  //for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
  //  if (i <= 4) {
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
  argparse::ArgumentParser program("scalar_rla_fk");

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
  const std::string robot_name = program.get<std::string>("--robot");

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Output header: " << header_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  // Generate unique namespace per robot
  std::string namespace_name = "ctup_gen_" + robot_name;

  of << "#include \"Eigen/Dense\"\n";
  of << "#include \"rla_fk/runtime/utils.h\"\n\n";
  of << "namespace " << namespace_name << " {\n\n";

  of << "using ctup_runtime::print_string;\n";
  of << "using ctup_runtime::print_matrix;\n\n";

  builder::builder_context context;

  auto ast = context.extract_function_ast(fk, "fk", model);
  of << "static ";
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
