#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/parsers/srdf.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/spatial/se3.hpp>
#include "pinocchio/algorithm/frames.hpp"

#include <Eigen/Core>

#include <iostream>
#include <string>
#include <cmath>

namespace pin = pinocchio;

static pin::SE3 fk_joint_placement(const pin::Model &model,
                                   const Eigen::VectorXd &q,
                                   pin::JointIndex jid) {
  pin::Data data(model);
  pin::forwardKinematics(model, data, q);
  pin::updateGlobalPlacements(model, data);
  return data.oMi[jid];
}

static pin::SE3 fk_frame_placement(const pin::Model &model,
                                   const Eigen::VectorXd &q,
                                   pin::FrameIndex fid) {
  pin::Data data(model);
  pin::forwardKinematics(model, data, q);
  pin::updateFramePlacements(model, data);
  return data.oMf[fid];
}

static Eigen::Matrix3d skew(const Eigen::Vector3d &v) {
  Eigen::Matrix3d m;
  m <<     0, -v.z(),  v.y(),
        v.z(),     0, -v.x(),
       -v.y(),  v.x(),    0;
  return m;
}

static inline Eigen::Vector3d vee_skew(const Eigen::Matrix3d &S) {
  return Eigen::Vector3d( S(2,1),
                          S(0,2),
                          S(1,0));
}

static Eigen::Matrix<double,6,Eigen::Dynamic>
fd_world_jacobian_for_joint(const pin::Model &model,
                            const Eigen::VectorXd &q,
                            pin::FrameIndex fid)
{
  constexpr double eps = 1e-8;
  const int nv = model.nv;
  Eigen::Matrix<double,6,Eigen::Dynamic> J(6, nv);
  J.setZero();

  // Base placement at q
  const pin::SE3 M0 = fk_frame_placement(model, q, fid);
  const Eigen::Matrix3d R0 = M0.rotation();
  const Eigen::Vector3d p0 = M0.translation(); // (not strictly needed, but kept for clarity)

  for (int k = 0; k < nv; ++k) {
    // Central difference in tangent space
    Eigen::VectorXd v = Eigen::VectorXd::Zero(nv);
    v[k] = eps;
    const Eigen::VectorXd q_p = pin::integrate(model, q,  v);
    const Eigen::VectorXd q_m = pin::integrate(model, q, -v);

    const Eigen::Vector3d trans_p = fk_frame_placement(model, q_p, fid).translation();
    const Eigen::Vector3d trans_m = fk_frame_placement(model, q_m, fid).translation();

    const Eigen::Matrix3d rot_p = fk_frame_placement(model, q_p, fid).rotation();
    const Eigen::Matrix3d rot_m = fk_frame_placement(model, q_m, fid).rotation();

	const Eigen::Vector3d diff_trans = (trans_p - trans_m) / (2.0 * eps);
	const Eigen::Matrix3d diff_rot = (rot_p - rot_m) / (2.0 * eps);

    // Linear velocity in WORLD: ṗ = (p+ - p-)/(2ε)
	Eigen::Matrix4d diff_g;
	diff_g.block<3, 3>(0, 0) = diff_rot;
	diff_g.block<3, 1>(0, 3) = diff_trans;

	Eigen::Matrix4d g_inv = M0.inverse().toHomogeneousMatrix();
	Eigen::Matrix4d thing = diff_g * g_inv;

    const Eigen::Vector3d omega = vee_skew(thing.block<3, 3>(0, 0));

    // Write column k
    J.block<3,1>(0,k) = omega; // angular (WORLD)
    J.block<3,1>(3,k) = thing.block<3, 1>(0, 3);    // linear  (WORLD)
  }
  return J;
}

static Eigen::Matrix<double,6,Eigen::Dynamic>
analytic_world_jacobian_for_joint(const pin::Model &model,
                                  const Eigen::VectorXd &q,
                                  pin::FrameIndex fid) {
  pin::Data data(model);
  pin::forwardKinematics(model, data, q);
  pin::updateFramePlacements(model, data);

  Eigen::Matrix<double,6,Eigen::Dynamic> J(6, model.nv);
  J.setZero();
  pin::computeFrameJacobian(model, data, q, fid, pin::WORLD, J);

  Eigen::Matrix<double, 6, Eigen::Dynamic> J_conv(6, model.nv);
  J_conv.setZero();

  // swapping because pin flips linear and angular part
  J_conv.topRows<3>() = J.bottomRows<3>();
  J_conv.bottomRows<3>() = J.topRows<3>();
  return J_conv;
}

static int get_jtype(const pin::Model &model, pin::JointIndex i) {
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

static int get_joint_axis(const pin::Model &model, pin::JointIndex i) {
  std::string joint_name = model.joints[i].shortname();
  char axis = joint_name.back();

  switch(axis) {
    case 'X': return 'X';
    case 'Y': return 'Y';
    case 'Z': return 'Z';
    default: assert(false && "should never happen"); return -1;
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

static Eigen::Matrix<double, 6, Eigen::Dynamic>
manual_world_jacobian_for_joint(const pin::Model &model,
        const Eigen::VectorXd &q,
        pin::FrameIndex fid) {
  pin::JointIndex jid = model.frames[fid].parentJoint;
  pin::Data data(model);
  // don't want to calculate FK from scratch
  pin::forwardKinematics(model, data, q);

  Eigen::Matrix<double, 6, Eigen::Dynamic> J(6, model.nv);
  J.setZero();

  Eigen::Matrix<double, 6, 1> S_world, S;
  S.setZero();
  S_world.setZero();

  Eigen::Matrix<double, 3, 3> adj_par_R;
  Eigen::Matrix<double, 3, 3> adj_par_p;
  Eigen::Matrix<double, 6, 6> adj_par;

  Eigen::Matrix<double, 3, 3> adj_curr_R;
  Eigen::Matrix<double, 3, 3> adj_curr_p;
  Eigen::Matrix<double, 6, 6> adj_curr;

  for (size_t i = 1; i < (size_t)model.njoints; i++) {
    S.setZero();
    S_world.setZero();
    adj_par_R.setZero();
    adj_par_p.setZero();
    adj_par.setZero();
    adj_curr_R.setZero();
    adj_curr_p.setZero();
    adj_curr.setZero();

    if (!is_joint_ancestor(model, i, jid)) {
      // 0th joint is universe
      J.col(i-1).setZero();
      continue;
    }

    if (get_jtype(model, i) == 'P') {
      // linear v bottom
      if (get_joint_axis(model, i) == 'X') S(3) = 1;
      if (get_joint_axis(model, i) == 'Y') S(4) = 1;
      if (get_joint_axis(model, i) == 'Z') S(5) = 1;
    }
    else if (get_jtype(model, i) == 'R') {
      // rotational omega top
      if (get_joint_axis(model, i) == 'X') S(0) = 1;
      if (get_joint_axis(model, i) == 'Y') S(1) = 1;
      if (get_joint_axis(model, i) == 'Z') S(2) = 1;
    }

    adj_curr_R = data.oMi[i].rotation();
    adj_curr_p = skew(data.oMi[i].translation());
    adj_curr.block<3, 3>(0, 0) = adj_curr_R;
    adj_curr.block<3, 3>(3, 3) = adj_curr_R;
    adj_curr.block<3, 3>(3, 0) = adj_curr_p * adj_curr_R;

    S_world = adj_curr * S;

    J.col(i-1) = S_world;
  }

  return J;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " path/to/robot.urdf path/to/robot.srdf\n";
    return 1;
  }

  std::string urdf_path = argv[1];
  std::string srdf_path = argv[2];

  pin::Model model;
  try {
    pin::urdf::buildModel(urdf_path, model);
  } catch (const std::exception &e) {
    std::cerr << "Failed to load URDF: " << e.what() << "\n";
    return 1;
  }

  Eigen::VectorXd q;
  bool used_ready = false;
  try {
    pin::srdf::loadReferenceConfigurations(model, srdf_path, false);
    auto it = model.referenceConfigurations.find("ready");
    if (it != model.referenceConfigurations.end() && it->second.size() == model.nq) {
      q = it->second;
      used_ready = true;
    } else {
      q = pin::randomConfiguration(model);
    }
  } catch (...) {
    q = pin::randomConfiguration(model);
  }

  const pin::JointIndex last_jid = model.njoints > 1 ? model.njoints - 1 : 0;
  const std::string last_jname =
      (last_jid < model.names.size()) ? model.names[last_jid] : ("joint#" + std::to_string(last_jid));
  const pin::FrameIndex last_fid = model.getFrameId("panda_link7");

  const auto J_an = analytic_world_jacobian_for_joint(model, q, last_fid);
  const auto J_fd = fd_world_jacobian_for_joint(model, q, last_fid);
  const auto J_man = manual_world_jacobian_for_joint(model, q, last_fid);
  const Eigen::MatrixXd err = J_an - J_fd;

  double max_abs = err.cwiseAbs().maxCoeff();
  double rms = std::sqrt((err.array().square().mean()));
  Eigen::VectorXd col_norms = (J_an.colwise().norm().array() + 1e-16).matrix();
  Eigen::VectorXd rel_cols(col_norms.size());
  for (int k = 0; k < col_norms.size(); ++k) rel_cols[k] = err.col(k).norm() / col_norms[k];
  double rel_max = rel_cols.maxCoeff();
  double rel_rms = std::sqrt(rel_cols.array().square().mean());
  Eigen::Index worst_idx; rel_cols.maxCoeff(&worst_idx);

  std::cout << "Model: nq=" << model.nq << ", nv=" << model.nv << "\n";
  std::cout << "Joint (last): id=" << last_jid << ", name='" << last_jname << "'\n";
  if (used_ready) std::cout << "Using SRDF 'ready' configuration.\n";
  else            std::cout << "Using randomConfiguration().\n";
  std::cout << "Errors comparing analytic WORLD Jacobian vs FD of joint placement:\n";
  std::cout << "  Max abs error: " << max_abs << "\n";
  std::cout << "  RMS abs error: " << rms << "\n";
  std::cout << "  Max rel (per-column): " << rel_max << "\n";
  std::cout << "  RMS rel (per-column): " << rel_rms << "\n";
  std::cout << "  Worst column index: " << worst_idx
            << " (rel err = " << rel_cols[worst_idx] << ")\n";

  Eigen::IOFormat fmt(6, 0, " ", "\n", "", "", "", "");
  std::cout << "\nAnalytic WORLD Jacobian:\n" << J_an.format(fmt) << "\n";
  std::cout << "\nFinite-difference WORLD Jacobian:\n" << J_fd.format(fmt) << "\n";
  std::cout << "\nError (analytic - FD):\n" << err.format(fmt) << "\n";
  std::cout << "\nManual calc WORLD Jacobian:\n" << J_man.format(fmt) << "\n";

  return 0;
}

