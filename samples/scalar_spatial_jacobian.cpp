// ignore unused header warning in IDE, this is needed
#include "matrix_layout.h"
#include "jacobian_layouts.h"

#include "pinocchio/multibody/joint/joint-collection.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <coal/collision_object.h>
#include <coal/shape/geometric_shapes.h>
#include <memory>
#include <pinocchio/multibody/fwd.hpp>
#include <pinocchio/multibody/geometry.hpp>
#include <pinocchio/spatial/fwd.hpp>
#include <string>
#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <iostream>
#include <map>

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
#include "backend.h"

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;

using ctup::EigenMatrix;
using ctup::matrix_layout;

using ctup::backend::blaze_avx256f;

/////////////////////////////////////////////

using ctup::Xform;
using ctup::SingletonSpatialVector;
using ctup::SpatialVector;

/////////////////////////////////////////////
///// DEBUG HELPERS

builder::dyn_var<void(ctup::BlazeStaticMatrix<float> &)> print_matrix = builder::as_global("print_matrix");
builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

template <typename MatType>
static void print_mat(std::string prefix, MatType &mat) {
  print_string(prefix.c_str());
  print_matrix(mat.denseify());
}

/////////////////////////////////////////////

namespace runtime {

namespace robots {
constexpr char robots_ur5_name[] = "ctup_runtime::robots::UR5";
using UR5 = typename builder::name<robots_ur5_name>;

constexpr char robots_panda_name[] = "ctup_runtime::robots::Panda";
using Panda = typename builder::name<robots_panda_name>;

constexpr char robots_baxter_name[] = "ctup_runtime::robots::Baxter";
using Baxter = typename builder::name<robots_baxter_name>;

constexpr char robots_fetch_name[] = "ctup_runtime::robots::Fetch";
using Fetch = typename builder::name<robots_fetch_name>;
}

constexpr char environment_t_name[] = "vamp::collision::Environment";
template <typename DataT>
using environment_t = typename builder::name<environment_t_name, DataT>;

constexpr char configuration_block_robot_name[] = "ctup_runtime::ConfigurationBlockRobot";
template <typename RobotT>
using configuration_block_robot_t = typename builder::name<configuration_block_robot_name, RobotT>;

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

template <typename Scalar>
static void set_X_T(builder::array<Xform<Scalar>>& X_T, const Model &model) {
  typedef typename Model::JointIndex JointIndex;
  static_var<JointIndex> i;

  static_var<size_t> r;
  static_var<size_t> c;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    // todo: understand what the heck is this outputing
    // for homogeneous transforms
    Eigen::Matrix<double, 4, 4> pin_X_T = model.jointPlacements[i].toHomogeneousMatrix();

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


static dyn_var<int> get_eef_world_jacobian(
    const pinocchio::Model &model, 
    dyn_var<ctup::EigenVectorXd &> q) {

  typedef typename Model::JointIndex JointIndex;
  const JointIndex njoints = (JointIndex)model.njoints;

  // joint transforms for FK
  builder::array<Xform<double>> X_T;
  builder::array<Xform<double>> X_J;
  builder::array<Xform<double>> X_0;

  X_T.set_size(model.njoints);
  X_J.set_size(model.njoints);
  X_0.set_size(model.njoints);

  builder::array<SingletonSpatialVector<double>> S;
  S.set_size(model.njoints);

  // if desired output: all jacobians
  // logical layout:
  // [ ] : 6 rows (i), njoints cols (j)
  // ... njoints matrices (k)
  // storage layout:
  // i*k rows, j cols
  //matrix_layout<double> J(6 * model.njoints, model.njoints, ctup::DENSE, ctup::EIGENMATRIX, ctup::UNCOMPRESSED);

  // joint 0 is "universe"
  matrix_layout<double> J(6, model.njoints-1, ctup::DENSE, ctup::EIGENMATRIX, ctup::UNCOMPRESSED);

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

  Xform<double> X_pi;

  ctup::Adjoint<double> adj;
  SpatialVector<double> S_world;

  static_var<JointIndex> parent;
  std::string joint_name;

  for (i = 1; i < njoints; i = i+1) {
    // FK calculatiion
    X_J[i].jcalc(q(i-1));

    //X_pi = X_J[i] * X_T[i]; // feath
    X_pi = X_T[i] * X_J[i]; // pin
    parent = model.parents[i];
    if (parent > 0) {
      //X_0[i] = X_pi * X_0[parent]; // feath
      X_0[i] = X_0[parent] * X_pi; // pin
    }
    else {
      X_0[i] = ctup::blocked_layout_expr_leaf<double>(X_pi);
    }

    // generating jacobian matrix for last joint
    // todo: add joint name as arg
    if (i == njoints-1) {
      for (j = 1; j < njoints; j = j+1) {
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
          J.set_entry_to_nonconstant(r, j-1, S_world.get_entry(r, 0));
        }
      }
      break;
    }
  }

  return J.denseify();
}

int main(int argc, char* argv[]) {
  const std::string urdf_filename = argv[1];
  std::cout << urdf_filename << "\n";

  const std::string header_filename = (argc <= 2) ? "./jac_gen.h" : argv[2];
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
  context.run_rce = true;

  auto ast = context.extract_function_ast(get_eef_world_jacobian, "get_eef_world_jacobian", model);
  of << "static ";
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}

