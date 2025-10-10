#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/collision/collision.hpp"
#include "pinocchio/utils/timer.hpp"
#include <iostream>
#include <argparse/argparse.hpp>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("debug_fkcc");

  program.add_argument("urdf")
      .help("path to the URDF file");
  program.add_argument("srdf")
      .help("path to the SRDF file");

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  using namespace pinocchio;
  const std::string urdf_filename = program.get<std::string>("urdf");
  const std::string srdf_filename = program.get<std::string>("srdf");

  PinocchioTicToc timer(PinocchioTicToc::NS);
  //const int NBT = 100000;
  const int NBT = 1;

  // Load the URDF model contained in urdf_filename
  Model model;
  pinocchio::urdf::buildModel(urdf_filename,model);
  // Build the data associated to the model
  Data data(model);
  // Load the geometries associated to model which are contained in the URDF file
  GeometryModel geom_model;
  pinocchio::urdf::buildGeom(model, urdf_filename, pinocchio::COLLISION, geom_model);
  // Add all possible collision pairs and remove the ones collected in the SRDF file
  geom_model.addAllCollisionPairs();
  pinocchio::srdf::removeCollisionPairs(model, geom_model, srdf_filename);
  // Build the data associated to the geom_model
  GeometryData geom_data(geom_model); // contained the intermediate computations, like the placement of all the geometries with respect to the world frame
  // Load the reference configuration of the robots (this one should be collision free)
  Model::ConfigVectorType q(model.nq);
  // known collision-free
  q << -0.28, -0.47, -0.5, -1.2, 0.82, -0.15;//, 0.15;
  // with collision
  std::cout << "Configurations: " <<std::endl;
  std::cout << q << std::endl;

  // And test all the collision pairs
  timer.tic();
  SMOOTH(NBT*8)
  {
  computeCollisions(model, data, geom_model, geom_data, q, false);
  }
  std::cout << "pin avg time taken (ns): 				";
  timer.toc(std::cout, NBT);

  updateGeometryPlacements(model, data, geom_model, geom_data);

  std::cout << "Sphere Positions:" <<std::endl;
  for(size_t i=0;i<geom_model.geometryObjects.size();++i){
    Eigen::Vector3d sphere_pos = geom_data.oMg[i].translation().transpose();
    std::cout <<sphere_pos<<std::endl;
    std::cout <<std::endl;
  }

  // Print the status of all the collision pairs
  for(size_t k = 0; k < geom_model.collisionPairs.size(); ++k)
  {
    const CollisionPair & cp = geom_model.collisionPairs[k];
    const coal::CollisionResult & cr = geom_data.collisionResults[k];
    std::cout << "collision pair: " << cp.first << " , " << cp.second << " - collision: ";
    std::cout << (cr.isCollision() ? "yes" : "no") << std::endl;
  }
  // If you want to stop as soon as a collision is encounter, just add false for the final default argument stopAtFirstCollision
  //computeCollisions(model,data,geom_model,geom_data,q,true);
  // And if you to check only one collision pair, e.g. the third one, at the neutral element of the Configuration Space of the robot
  /*
  const PairIndex pair_id = 2;
  const Model::ConfigVectorType q_neutral = neutral(model);
  updateGeometryPlacements(model, data, geom_model, geom_data, q_neutral); // performs a forward kinematics over the whole kinematics model + update the placement of all the geometries contained inside geom_model
  computeCollision(geom_model, geom_data, pair_id);
  */

  // Debug helpers
  std::cout << "----------------\n";
  std::cout << "DEBUG OUTPUTS\n";

  typedef Eigen::Matrix<double, 4, 4> EigenHomogXform;

  EigenHomogXform X_0;
  Eigen::Matrix<double, 4, 1> t_sph_homog;
  Eigen::Matrix<double, 4, 1> t_sph_0_homog;

  Eigen::Matrix<double, 3, 3> X_0_rot;
  Eigen::Matrix<double, 3, 1> X_0_trans;

  Eigen::Matrix<double, 3, 1> t_sph;
  Eigen::Matrix<double, 3, 1> t_sph_0;

  std::string parent_joint;
  size_t parent_joint_id;

  EigenHomogXform X_T, X_J, X_pi, X_par;
  EigenHomogXform X_pi_manual, X_T_manual, X_J_manual, X_0_manual;
  Eigen::Matrix<double, 3, 3> X_T_rot;
  Eigen::Matrix<double, 3, 1> X_T_trans;

  for (size_t i = 1; i < (size_t)model.njoints; i++) {
    if (i <= 4) {
      X_T = model.jointPlacements[i].toHomogeneousMatrix();

      X_J = data.joints[i].M().toHomogeneousMatrix();
      X_pi = data.liMi[i].toHomogeneousMatrix();

      std::cout << "X_J_pin " << model.names[i] << ":\n" << X_J << "\n";
      std::cout << "X_T_pin " << model.names[i] << ":\n" << X_T << "\n";

      X_pi_manual = X_T * X_J;
      std::cout << "X_pi_pin " << model.names[i] << ":\n" << X_pi_manual << "\n";

      // "correcting" pin X_J
      X_J_manual = X_J;
      Eigen::Matrix<double, 3, 3> X_J_rot = X_J.block<3, 3>(0, 0);
      X_J_rot.transposeInPlace();
      X_J_manual.block<3, 3>(0, 0) = X_J_rot;
      //std::cout << "X_J_feath " << model.names[i] << ":\n" << X_J_manual << "\n";

      // "correcting" pin X_T
      X_T_manual.setIdentity();
      X_T_rot = model.jointPlacements[i].inverse().rotation().transpose();
      X_T_trans = model.jointPlacements[i].translation();
      X_T_manual.topLeftCorner(3, 3) = X_T_rot;
      X_T_manual.topRightCorner(3, 1) = X_T_trans;
      //std::cout << "X_T_feath " << model.names[i] << ":\n" << X_T_manual << "\n";

      X_0_manual = X_J_manual * X_T_manual;
      //std::cout << "X_0_feath " << model.names[i] << ":\n" << X_0_manual << "\n";
    }
    X_0 = data.oMi[i].toHomogeneousMatrix();
    std::cout << "X_0 " << model.names[i] << ":\n" << X_0 << "\n";
  }

  std::cout << "========================\n";

  for(size_t i = 0; i < geom_model.geometryObjects.size(); ++i) {
    const GeometryObject &geom_obj = geom_model.geometryObjects[i];

    parent_joint_id = geom_obj.parentJoint;

    // homogeneous 4x4
    X_0 = data.oMi[parent_joint_id];
    // no need to transpose 4x4 representation of pinocchio SE3 for some reason
    std::cout << "X_0: " << model.names[parent_joint_id] << "\n" << X_0 << "\n";

    // reg 3x3
    X_0_rot = data.oMi[parent_joint_id].rotation();
    X_0_trans = data.oMi[parent_joint_id].translation();

    t_sph = geom_obj.placement.translation();
    t_sph_0 = X_0_rot * t_sph + X_0_trans;

    std::cout << "sph pos nom: " << i << "\n" << t_sph << "\n";
    std::cout << "sph pos: " << i << "\n" << t_sph_0 << "\n";

    Eigen::Vector3d sphere_pos = geom_data.oMg[i].translation().transpose();
    std::cout << "ACTUAL: " << i << "\n" << sphere_pos << "\n";

    std::cout << "----------------\n";
  }

  return 0;
}
