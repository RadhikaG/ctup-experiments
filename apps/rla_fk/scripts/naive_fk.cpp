#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/utils/timer.hpp"
#include "pinocchio/algorithm/kinematics.hpp"
#include "blaze/Math.h"
#include <iostream>
#include <argparse/argparse.hpp>

typedef blaze::StaticVector<double, 8> blazeSIMDVec8d; 
typedef blaze::StaticMatrix<blazeSIMDVec8d, 6, 6> XformBatched_t;
typedef blaze::StaticMatrix<double, 6, 6> Xform_t;

using namespace pinocchio;

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

static void set_X_T(const Model &model, blaze::DynamicVector<Xform_t> &X_T) {
  size_t r = 0;
  size_t c = 0;

  for (size_t i = 0; i < (size_t)model.njoints; i = i+1) {
    Eigen::Matrix<double, 6, 6> tmp_cst_mat = model.jointPlacements[i];

    for (c = 0; c < 6; c = c + 1) {
      for (r = 0; r < 6; r = r + 1) {
        X_T[i](c, r) = tmp_cst_mat.coeffRef(c, r);
      }
    }
  }
}

static Xform_t fk(const Model &model, blaze::DynamicVector<Xform_t> &X_T, blaze::DynamicVector<double> &q) {
  int jtype;
  int axis;

  blaze::DynamicVector<Xform_t> X_J(model.njoints);
  blaze::DynamicVector<Xform_t> X_0(model.njoints);

  double sinq, cosq;

  for (size_t i = 1; i < (size_t)model.njoints; i++) {
    sinq = sin(q[i-1]); 
    cosq = cos(q[i-1]); 

    jtype = get_jtype(model, i);
    axis = get_joint_axis(model, i);

    X_J[i].reset();

    if (jtype == 'R') {
      if (axis == 'X') {
        X_J[i](0, 0) = 1;
        X_J[i](1, 1) = cosq;
        X_J[i](1, 2) = -sinq;
        X_J[i](2, 1) = sinq;
        X_J[i](2, 2) = cosq;
        // not smart but doing nonetheless for symmetric E
        X_J[i](3+0, 3+0) = 1;
        X_J[i](3+1, 3+1) = cosq;
        X_J[i](3+1, 3+2) = -sinq;
        X_J[i](3+2, 3+1) = sinq;
        X_J[i](3+2, 3+2) = cosq;
      } 
      else if (axis == 'Y') {
        X_J[i](1, 1) = 1;
        X_J[i](0, 0) = cosq;
        X_J[i](0, 2) = sinq;
        X_J[i](2, 0) = -sinq;
        X_J[i](2, 2) = cosq;
        // not smart but doing nonetheless for symm E
        X_J[i](3+1, 3+1) = 1;
        X_J[i](3+0, 3+0) = cosq;
        X_J[i](3+0, 3+2) = sinq;
        X_J[i](3+2, 3+0) = -sinq;
        X_J[i](3+2, 3+2) = cosq;
      } 
      else if (axis == 'Z') {
        X_J[i](2, 2) = 1;
        X_J[i](0, 0) = cosq;
        X_J[i](0, 1) = -sinq;
        X_J[i](1, 0) = sinq;
        X_J[i](1, 1) = cosq;
        // not smart but doing nonetheless for symm E
        X_J[i](3+2, 3+2) = 1;
        X_J[i](3+0, 3+0) = cosq;
        X_J[i](3+0, 3+1) = -sinq;
        X_J[i](3+1, 3+0) = sinq;
        X_J[i](3+1, 3+1) = cosq;
      } 
      // r = 0
    }
    else if (jtype == 'P') {
      // negative r-cross, opp signs of featherstone 2.23
      if (axis == 'X') {
        X_J[i](3+1, 2) = -q[i-1];
        X_J[i](3+2, 1) = q[i-1];
      }
      else if (axis == 'Y') {
        X_J[i](3+0, 2) = q[i-1];
        X_J[i](3+2, 0) = -q[i-1];
      }
      else if (axis == 'Z') {
        X_J[i](3+0, 1) = -q[i-1];
        X_J[i](3+1, 0) = q[i-1];
      }
      // E = Identity 
      X_J[i](0, 0) = 1;
      X_J[i](1, 1) = 1;
      X_J[i](2, 2) = 1;
      // symm E
      X_J[i](3+0, 3+0) = 1;
      X_J[i](3+1, 3+1) = 1;
      X_J[i](3+2, 3+2) = 1;
    }
    else {
      assert(false && "joint type unsupported");
    }
  }

  size_t parent;
  Xform_t X_pi;

  for (size_t i = 1; i < (size_t)model.njoints; i++) {
    X_pi = X_T[i] * X_J[i];

    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_0[parent] * X_pi;
    }
    else {
      X_0[i] = X_pi;
    }

    std::cout << "------ i = " << i << " --------\n";

    std::cout << "X_T:\n" << X_T[i];
    std::cout << "X_J:\n" << X_J[i];
    if (parent > 0)
      std::cout << "X_0 par:\n" << X_0[parent];
    std::cout << "X_pi:\n" << X_pi;
    std::cout << "X_0:\n" << X_0[i];
    
    std::cout << "---------------------\n";
  }

  return X_0[model.njoints-1];
}

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("naive_fk");

  program.add_argument("urdf")
      .help("path to the URDF file");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  PinocchioTicToc timer(PinocchioTicToc::NS);
  //const int NBT = 1000000;
  const int NBT = 1;

  // You should change here to set up your own URDF file or just pass it as an argument of this example.
  const std::string urdf_filename = program.get<std::string>("urdf");
  std::cout << urdf_filename << "\n";
  
  // Load the urdf model
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  std::cout << "model name: " << model.name << std::endl;
  
  // Create data required by the algorithms
  Data data(model);
  
  // Sample a random configuration
  Eigen::VectorXd q = randomConfiguration(model);
  std::cout << "q: " << q.transpose() << std::endl;

  blaze::DynamicVector<double> blaze_q;

  blaze_q.resize(model.njoints);
  for (size_t i = 0; i < (size_t)model.nq; i++) {
    blaze_q[i] = q[i];
  }

  blaze::DynamicVector<Xform_t> X_T(model.njoints);
  set_X_T(model, X_T);

  Xform_t res;

  timer.tic();
  SMOOTH(NBT)
  {
    res = fk(model, X_T, blaze_q);
  }
  std::cout << "dumb fk avg time taken (ns): \t\t\t\t";
  timer.toc(std::cout, NBT);

  Eigen::Matrix<double, 6, 6> dumb_res, pin_res;

  forwardKinematics(model,data,q);
  pin_res = data.oMi[model.njoints-1];

  // we know dumb_res has broadcasted entries
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      dumb_res(i, j) = res(i, j);

  std::cout << "dumb fk res:\n" << dumb_res << "\n";
  std::cout << "pin res:\n" << pin_res << "\n";
}

