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

/////////// Prims with varying batch size ////////////////

template <size_t BatchSize>
using blaze_sv_f = BlazeStaticVector<float, BatchSize>;

/////////////////////////////////////////////////////////

builder::dyn_var<void(BlazeStaticMatrix<double> &)> print_matrix = builder::as_global("print_matrix");

builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

/** Robot type declarations **/
namespace runtime {
namespace robots {
constexpr char iiwa_name[] = "ctup_runtime::robots::iiwa";
constexpr char hyq_name[] = "ctup_runtime::robots::hyq";
constexpr char baxter_name[] = "ctup_runtime::robots::baxter";
constexpr char synth_12_name[] = "ctup_runtime::robots::synth_12";

using iiwa = typename builder::name<iiwa_name>;
using hyq = typename builder::name<hyq_name>;
using baxter = typename builder::name<baxter_name>;
using synth_12 = typename builder::name<synth_12_name>;
}

constexpr char configuration_block_name[] = "ctup_runtime::ConfigurationBlock";
template <typename RobotT, typename Prim>
using configuration_block_t = typename builder::name<configuration_block_name, RobotT, Prim>;

template <typename Prim>
builder::dyn_var<void (
    size_t flattened_idx,
    Prim&, ctup::EigenMatrixXd&
        )> map_blaze_avxtype_to_eigen_batch_dim = builder::as_global("ctup_runtime::map_blaze_avxtype_to_eigen_batch_dim");
}

template <typename Prim>
static void toRawMatrix(Xform<Prim> &xform, dyn_var<ctup::EigenMatrixXd&> &raw_mat) {
  static_var<int> r, c;

  for (r = 0; r < 6; r = r + 1) {
    for (c = 0; c < 6; c = c + 1) {
      if (xform.is_nonzero(r, c))
        runtime::map_blaze_avxtype_to_eigen_batch_dim<Prim>(r*6 + c, xform.get_entry(r, c), raw_mat);
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
template <typename RobotT, typename Prim>
static void batched_fk(
    const Model &model,
    dyn_var<const runtime::configuration_block_t<RobotT, Prim>&> q,
    dyn_var<ctup::EigenMatrixXd&> result)
{
  typedef typename Model::JointIndex JointIndex;

  builder::array<Xform<Prim>> X_T;
  builder::array<Xform<Prim>> X_J;
  builder::array<Xform<Prim>> X_0;

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

  Xform<Prim> X_pi;

  static_var<JointIndex> parent;
  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      //X_0[i] = ctup::matrix_layout_expr_leaf<Prim>(X_pi);
      X_0[i] = ctup::blocked_layout_expr_leaf<Prim>(X_pi);
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
  argparse::ArgumentParser program("batched_fk_batch_size_sweep");

  program.add_argument("urdf")
      .help("path to the URDF file");

  program.add_argument("-o", "--output")
      .default_value(std::string("./fk_gen.h"))
      .help("output header file path");

  program.add_argument("-r", "--robot")
      .required()
      .help("robot name (iiwa, hyq, baxter)");

  program.add_argument("-b", "--batch_size")
      .default_value(8)
      .scan<'i', int>()
      .help("batch size (4, 8, 16, 32)");

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
  int batch_size = program.get<int>("--batch_size");

  std::cout << "URDF file: " << urdf_filename << "\n";
  std::cout << "Output header: " << header_filename << "\n";
  std::cout << "Robot: " << robot_name << "\n";
  std::cout << "Batch size: " << batch_size << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  // Generate unique namespace per robot
  // For synth_12, extract namespace from URDF filename
  std::string namespace_name;
  if (robot_name == "synth_12") {
    size_t last_slash = urdf_filename.find_last_of("/\\");
    size_t last_dot = urdf_filename.find_last_of(".");
    std::string base_filename = urdf_filename.substr(last_slash + 1, last_dot - last_slash - 1);
    namespace_name = "ctup_gen_" + base_filename;
  } else {
    namespace_name = "ctup_gen_" + robot_name;
  }

  of << "// clang-format off\n\n";
  of << "#include \"Eigen/Dense\"\n";
  of << "#include \"blaze/Math.h\"\n";
  of << "#include \"rla_fk_batch_size_sweep/runtime/utils.h\"\n\n";
  of << "namespace " << namespace_name << " {\n\n";

  of << "using ctup_runtime::print_string;\n";
  of << "using ctup_runtime::print_matrix;\n\n";

  builder::builder_context context;
  context.run_rce = true;

  // Macro to generate code for a given robot and batch size
  #define GENERATE_FOR_ROBOT_AND_BATCH(RobotType, BatchSize) \
    do { \
      auto ast = context.extract_function_ast( \
          batched_fk<runtime::robots::RobotType, blaze_sv_f<BatchSize>>, \
          "batched_fk", model); \
      of << "static "; \
      block::c_code_generator::generate_code(ast, of, 0); \
    } while(0)

  // Instantiate batched_fk function based on robot type and batch size
  if (robot_name == "iiwa") {
    if (batch_size == 4) {
      GENERATE_FOR_ROBOT_AND_BATCH(iiwa, 4);
    } else if (batch_size == 8) {
      GENERATE_FOR_ROBOT_AND_BATCH(iiwa, 8);
    } else if (batch_size == 16) {
      GENERATE_FOR_ROBOT_AND_BATCH(iiwa, 16);
    } else if (batch_size == 32) {
      GENERATE_FOR_ROBOT_AND_BATCH(iiwa, 32);
    } else {
      std::cerr << "Unsupported batch size: " << batch_size << "\n";
      return 1;
    }
  } else if (robot_name == "hyq") {
    if (batch_size == 4) {
      GENERATE_FOR_ROBOT_AND_BATCH(hyq, 4);
    } else if (batch_size == 8) {
      GENERATE_FOR_ROBOT_AND_BATCH(hyq, 8);
    } else if (batch_size == 16) {
      GENERATE_FOR_ROBOT_AND_BATCH(hyq, 16);
    } else if (batch_size == 32) {
      GENERATE_FOR_ROBOT_AND_BATCH(hyq, 32);
    } else {
      std::cerr << "Unsupported batch size: " << batch_size << "\n";
      return 1;
    }
  } else if (robot_name == "baxter") {
    if (batch_size == 4) {
      GENERATE_FOR_ROBOT_AND_BATCH(baxter, 4);
    } else if (batch_size == 8) {
      GENERATE_FOR_ROBOT_AND_BATCH(baxter, 8);
    } else if (batch_size == 16) {
      GENERATE_FOR_ROBOT_AND_BATCH(baxter, 16);
    } else if (batch_size == 32) {
      GENERATE_FOR_ROBOT_AND_BATCH(baxter, 32);
    } else {
      std::cerr << "Unsupported batch size: " << batch_size << "\n";
      return 1;
    }
  } else if (robot_name == "synth_12") {
    if (batch_size == 4) {
      GENERATE_FOR_ROBOT_AND_BATCH(synth_12, 4);
    } else if (batch_size == 8) {
      GENERATE_FOR_ROBOT_AND_BATCH(synth_12, 8);
    } else if (batch_size == 16) {
      GENERATE_FOR_ROBOT_AND_BATCH(synth_12, 16);
    } else if (batch_size == 32) {
      GENERATE_FOR_ROBOT_AND_BATCH(synth_12, 32);
    } else {
      std::cerr << "Unsupported batch size: " << batch_size << "\n";
      return 1;
    }
  } else {
    std::cerr << "Unknown robot: " << robot_name << "\n";
    return 1;
  }

  #undef GENERATE_FOR_ROBOT_AND_BATCH

  of << "}\n";
}
