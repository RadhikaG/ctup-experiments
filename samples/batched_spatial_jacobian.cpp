// ignore unused header warning in IDE, this is needed
#include "matrix_layout.h"
#include "pinocchio/multibody/joint/joint-collection.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/collision/collision.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <coal/collision_object.h>
#include <coal/shape/geometric_shapes.h>
#include <memory>
#include <ostream>
#include <pinocchio/multibody/fwd.hpp>
#include <pinocchio/multibody/geometry.hpp>
#include <pinocchio/spatial/fwd.hpp>
#include <string>
#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <iostream>
#include <argparse/argparse.hpp>

#include "blocks/block_visitor.h"
#include "blocks/c_code_generator.h"
#include "builder/builder_base.h"
#include "builder/builder_context.h"
#include "builder/dyn_var.h"
#include "builder/forward_declarations.h"
#include "builder/static_var.h"
#include "builder/lib/utils.h"
#include "builder/array.h"

#include "matrix_layout_composite.h"
#include "matrix_operators.h"
#include "jacobian_layouts.h"
#include "backend.h"

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;

using ctup::backend::blaze_avx256f;

/////////////////////////////////////////////

using ctup::Xform;
using ctup::SingletonSpatialVector;
using ctup::SpatialVector;

/////////////////////////////////////////////
///// DEBUG HELPERS

builder::dyn_var<void(ctup::BlazeStaticMatrix<float> &)> print_matrix = builder::as_global("print_matrix");
builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

template <typename Scalar>
static void print_Xmat(std::string prefix, Xform<Scalar> &xform) {
  print_string(prefix.c_str());
  print_matrix(xform.denseify());
}

/////////////////////////////////////////////

namespace runtime {

namespace robots {
constexpr char panda_name[] = "rla_jac_runtime::robots::Panda";
constexpr char iiwa_name[] = "rla_jac_runtime::robots::iiwa";
constexpr char hyq_name[] = "rla_jac_runtime::robots::Hyq";
constexpr char baxter_name[] = "rla_jac_runtime::robots::Baxter";

using Panda = typename builder::name<panda_name>;
using iiwa = typename builder::name<iiwa_name>;
using Hyq = typename builder::name<hyq_name>;
using Baxter = typename builder::name<baxter_name>;
}

constexpr char configuration_block_robot_name[] = "rla_jac_runtime::ConfigurationBlockRobot";
template <typename RobotT>
using configuration_block_robot_t = typename builder::name<configuration_block_robot_name, RobotT>;

builder::dyn_var<void (
    size_t flattened_idx,
    blaze_avx256f&, ctup::EigenMatrixXd&
        )> map_blaze_avxtype_to_eigen_batch_dim = builder::as_global("rla_jac_runtime::map_blaze_avxtype_to_eigen_batch_dim");
}

/////////////////////////////////////////////

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

static void set_X_T(builder::array<Xform<blaze_avx256f>>& X_T, const Model &model) {
  typedef typename Model::JointIndex JointIndex;
  static_var<JointIndex> i;

  static_var<size_t> r;
  static_var<size_t> c;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    // todo: understand what the heck is this outputing
    // for homogeneous transforms
    Eigen::Matrix<double, 4, 4> pin_X_T = model.jointPlacements[i].toHomogeneousMatrix();

    // setting E
    for (r = 0; r < 4; r = r + 1) {
      for (c = 0; c < 4; c = c + 1) {
        float entry = pin_X_T.coeffRef(r, c);
        if (std::abs(entry) < 1e-5)
          X_T[i].set_entry_to_constant(r, c, 0);
        else
          X_T[i].set_entry_to_constant(r, c, entry);
      }
    }
  }
}

static bool is_joint_ancestor(
    const pinocchio::Model &model, 
    size_t ancestor, size_t descendant) {
  size_t parent = descendant;
  // joint 0 is "universe"
  while (parent != 0) {
    if (parent == ancestor)
      return true;
    parent = model.parents[parent];
  }
  return false;
}


// computes EEF jacobian for 8 robot configurations at once (batch size = 8)
// returns:
// jacobian: shape: (batch_size, 6 * njoints)
template <typename RobotT>
static void batched_jac(
    const pinocchio::Model &model,
    dyn_var<const runtime::configuration_block_robot_t<RobotT>&> q,
    // modifies jac by reference
    dyn_var<ctup::EigenMatrixXd&> jac) 
{

  typedef typename Model::JointIndex JointIndex;

  // joint transforms for FK
  builder::array<Xform<blaze_avx256f>> X_T;
  builder::array<Xform<blaze_avx256f>> X_J;
  builder::array<Xform<blaze_avx256f>> X_0;

  X_T.set_size(model.njoints);
  X_J.set_size(model.njoints);
  X_0.set_size(model.njoints);

  ////////// for spatial jacobian /////////////////
  builder::array<SingletonSpatialVector<blaze_avx256f>> S;
  S.set_size(model.njoints);

  ctup::Adjoint<blaze_avx256f> adj;
  SpatialVector<blaze_avx256f> S_world;
  ///////////////////////////////////////////////


  static_var<JointIndex> i, j;

  set_X_T(X_T, model);

  static_var<int> jtype;
  static_var<int> axis;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    jtype = get_jtype(model, i);
    axis = get_joint_axis(model, i);

    if (jtype == 'R') {
      X_J[i].set_revolute_axis(axis);
      S[i].set_revolute_axis(axis);
    }
    if (jtype == 'P') {
      X_J[i].set_prismatic_axis(axis);
      S[i].set_prismatic_axis(axis);
    }
  }

  Xform<blaze_avx256f> X_pi;

  static_var<JointIndex> parent;
  std::string joint_name;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    // todo: figure out why standard featherstone matmul
    // ordering not working with X_T from pinocchio
    //X_pi = X_J[i] * X_T[i]; // feath
    X_pi = X_T[i] * X_J[i]; // pin
    parent = model.parents[i];
    if (parent > 0) {
      //X_0[i] = X_pi * X_0[parent]; // feath
      X_0[i] = X_0[parent] * X_pi; // pin
    }
    else {
      X_0[i] = ctup::blocked_layout_expr_leaf<blaze_avx256f>(X_pi);
    }

    //////////// Spatial jacobian for last joint ///////////
    if (i == (size_t)model.njoints-1) {
      for (j = 1; j < (JointIndex)model.njoints; j = j+1) {
        if (!is_joint_ancestor(model, j, i)) {
            continue;
        }
        // since we know j is ancestor of i,
        // X_0[j] is guaranteed to have been
        // calculated already.
        adj.set_rotation_and_translation(X_0[j].get_rotation(), X_0[j].get_translation());

        S_world = adj * S[j];

        for (static_var<size_t> r = 0; r < 6; r = r + 1) {
          // j-1 because j=0 is universe joint
          // jac storage convention is:
          // jac(batch_dim, r * model.nv + c), where (r,c) are the 2D indices of
          // a vanilla jacobian matrix.
          // r * model.nv + c is a flattened index
          runtime::map_blaze_avxtype_to_eigen_batch_dim((size_t)(r * (size_t)model.nv + j-1), 
                  S_world.get_entry(r, 0), jac);
        }
      }
    }
    ////////////////////////////////////////////////
  }
}

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program("batched_spatial_jacobian");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("-o", "--output")
      .default_value(std::string("./jac_gen.h"))
      .help("output header file path");

  program.add_argument("-r", "--robot")
      .required()
      .help("robot name (panda, iiwa, hyq, baxter)");

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
  std::string namespace_name = "rla_jac_gen_" + robot_name;

  of << "// clang-format off\n\n";
  of << "#include \"Eigen/Dense\"\n";
  of << "#include \"blaze/Math.h\"\n";
  of << "#include \"rla_spatial_jacobian/runtime/utils.h\"\n\n";
  of << "namespace " << namespace_name << " {\n\n";

  of << "using rla_jac_runtime::print_string;\n";
  of << "using rla_jac_runtime::print_matrix;\n\n";

  builder::builder_context context;
  context.run_rce = true;

  // Instantiate batched_jac function based on robot type
  if (robot_name == "panda") {
    auto ast = context.extract_function_ast(batched_jac<runtime::robots::Panda>, "batched_jac", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  } else if (robot_name == "iiwa") {
    auto ast = context.extract_function_ast(batched_jac<runtime::robots::iiwa>, "batched_jac", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  } else if (robot_name == "hyq") {
    auto ast = context.extract_function_ast(batched_jac<runtime::robots::Hyq>, "batched_jac", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  } else if (robot_name == "baxter") {
    auto ast = context.extract_function_ast(batched_jac<runtime::robots::Baxter>, "batched_jac", model);
    of << "static ";
    block::c_code_generator::generate_code(ast, of, 0);
  } else {
    std::cerr << "Unknown robot: " << robot_name << "\n";
    return 1;
  }

  of << "}\n";
}

