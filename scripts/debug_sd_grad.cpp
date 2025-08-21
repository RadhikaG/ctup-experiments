#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/parsers/srdf.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/geometry.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include "pinocchio/algorithm/frames.hpp"

#include <hpp/fcl/shape/geometric_shapes.h>  // for hpp::fcl::Sphere

#include <cassert>
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

static inline Eigen::Vector3d vee_skew(const Eigen::Matrix3d &S) {
  return Eigen::Vector3d( S(2,1),
                          S(0,2),
                          S(1,0));
}

static double computeDistance(
    const Model &model,
    Data &data,
    const GeometryModel &geom_model,
    GeometryData &geom_data,
    const Eigen::VectorXd &q,
    GeomIndex g1,
    GeomIndex g2) {

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

  return signed_dist;
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
  // oMg is placement of object wrt world frame expressed in world frame
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

  //Eigen::MatrixXd J1 = J1_linear + skew(p1_world) * J1_angular;
  Eigen::Matrix<double, 3, Eigen::Dynamic> J1;
  J1.resize(3, model.nq);

  for (size_t i = 0; i < (size_t)model.nq; i++) {
    Eigen::Vector3d w_1i = J1_angular.col(i);
    Eigen::Vector3d v_1i = J1_linear.col(i);
    J1.col(i) = w_1i.cross(p1_world) + v_1i;
  }

  std::cout << "===============\n";
  std::cout << "J1: \n" << J1 << "\n";
  std::cout << "pin frame jac: \n" << getFrameJacobian(model, data, obj1.parentFrame, WORLD).topRows<3>() << "\n";
  J1 = getFrameJacobian(model, data, obj1.parentFrame, WORLD).topRows<3>();

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

  //Eigen::MatrixXd J2 = J2_linear + skew(p2_world) * J2_angular;
  Eigen::Matrix<double, 3, Eigen::Dynamic> J2;
  J2.resize(3, model.nq);
  for (size_t i = 0; i < (size_t)model.nq; i++) {
    Eigen::Vector3d w_2i = J2_angular.col(i);
    Eigen::Vector3d v_2i = J2_linear.col(i);
    J2.col(i) = w_2i.cross(p2_world) + v_2i;
  }

  std::cout << "===============\n";
  std::cout << "J2: \n" << J2 << "\n";
  std::cout << "pin frame jac: \n" << getFrameJacobian(model, data, obj2.parentFrame, WORLD).topRows<3>() << "\n";
  J2 = getFrameJacobian(model, data, obj2.parentFrame, WORLD).topRows<3>();

  ////// Gradient calc

  Eigen::VectorXd grad = Eigen::VectorXd::Zero(model.nv);
  std::cout << "===============\n";
  std::cout << "grad_norm: " << (delta/dist).transpose() << "\n";
  std::cout << "grad: " << (delta/2*dist).transpose() * (J1 - J2) << "\n";
  std::cout << "===============\n";
  if (dist > 1e-8) {
    grad = (delta / 2 * dist).transpose() * (J1 - J2);
  }

  return {signed_dist, grad, {g1, g2}};
}

static void printAllGeoms(
    Model &model,
    Data &data,
    GeometryModel &geom_model,
    GeometryData &geom_data)
{
  std::cout << "===============================\n";
  for (size_t i = 0; i < geom_model.geometryObjects.size(); i++) {
    Eigen::Matrix4d go_xform = geom_data.oMg[i].toHomogeneousMatrix();
    std::cout << geom_model.geometryObjects[i].name << ":\n";
    std::cout << go_xform << "\n";
  }
  std::cout << "===============================\n";
}

static Eigen::Matrix<double, 6, 1> get_spatial_twist_fd(
    Model &model,
    Data &data,
    GeometryModel &geom_model,
    GeometryData &geom_data,
    GeomIndex g_id,
    Eigen::VectorXd &q_minus,
    Eigen::VectorXd &q,
    Eigen::VectorXd &q_plus) {
  Eigen::Matrix<double, 6, 1> spatial_twist;

  Eigen::Matrix4d T_dot, T, T_plus, T_minus;

  Eigen::Vector3d omega_s, v_s;

  updateGeometryPlacements(model, data, geom_model, geom_data, q);
  T = geom_data.oMg[g_id].inverse().toHomogeneousMatrix();

  updateGeometryPlacements(model, data, geom_model, geom_data, q_plus);
  T_plus = geom_data.oMg[g_id].toHomogeneousMatrix();

  updateGeometryPlacements(model, data, geom_model, geom_data, q_minus);
  T_minus = geom_data.oMg[g_id].toHomogeneousMatrix();

  T_dot = (T_plus - T_minus) / (2 * EPSILON);

  Eigen::Matrix4d spatial_twist_hom;
  //spatial_twist_hom = T_dot * T.inverse();
  spatial_twist_hom = T_dot * T;

  omega_s = vee_skew(spatial_twist_hom.block<3, 3>(0, 0));
  v_s = spatial_twist_hom.block<3, 1>(0, 3);

  //spatial_twist.block<3, 1>(0, 0) = omega_s;
  //spatial_twist.block<3, 1>(3, 0) = v_s;
  //
  // pin order
  spatial_twist.block<3, 1>(0, 0) = v_s;
  spatial_twist.block<3, 1>(3, 0) = omega_s;

  return spatial_twist;
}

static void finiteDifferenceCheck(
    Model &model,
    Data &data,
    GeometryModel &geom_model,
    GeometryData &geom_data,
    Eigen::VectorXd &q,
    CollisionGradient &result)
{
  const auto &[g1, g2] = result.geom_pair;

  const auto &obj1 = geom_model.geometryObjects[g1];
  const auto &obj2 = geom_model.geometryObjects[g2];

  auto sph1 = std::dynamic_pointer_cast<hpp::fcl::Sphere>(obj1.geometry);
  auto sph2 = std::dynamic_pointer_cast<hpp::fcl::Sphere>(obj2.geometry);
  if (!sph1 || !sph2) {
    throw std::runtime_error("Non-sphere geometry detected in collision model.");
  }

  double r1 = sph1->radius;
  double r2 = sph2->radius;

  std::cout << "========= Finite Diff check =======\n";

  Eigen::VectorXd q_plus(q), q_minus(q);

  Eigen::MatrixXd J1_fd(6, model.nq);
  Eigen::MatrixXd J2_fd(6, model.nq);

  for (size_t i = 0; i < (size_t)model.nq; i++) {
    //std::cout << "pair: " << "(" << g1 << ", " << g2 << "), " << "i = " << i << "\n";
    q_plus = q; q_minus = q;
    //q_plus(i) += EPSILON;
    //q_minus(i) -= EPSILON;
    Eigen::VectorXd v(model.nv);
    v.setZero();
    v[i] = EPSILON;
    q_plus = integrate(model, q, v);
    q_minus = integrate(model, q, -v);

    Eigen::Matrix<double, 6, 1> v1 = get_spatial_twist_fd(model, data, geom_model, geom_data, g1, q_minus, q, q_plus);
    Eigen::Matrix<double, 6, 1> v2 = get_spatial_twist_fd(model, data, geom_model, geom_data, g2, q_minus, q, q_plus);

    J1_fd.col(i) = v1;
    J2_fd.col(i) = v2;
  }

  //const double threshold = 1e-15;
  //J1_fd = (threshold < J1_fd.array().abs()).select(J1_fd, 0.0f);
  //J2_fd = (threshold < J2_fd.array().abs()).select(J2_fd, 0.0f);

  Eigen::Matrix<double, 6, Eigen::Dynamic> J_pin(6, model.nv);

  std::cout << "====== Finite diff jacobians =========\n";
  std::cout << "J1: \n" << J1_fd << "\n";
  std::cout << "J2: \n" << J2_fd << "\n";
  std::cout << "===============================\n";

  std::cout << "====== getFrameJacobian =========\n";
  computeJointJacobians(model, data, q);
  getFrameJacobian(model, data, obj1.parentFrame, WORLD, J_pin);
  std::cout << "J1: \n" <<  J_pin << "\n";
  getFrameJacobian(model, data, obj2.parentFrame, WORLD, J_pin);
  std::cout << "J2: \n" << J_pin << "\n";
  std::cout << "===============================\n";

  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  Eigen::Vector3d p1 = geom_data.oMg[g1].translation();
  Eigen::Vector3d p2 = geom_data.oMg[g2].translation();

  Eigen::Vector3d n = (p1 - p2).normalized();

  Eigen::VectorXd grad_fd = n.transpose() * (J1_fd.topRows<3>() - J2_fd.topRows<3>());


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

  Eigen::VectorXd q;
  //// Use reference configuration if available
  //q = model.referenceConfigurations["ready"];
  //std::cout << q << "\n";
  //computeJointJacobians(model, data, q);
  //getJointJacobian(model, data, model.njoints-1, WORLD, J);
  //std::cout << J << "\n";
  std::cout << "======== random config =========\n";
  q = randomConfiguration(model);
  std::cout << q << "\n";
  computeJointJacobians(model, data, q);
  getJointJacobian(model, data, model.njoints-1, WORLD, J);
  std::cout << J << "\n";
  std::cout << "=============================\n";
  // test jac

  updateGeometryPlacements(model, data, geom_model, geom_data, q);

  // Compute distance + gradient for all valid collision pairs
  for (const auto &cp : geom_model.collisionPairs) {
    auto result = computeDistanceAndGradientForPair(model, data, geom_model, geom_data, q, cp.first, cp.second);
    std::cout << "Collision Pair (" << cp.first << ", " << cp.second << ") -> Signed Distance: "
              << result.signed_distance << "\n";

    finiteDifferenceCheck(model, data, geom_model, geom_data, q, result);
    std::cout << "----------------------------------------\n";
  }

  return 0;
}

