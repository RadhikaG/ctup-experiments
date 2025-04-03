// ./build/sample10 ./deps/pinocchio/models/baxter_simple.urdf ../ctup-experiments/gen/rnea_gen_unrolled.h
#include "matrix_layout.h"
#include "rnea_layouts.h"
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
#include "builder/array.h"

// ignore unused header warning in IDE, this is needed
#include "pinocchio/multibody/joint/joint-collection.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <Eigen/src/Core/util/ForwardDeclarations.h>
#include <string>

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;
using ctup::EigenMatrix;
using ctup::matrix_layout;

/** helpers **/

builder::dyn_var<void(EigenMatrix<double> &)> print_matrix = builder::as_global("print_matrix");
builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

template <typename Scalar, int Rows_, int Cols_>
static void toPinEigen(dyn_var<EigenMatrix<Scalar, Rows_, Cols_>> &mat, matrix_layout<Scalar> &mat_layout) {
  static_var<int> r, c;

  for (r = 0; r < Rows_; r = r + 1)
    for (c = 0; c < Cols_; c = c + 1)
      mat.coeffRef(r, c) = mat_layout.get_entry(c, r);
}

template <typename Scalar>
static void print_matrix_layout(std::string prefix, matrix_layout<Scalar> &mat_layout) {
  print_string(prefix.c_str());
  print_matrix(mat_layout.denseify());
}

template <typename Scalar>
static void print_matrix_layout_pin(std::string prefix, matrix_layout<Scalar> &mat_layout) {
  print_string(prefix.c_str());
  dyn_var<EigenMatrix<Scalar>> mat;
  mat.set_matrix_fixed_size(mat_layout.shape[0], mat_layout.shape[1]);
  toPinEigen(mat, mat_layout);
  print_matrix(mat);
}

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

//using ctup::Xform;
template <typename Scalar>
using Xform = ctup::XformNonBlocked<Scalar>;

using ctup::SpatialInertia;
using ctup::SpatialVector;
using ctup::SingletonSpatialVector;

template <typename T>
struct vector: public builder::custom_type<T> {
  static constexpr const char* type_name = "std::vector";
  typedef T dereference_type;
  dyn_var<void(int)> resize = builder::with_name("resize");
};

struct robot_data {
  static constexpr const char* type_name = "robot_data";
  dyn_var<vector<builder::eigen_vectorXd_t>> v = builder::with_name("v");
  dyn_var<vector<builder::eigen_vectorXd_t>> a = builder::with_name("a");
  dyn_var<vector<builder::eigen_vectorXd_t>> f = builder::with_name("f");
  dyn_var<builder::eigen_vectorXd_t> tau = builder::with_name("tau");
};

static void init_rd(static_var<size_t> N, dyn_var<robot_data*> rd) {
  rd->v.resize(N);
  rd->a.resize(N);
  rd->f.resize(N);
  for (dyn_var<size_t> i = 0; i < N; i = i+1) {
    rd->v[i].setZero();
    rd->a[i].setZero();
    rd->f[i].setZero();
  }
}

/** helpers end **/

template <typename Scalar>
static void set_fixed_transforms_inertias(builder::array<Xform<Scalar>> &X_T, 
        builder::array<SpatialInertia<Scalar>> &I, const Model &model) {
  typedef typename Model::JointIndex JointIndex;

  static_var<int> r;
  static_var<int> c;

  double entry;

  for (static_var<size_t> i = 1; i < (JointIndex)model.njoints; i = i+1) {
    Eigen::Matrix<double, 6, 6> pin_X_T = model.jointPlacements[i];
    Eigen::Matrix<double, 6, 6> pin_I = model.inertias[i];

    Eigen::Matrix<double, 6, 6> mod_I;
    mod_I.topLeftCorner(3,3) = pin_I.bottomRightCorner(3,3);
    mod_I.bottomLeftCorner(3,3) = pin_I.topRightCorner(3,3);
    mod_I.bottomRightCorner(3,3) = pin_I.topLeftCorner(3,3);
    mod_I.topRightCorner(3,3) = pin_I.bottomLeftCorner(3,3);

    for (r = 0; r < 6; r = r + 1) {
      for (c = 0; c < 6; c = c + 1) {
        entry = pin_X_T.coeffRef(c, r);
        X_T[i].set_entry_to_constant(r, c, entry);

        entry = mod_I.coeffRef(r, c);
        I[i].set_entry_to_constant(r, c, entry);
      }
    }
  }
}

static void mxS(SpatialVector<double> &mxSvec, const SingletonSpatialVector<double> &S, 
        const SpatialVector<double> &vec, const dyn_var<double> &alpha) {
  mxSvec.set_zero();
  if (S.get_constant_entry(0, 0) == 1) {
    mxSvec.set_entry_to_nonconstant(1, 0, vec.get_entry(2,0) * alpha);
    mxSvec.set_entry_to_nonconstant(2, 0, -vec.get_entry(1,0) * alpha);
    mxSvec.set_entry_to_nonconstant(4, 0, vec.get_entry(5,0) * alpha);
    mxSvec.set_entry_to_nonconstant(5, 0, -vec.get_entry(4,0) * alpha);
  }
  else if (S.get_constant_entry(1, 0) == 1) {
    mxSvec.set_entry_to_nonconstant(0, 0, -vec.get_entry(2,0) * alpha);
    mxSvec.set_entry_to_nonconstant(2, 0, vec.get_entry(0,0) * alpha);
    mxSvec.set_entry_to_nonconstant(3, 0, -vec.get_entry(5,0) * alpha);
    mxSvec.set_entry_to_nonconstant(5, 0, vec.get_entry(3,0) * alpha);
  }
  else if (S.get_constant_entry(2, 0) == 1) {
    mxSvec.set_entry_to_nonconstant(0, 0, vec.get_entry(1,0) * alpha);
    mxSvec.set_entry_to_nonconstant(1, 0, -vec.get_entry(0,0) * alpha);
    mxSvec.set_entry_to_nonconstant(3, 0, vec.get_entry(4,0) * alpha);
    mxSvec.set_entry_to_nonconstant(4, 0, -vec.get_entry(3,0) * alpha);
  }
  else if (S.get_constant_entry(3, 0) == 1) {
    mxSvec.set_entry_to_nonconstant(4, 0, vec.get_entry(2,0) * alpha);
    mxSvec.set_entry_to_nonconstant(5, 0, -vec.get_entry(1,0) * alpha);
  }
  else if (S.get_constant_entry(4, 0) == 1) {
    mxSvec.set_entry_to_nonconstant(3, 0, -vec.get_entry(2,0) * alpha);
    mxSvec.set_entry_to_nonconstant(5, 0, vec.get_entry(0,0) * alpha);
  }
  else if (S.get_constant_entry(5, 0) == 1) {
    mxSvec.set_entry_to_nonconstant(3, 0, vec.get_entry(1,0) * alpha);
    mxSvec.set_entry_to_nonconstant(4, 0, -vec.get_entry(0,0) * alpha);
  }
}

static void vxIv(SpatialVector<double> &vecXIvec, SpatialVector<double> &vec, SpatialInertia<double> &I) {
  matrix_layout<double> temp(6, 1, ctup::DENSE, ctup::EIGENMATRIX, ctup::UNCOMPRESSED);
  temp.set_zero();
  temp = I * vec;
  dyn_var<double> vxiv_0, vxiv_1, vxiv_2, vxiv_3, vxiv_4, vxiv_5;

  vxiv_0 = -vec.get_entry(2,0)*temp.get_entry(1,0) +  vec.get_entry(1,0)*temp.get_entry(2,0) + -vec.get_entry(2+3,0)*temp.get_entry(1+3,0) +  vec.get_entry(1+3,0)*temp.get_entry(2+3,0);
  vxiv_1 =  vec.get_entry(2,0)*temp.get_entry(0,0) + -vec.get_entry(0,0)*temp.get_entry(2,0) +  vec.get_entry(2+3,0)*temp.get_entry(0+3,0) + -vec.get_entry(0+3,0)*temp.get_entry(2+3,0);
  vxiv_2 = -vec.get_entry(1,0)*temp.get_entry(0,0) +  vec.get_entry(0,0)*temp.get_entry(1,0) + -vec.get_entry(1+3,0)*temp.get_entry(0+3,0) +  vec.get_entry(0+3,0)*temp.get_entry(1+3,0);
  vxiv_3 = -vec.get_entry(2,0)*temp.get_entry(1+3,0) +  vec.get_entry(1,0)*temp.get_entry(2+3,0);
  vxiv_4 =  vec.get_entry(2,0)*temp.get_entry(0+3,0) + -vec.get_entry(0,0)*temp.get_entry(2+3,0);
  vxiv_5 = -vec.get_entry(1,0)*temp.get_entry(0+3,0) +  vec.get_entry(0,0)*temp.get_entry(1+3,0);

  vecXIvec.set_entry_to_nonconstant(0, 0, vxiv_0);
  vecXIvec.set_entry_to_nonconstant(1, 0, vxiv_1);
  vecXIvec.set_entry_to_nonconstant(2, 0, vxiv_2);
  vecXIvec.set_entry_to_nonconstant(3, 0, vxiv_3);
  vecXIvec.set_entry_to_nonconstant(4, 0, vxiv_4);
  vecXIvec.set_entry_to_nonconstant(5, 0, vxiv_5);
}

#define EIGEN_MAT_CAST (dyn_var<EigenMatrix<double>>)(builder::cast)

static dyn_var<builder::eigen_vectorXd_t> rnea(const Model &model, 
        //dyn_var<robot_data*> rd,
        dyn_var<builder::eigen_vectorXd_t &> q, 
        dyn_var<builder::eigen_vectorXd_t &> qd, 
        const double GRAVITY = -9.81) {

  typedef typename Model::JointIndex JointIndex;
  const JointIndex njoints = (JointIndex)model.njoints;

  // hooked up to global robot_data struct for persistent result storage
  builder::array<SpatialVector<double>> v;
  builder::array<SpatialVector<double>> a;
  builder::array<SpatialVector<double>> f;
  v.set_size(njoints);
  a.set_size(njoints);
  f.set_size(njoints);
  matrix_layout<double> tau(model.njoints, 1, ctup::DENSE, ctup::EIGENMATRIX, ctup::UNCOMPRESSED);

  //// ----------- binding local vars for storing to persistent struct
  //for (static_var<JointIndex> i = 1; i < njoints; i = i+1) {
  //  v[i].set_matrix(rd->v[i]);
  //  a[i].set_matrix(rd->a[i]);
  //  f[i].set_matrix(rd->f[i]);
  //}
  //tau.set_matrix(rd->tau);

  SingletonSpatialVector<double> gravity_vec;
  gravity_vec.set_entry_to_constant(5, 0, -GRAVITY);

  builder::array<SingletonSpatialVector<double>> S;
  S.set_size(model.njoints);

  builder::array<Xform<double>> X_T;
  builder::array<Xform<double>> X_J;
  builder::array<Xform<double>> X_pi;

  X_T.set_size(model.njoints);
  X_J.set_size(model.njoints);
  X_pi.set_size(model.njoints);

  builder::array<SpatialInertia<double>> I;
  I.set_size(model.njoints);

  static_var<JointIndex> i;

  set_fixed_transforms_inertias(X_T, I, model);

  static_var<int> jtype;
  static_var<int> axis;

  for (i = 1; i < njoints; i = i+1) {
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

  SpatialVector<double> mxSvec, vecXIvec;

  static_var<JointIndex> parent;

  // forward pass
  for (i = 1; i < njoints; i = i+1) {
    X_J[i].jcalc(q(i-1));

    X_pi[i] = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      v[i] = X_pi[i] * v[parent];
      a[i] = X_pi[i] * a[parent];
    }
    else {
      // parent is base, v[i] remains zero
      a[i] = X_pi[i] * gravity_vec;
    }

    v[i] += S[i] * (dyn_var<double>)(builder::cast)qd(i-1);

    mxS(mxSvec, S[i], v[i], (dyn_var<double>)(builder::cast)qd(i-1));
    a[i] += mxSvec;

    // compute f
    // todo implement runtime func
    vxIv(vecXIvec, v[i], I[i]);
    f[i] = I[i] * a[i] + vecXIvec;
  }

  // backward pass

  for (i = njoints-1; i > 0; i = i-1) {
    tau.set_entry_to_nonconstant(i, 0, (transpose(S[i]) * f[i]).gen_entry_at(0, 0));

    parent = model.parents[i];
    if (parent > 0) {
      f[parent] += transpose(X_pi[i]) * f[i];
    }
  }

  //print_matrix_layout("tau: ", tau);
  return tau.denseify();
}

int main(int argc, char* argv[]) {
  const std::string urdf_filename = argv[1];
  std::cout << urdf_filename << "\n";

  const std::string header_filename = (argc <= 2) ? "./rnea_gen.h" : argv[2];
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

  block::c_code_generator::generate_struct_decl<dyn_var<robot_data>>(of);
  of << "\n";

  //auto rd_decl = std::make_shared<block::decl_stmt>();
  //rd_decl->decl_var = rd.block_var;
  ////rd.resize(model.njoints);
  //rd_decl->accept(&codegen);
  //of << "\n\n";

  builder::builder_context context;

  auto ast = context.extract_function_ast(init_rd, "init_rd", model.njoints);
  of << "static ";
  block::c_code_generator::generate_code(ast, of, 0);

  ast = context.extract_function_ast(rnea, "rnea", model, -9.81);
  of << "static ";
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
