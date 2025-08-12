#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/parsers/srdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/geometry.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include "pinocchio/algorithm/frames.hpp"

#include <hpp/fcl/shape/geometric_shapes.h>  // for hpp::fcl::Sphere

#include <iostream>
#include <cmath>

using namespace pinocchio;

constexpr double EPSILON = 1e-6;

struct CollisionGradient {
  double signed_distance;
  Eigen::VectorXd gradient;
  std::pair<GeomIndex, GeomIndex> geom_pair;
};

static Eigen::Matrix3d skew(const Eigen::Vector3d &v) {
  Eigen::Matrix3d m;
  m <<     0, -v.z(),  v.y(),
        v.z(),     0, -v.x(),
       -v.y(),  v.x(),    0;
  return m;
}

static CollisionGradient computeDistanceAndGradientForPair(
    const Model &model,
    Data &data,
    const GeometryModel &geom_model,
    GeometryData &geom_data,
    const Eigen::VectorXd &q,
    GeomIndex g1,
    GeomIndex g2)
{
  std::cout << "pair: " << "(" << g1 << ", " << g2 << ")\n";

  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  const auto &obj1 = geom_model.geometryObjects[g1];
  const auto &obj2 = geom_model.geometryObjects[g2];

  auto sph1 = std::dynamic_pointer_cast<hpp::fcl::Sphere>(obj1.geometry);
  auto sph2 = std::dynamic_pointer_cast<hpp::fcl::Sphere>(obj2.geometry);
  if (!sph1 || !sph2) {
    throw std::runtime_error("Non-sphere geometry detected in collision model.");
  }

  double r1 = sph1->radius;
  double r2 = sph2->radius;

  // World positions of sphere centers
  // oMg is placement of object in world frame
  Eigen::Vector3d p1 = geom_data.oMg[g1].translation();
  Eigen::Vector3d p2 = geom_data.oMg[g2].translation();
  Eigen::Vector3d delta = p1 - p2;
  double dist = delta.norm();
  double signed_dist = dist - (r1 + r2);

  // Get world Jacobians of the sphere centers
  JointIndex j1 = obj1.parentJoint;
  JointIndex j2 = obj2.parentJoint;

  computeJointJacobians(model, data, q);

  ////// Jacobian for obj1

  Eigen::Matrix<double, 6, Eigen::Dynamic> J1_spatial;
  J1_spatial.resize(6, model.nv);
  J1_spatial.setZero();
  getJointJacobian(model, data, j1, WORLD, J1_spatial);

  Eigen::MatrixXd J1_linear = J1_spatial.topRows<3>();
  Eigen::MatrixXd J1_angular = J1_spatial.bottomRows<3>();

  // adding offset for obj1 position

  // obj1 placement wrt parent joint j1, expressed in j1 frame
  Eigen::Vector3d p1_local = obj1.placement.translation();
  Eigen::Matrix3d R1_world = data.oMi[j1].rotation();
  // obj1 wrt j1 expressed in world frame
  Eigen::Vector3d p1_world = R1_world * p1_local;

  Eigen::MatrixXd J1 = J1_linear + skew(p1_world) * J1_angular;

  std::cout << "===============\n";
  std::cout << "J1: \n" << J1 << "\n";

  ////// Jacobian for obj2

  Eigen::Matrix<double, 6, Eigen::Dynamic> J2_spatial;
  J2_spatial.resize(6, model.nv);
  J2_spatial.setZero();
  getJointJacobian(model, data, j2, WORLD, J2_spatial);

  Eigen::MatrixXd J2_linear = J2_spatial.topRows<3>();
  Eigen::MatrixXd J2_angular = J2_spatial.bottomRows<3>();

  // adding offset for obj2 position

  // obj1 placement wrt parent joint j1, expressed in j1 frame
  Eigen::Vector3d p2_local = obj2.placement.translation();
  Eigen::Matrix3d R2_world = data.oMi[j2].rotation();
  // obj1 wrt j1 expressed in world frame
  Eigen::Vector3d p2_world = R2_world * p2_local;

  Eigen::MatrixXd J2 = J2_linear + skew(p2_world) * J2_angular;

  std::cout << "===============\n";
  std::cout << "J2: \n" << J2 << "\n";

  ////// Gradient calc

  Eigen::VectorXd grad = Eigen::VectorXd::Zero(model.nv);
  std::cout << "===============\n";
  std::cout << "grad_norm: " << (delta/dist).transpose() << "\n";
  std::cout << "grad: " << (delta/dist).transpose() * (J1 - J2) << "\n";
  std::cout << "===============\n";
  if (dist > 1e-8) {
    grad = (delta / dist).transpose() * (J1 - J2);
  }

  return {signed_dist, grad, {g1, g2}};
}

static void finiteDifferenceCheck(
    const Model &model,
    const GeometryModel &geom_model,
    const Eigen::VectorXd &q,
    const CollisionGradient &result)
{
  std::cout << "========= Finite Diff check =======\n";
  const auto &[g1, g2] = result.geom_pair;
  Eigen::VectorXd q_plus = q, q_minus = q;
  Eigen::VectorXd grad_fd(model.nv);

  for (int i = 0; i < model.nv; ++i) {
    q_plus = q;
    q_minus = q;
    q_plus(i) += EPSILON;
    q_minus(i) -= EPSILON;

    Data data_plus(model), data_minus(model);
    GeometryData geom_plus(geom_model), geom_minus(geom_model);

    double d_plus = computeDistanceAndGradientForPair(model, data_plus, geom_model, geom_plus, q_plus, g1, g2).signed_distance;
    double d_minus = computeDistanceAndGradientForPair(model, data_minus, geom_model, geom_minus, q_minus, g1, g2).signed_distance;

    grad_fd(i) = (d_plus - d_minus) / (2 * EPSILON);
  }

  std::cout << "pair: " << "(" << g1 << ", " << g2 << ")\n";
  std::cout << "Analytical Gradient:\n" << result.gradient.transpose() << "\n";
  std::cout << "Finite Difference:\n" << grad_fd.transpose() << "\n";
  std::cout << "Relative Error:\n";
  for (int i = 0; i < model.nv; ++i) {
    double a = result.gradient(i), n = grad_fd(i);
    double err = std::abs(a - n) / std::max(1e-8, std::abs(a) + std::abs(n));
    std::cout << "Joint " << i << ": " << err << "\n";
  }
  std::cout << "===============\n";
}

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " robot.urdf robot.srdf\n";
    return 1;
  }

  const std::string urdf_path = argv[1];
  const std::string srdf_path = argv[2];

  // Load model and geometry
  Model model;
  GeometryModel geom_model;
  pinocchio::urdf::buildModel(urdf_path, model);
  pinocchio::urdf::buildGeom(model, urdf_path, COLLISION, geom_model);

  geom_model.addAllCollisionPairs();
  srdf::removeCollisionPairs(model, geom_model, srdf_path);

  srdf::loadReferenceConfigurations(model, srdf_path, true);

  Data data(model);
  GeometryData geom_data(geom_model);

  // test jac
  Eigen::Matrix<double, 6, Eigen::Dynamic> J;
  J.resize(6, model.nv);

  // Use reference configuration if available
  Eigen::VectorXd q = model.referenceConfigurations["ready"];
  std::cout << q << "\n";
  computeJointJacobians(model, data, q);
  getJointJacobian(model, data, model.njoints-1, WORLD, J);
  std::cout << J << "\n";
  std::cout << "======== random config =========\n";
  q = randomConfiguration(model);
  std::cout << q << "\n";
  computeJointJacobians(model, data, q);
  getJointJacobian(model, data, model.njoints-1, WORLD, J);
  std::cout << J << "\n";
  std::cout << "=============================\n";
  // test jac

  // Compute distance + gradient for all valid collision pairs
  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  for (const auto &cp : geom_model.collisionPairs) {
    auto result = computeDistanceAndGradientForPair(model, data, geom_model, geom_data, q, cp.first, cp.second);
    std::cout << "Collision Pair (" << cp.first << ", " << cp.second << ") -> Signed Distance: "
              << result.signed_distance << "\n";

    finiteDifferenceCheck(model, geom_model, q, result);
    std::cout << "----------------------------------------\n";
  }

  return 0;
}

