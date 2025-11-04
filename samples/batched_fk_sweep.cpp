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
using ctup::backend::vamp_avx256f;

builder::dyn_var<void(BlazeStaticMatrix<double> &)> print_matrix = builder::as_global("print_matrix");

builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

namespace runtime {
namespace robots {

struct iiwa {
  static const size_t dof = 7;
};
struct HyQ {
  static const size_t dof = 12;
};
struct Baxter {
  static const size_t dof = 14;
};
struct Synth12 {
  static const size_t dof = 12;
};
}

template <typename RobotT>
using vamp_config_block_t = typename ctup::VampFloatVector<8, RobotT::dof>;

builder::dyn_var<void (
    size_t flattened_idx,
    vamp_avx256f&, ctup::EigenMatrixXd&
        )> map_vamp_vector_to_eigen_batch_dim = builder::as_global("ctup_runtime::map_vamp_vector_to_eigen_batch_dim");

} // namespace runtime


static void toRawMatrix(Xform<vamp_avx256f> &xform, dyn_var<ctup::EigenMatrixXd&> &raw_mat) {
  static_var<int> r, c;

  for (r = 0; r < 6; r = r + 1) {
    for (c = 0; c < 6; c = c + 1) {
      if (xform.is_nonzero(r, c))
        runtime::map_vamp_vector_to_eigen_batch_dim(r*6 + c, xform.get_entry(r, c), raw_mat);
    }
  }
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

// computes forward kinematics for 8 robot configurations at once (batch size = 8)
// returns:
// result: (batch_size, 36)
// with 36 entries of each X matrix laid out in row-major order
template <typename RobotT>
static void batched_fk_vamp(
    const Model &model,
    dyn_var<const runtime::vamp_config_block_t<RobotT>&> q,
    dyn_var<ctup::EigenMatrixXd&> result)
{
  typedef typename Model::JointIndex JointIndex;

  builder::array<Xform<vamp_avx256f>> X_T;
  builder::array<Xform<vamp_avx256f>> X_J;
  builder::array<Xform<vamp_avx256f>> X_0;

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

  Xform<vamp_avx256f> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      //X_0[i] = ctup::matrix_layout_expr_leaf<vamp_avx256f>(X_pi);
      X_0[i] = ctup::blocked_layout_expr_leaf<vamp_avx256f>(X_pi);
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

  toRawMatrix(X_0[model.njoints-1], result);
}

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program("batched_fk_sweep");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("-o", "--output")
      .default_value(std::string("./fk_gen.h"))
      .help("output header file path");

  program.add_argument("-r", "--robot")
      .required()
      .help("robot name (iiwa, hyq, baxter, synth_12)");

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
  std::string namespace_name;
  if (robot_name == "synth_12") {
    // Extract filename without path and extension for synth_12 robots
    size_t last_slash = urdf_filename.find_last_of("/\\");
    size_t last_dot = urdf_filename.find_last_of(".");
    std::string base_filename = urdf_filename.substr(last_slash + 1, last_dot - last_slash - 1);
    namespace_name = "ctup_gen_" + base_filename;
  } else {
    namespace_name = "ctup_gen_" + robot_name;
  }

  of << "// clang-format off\n\n";
  of << "#include \"rla_fk_intrin/runtime/utils.h\"\n\n";
  of << "namespace " << namespace_name << " {\n\n";

  builder::builder_context context;
  context.run_rce = true;

  // Instantiate batched_fk_vamp function based on robot type
  if (robot_name == "iiwa") {
    auto ast = context.extract_function_ast(batched_fk_vamp<runtime::robots::iiwa>, "batched_fk_vamp", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  }
  else if (robot_name == "hyq") {
    auto ast = context.extract_function_ast(batched_fk_vamp<runtime::robots::HyQ>, "batched_fk_vamp", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  }
  else if (robot_name == "baxter") {
    auto ast = context.extract_function_ast(batched_fk_vamp<runtime::robots::Baxter>, "batched_fk_vamp", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  }
  else if (robot_name == "synth_12") {
    auto ast = context.extract_function_ast(batched_fk_vamp<runtime::robots::Synth12>, "batched_fk_vamp", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  }
  else {
    std::cerr << "Unknown robot: " << robot_name << "\n";
    return 1;
  }

  of << "}\n";
}
