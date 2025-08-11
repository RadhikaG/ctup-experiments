#include <memory>
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/collision/collision.hpp"
#include "pin_collision.h"
#include "pin_shapes.h"

namespace ctup_runtime {

namespace pin_compat {

/////////// Impl ////////////////

struct PinFKCC::Impl {
  // coarse
  pinocchio::Model pin_model_coarse;
  pinocchio::Data pin_data_coarse;
  pinocchio::GeometryModel pin_geom_model_coarse;
  pinocchio::GeometryData pin_geom_data_coarse;

  // fine
  pinocchio::Model pin_model_fine;
  pinocchio::Data pin_data_fine;
  pinocchio::GeometryModel pin_geom_model_fine;
  pinocchio::GeometryData pin_geom_data_fine;

  // environment
  std::vector<std::shared_ptr<hpp::fcl::CollisionObject>> pin_env;

  Impl(std::string robot_name, const vamp::collision::Environment<float> &vamp_env);

  template <size_t ndim>
  bool fkcc_pin(const ConfigurationBlockDimEigen<ndim> &q_block);
};

PinFKCC::Impl::Impl(std::string robot_name, const vamp::collision::Environment<float> &vamp_env) {
  ////////////// setting URDF and SRDF filepaths ////

  std::string urdf_filename_coarse, urdf_filename_fine;
  std::string srdf_filename;
  std::string pin_model_path;

  if (robot_name == "panda") {
    // todo: change to relative paths later
    urdf_filename_coarse = "/home/ubuntu/ctup_stuff/ctup-experiments/models/panda/panda_spherized_1.urdf";
    urdf_filename_fine = "/home/ubuntu/ctup_stuff/ctup-experiments/models/panda/panda_spherized.urdf";
    srdf_filename = "/home/ubuntu/ctup_stuff/ctup-experiments/models/panda/panda.srdf";
    pin_model_path = "/home/ubuntu/ctup_stuff/ctup-experiments/models/panda/";
  }
  else {
    assert(false && "unimplemented for non-panda robots");
  }

  ////////////// coarse model setup /////////////////

  pinocchio::urdf::buildModel(urdf_filename_coarse, pin_model_coarse);

  pin_data_coarse = pinocchio::Data(pin_model_coarse);

  pinocchio::urdf::buildGeom(
          pin_model_coarse, 
          urdf_filename_coarse, 
          pinocchio::COLLISION, 
          pin_geom_model_coarse, 
          pin_model_path);

  pin_geom_model_coarse.addAllCollisionPairs();
  pinocchio::srdf::removeCollisionPairs(pin_model_coarse, pin_geom_model_coarse, srdf_filename);

  pin_geom_data_coarse = pinocchio::GeometryData(pin_geom_model_coarse);

  ////////////// fine model setup /////////////////

  pinocchio::urdf::buildModel(urdf_filename_fine, pin_model_fine);

  pin_data_fine = pinocchio::Data(pin_model_fine);

  pinocchio::urdf::buildGeom(
          pin_model_fine, 
          urdf_filename_fine, 
          pinocchio::COLLISION, 
          pin_geom_model_fine, 
          pin_model_path);

  pin_geom_model_fine.addAllCollisionPairs();
  pinocchio::srdf::removeCollisionPairs(pin_model_fine, pin_geom_model_fine, srdf_filename);

  pin_geom_data_fine = pinocchio::GeometryData(pin_geom_model_fine);

  ////////////// environment setup /////////////////

  // spheres
  for (auto &sph : vamp_env.spheres) {
    pin_env.push_back(to_fcl_sphere(sph));
  }

  // cuboids/boxes
  for (auto &b : vamp_env.cuboids) {
    pin_env.push_back(to_fcl_box(b));
  }

  // cylinders
  for (auto &cyl : vamp_env.cylinders) {
    pin_env.push_back(to_fcl_cylinder(cyl));
  }

  // capsules
  for (auto &cap : vamp_env.capsules) {
    pin_env.push_back(to_fcl_capsule(cap));
  }

  assert(vamp_env.z_aligned_capsules.size() == 0 && "pin fkcc doesn't support z aligned capsules");
  assert(vamp_env.z_aligned_cuboids.size() == 0 && "pin fkcc doesn't support z aligned cuboids");
  assert(vamp_env.heightfields.size() == 0 && "pin fkcc doesn't support heightfields");
}

template <size_t ndim>
bool PinFKCC::Impl::fkcc_pin(const ConfigurationBlockDimEigen<ndim> &q_block) {
  bool is_coarse_collide = false;
  bool is_fine_collide = false;

  // we know q_block is of length 8 ahead of time
  const size_t B = 8;
  for (size_t b = 0; b < B; b++) {
    pinocchio::Model::ConfigVectorType q(pin_model_coarse.nq);
    q << q_block[b].template cast<double>();

    // coarse self collision check
    is_coarse_collide = pinocchio::computeCollisions(
        pin_model_coarse, 
        pin_data_coarse,
        pin_geom_model_coarse,
        pin_geom_data_coarse,
        q,
        true
    );

    if (!is_coarse_collide) {
      // configuration is wholely collision free
      // continue check rest of configs
      continue;
    }

    // fine self collision check
    is_fine_collide = pinocchio::computeCollisions(
        pin_model_fine, 
        pin_data_fine,
        pin_geom_model_fine,
        pin_geom_data_fine,
        q,
        true
    );

    if (is_fine_collide)
      return false;

    pinocchio::updateGeometryPlacements(pin_model_fine, pin_data_fine,
        pin_geom_model_fine, pin_geom_data_fine);

    // fine environment check
    for (size_t r_i = 0; r_i < pin_geom_model_fine.geometryObjects.size(); r_i++) {
      const auto &geom = pin_geom_model_fine.geometryObjects[r_i];
      const auto &pose = pin_geom_data_fine.oMg[r_i];
      pinocchio::CollisionObject r_obj(geom.geometry, pose);

      for (const auto &obj : pin_env) {
        hpp::fcl::CollisionRequest req;
        hpp::fcl::CollisionResult res;
        hpp::fcl::collide(&r_obj, obj.get(), req, res);
        if (res.isCollision())
          return false;
      }
    }
  }

  // if control flow reaches here then no collision was found
  return true;
}

/////////// Interface ////////////////

PinFKCC::PinFKCC(std::string robot_name,
                 const vamp::collision::Environment<float>& vamp_env)
	: impl_(std::make_unique<Impl>(robot_name, vamp_env)) {}

template <size_t ndim>
bool PinFKCC::fkcc_pin(const ConfigurationBlockDimEigen<ndim> &q_block) {
  return impl_->fkcc_pin<ndim>(q_block);
}

PinFKCC::~PinFKCC() = default;

// explicit template instantiation because we defined template function
// in cpp
template bool PinFKCC::fkcc_pin<7>(const ConfigurationBlockDimEigen<7>&);
 
}

}
