#include <memory>
#include <pinocchio/multibody/geometry-object.hpp>
#include "pinocchio/parsers/urdf.hpp"
#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/collision/collision.hpp"
#include "pin_collision.h"
#include "pin_shapes.h"
#include <iostream>

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

  Impl();
  Impl(std::string robot_name, const vamp::collision::Environment<float> &vamp_env);

  template <size_t ndim>
  bool fkcc_pin(const ConfigurationBlockDimEigen<ndim> &q_block);

  std::map<size_t, std::vector<size_t>> coarse_geom_id_to_fine_geom_ids;

  void map_coarse_to_fine();
};

PinFKCC::Impl::Impl() {}

PinFKCC::Impl::Impl(std::string robot_name, const vamp::collision::Environment<float> &vamp_env) {
  ////////////// setting URDF and SRDF filepaths ////

  std::string urdf_filename_coarse, urdf_filename_fine;
  std::string srdf_filename;
  std::string pin_model_path;

  std::string CTUP_ROOT = "/home/ubuntu/ctup_stuff/ctup-experiments/";

  if (robot_name == "panda") {
    // todo: change to relative paths later
    urdf_filename_coarse = CTUP_ROOT + "models/panda/panda_spherized_1.urdf";
    urdf_filename_fine = CTUP_ROOT + "models/panda/panda_spherized.urdf";
    srdf_filename = CTUP_ROOT + "models/panda/panda.srdf";
    pin_model_path = CTUP_ROOT + "models/panda/";
  }
  else if (robot_name == "baxter") {
    // todo: change to relative paths later
    urdf_filename_coarse = CTUP_ROOT + "models/baxter/baxter_spherized_1.urdf";
    urdf_filename_fine = CTUP_ROOT + "models/baxter/baxter_spherized.urdf";
    srdf_filename = CTUP_ROOT + "models/baxter/baxter.srdf";
    pin_model_path = CTUP_ROOT + "models/baxter/";
  }
  else if (robot_name == "fetch") {
    // todo: change to relative paths later
    urdf_filename_coarse = CTUP_ROOT + "models/fetch/fetch_spherized_1.urdf";
    urdf_filename_fine = CTUP_ROOT + "models/fetch/fetch_spherized.urdf";
    srdf_filename = CTUP_ROOT + "models/fetch/fetch.srdf";
    pin_model_path = CTUP_ROOT + "models/fetch/";
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

  map_coarse_to_fine();

  ////////////// environment setup /////////////////

  // spheres
  for (auto &sph : vamp_env.spheres) {
    pin_env.push_back(to_fcl_sphere(sph));
  }

  // cuboids/boxes
  for (auto &b : vamp_env.cuboids) {
    pin_env.push_back(to_fcl_box(b));
  }

  // vamp just skips certain math when cuboids are z-aligned
  // the objects themselves are still cuboids
  for (auto &b : vamp_env.z_aligned_cuboids) {
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

  for (auto &cap : vamp_env.z_aligned_capsules) {
    pin_env.push_back(to_fcl_capsule(cap));
  }

  assert(vamp_env.heightfields.size() == 0 && "pin fkcc doesn't support heightfields");
}

void PinFKCC::Impl::map_coarse_to_fine() {
  for (size_t c_i = 0; c_i < pin_geom_model_coarse.geometryObjects.size(); c_i++ ) {
    const pinocchio::GeometryObject &c_obj = pin_geom_model_coarse.geometryObjects[c_i];

    const pinocchio::FrameIndex c_par_jid = c_obj.parentJoint;
    const pinocchio::FrameIndex c_par_fid = c_obj.parentFrame;

    std::string c_par_fname = pin_model_coarse.frames[c_par_fid].name;

    for (size_t f_i = 0; f_i < pin_geom_model_fine.geometryObjects.size(); f_i++) {
      const pinocchio::GeometryObject &f_obj = pin_geom_model_fine.geometryObjects[f_i];

      const pinocchio::FrameIndex f_par_jid = f_obj.parentJoint;
      const pinocchio::FrameIndex f_par_fid = f_obj.parentFrame;

      std::string f_par_fname = pin_model_fine.frames[f_par_fid].name;

      if (f_par_fname == c_par_fname) {
        assert(f_par_fid == c_par_fid && "should be same number of links in coarse and fine models");
        assert(f_par_jid == c_par_jid && "joint ids should match up");
        coarse_geom_id_to_fine_geom_ids[c_i].push_back(f_i);
      }
    }

    //std::cout << c_i << ": [";
    //for (size_t f_i : coarse_geom_id_to_fine_geom_ids[c_i]) {
    //  std::cout << f_i << ",";
    //}
    //std::cout << "]\n";
  }
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

    //pinocchio::updateGeometryPlacements(pin_model_fine, pin_data_fine,
    //    pin_geom_model_fine, pin_geom_data_fine);

    // coarse environment check
    for (size_t c_i = 0; c_i < pin_geom_model_coarse.geometryObjects.size(); c_i++) {
      const auto &c_sph = pin_geom_model_coarse.geometryObjects[c_i];
      const auto &c_pose = pin_geom_data_coarse.oMg[c_i];
      hpp::fcl::CollisionRequest c_req;
      hpp::fcl::CollisionResult c_res;

      pinocchio::CollisionObject c_obj(c_sph.geometry, c_pose);

      for (const auto &e_obj : pin_env) {
        hpp::fcl::collide(&c_obj, e_obj.get(), c_req, c_res);

        if (c_res.isCollision()) {
          // coarse collision, now check fine
          // fine check for each collision sphere corres. to coarse
          for (size_t f_i : coarse_geom_id_to_fine_geom_ids[c_i]) {
            const auto &f_sph = pin_geom_model_fine.geometryObjects[f_i];
            const auto &f_pose = pin_geom_data_fine.oMg[f_i];
            pinocchio::CollisionObject f_obj(f_sph.geometry, f_pose);

            hpp::fcl::CollisionRequest f_req;
            hpp::fcl::CollisionResult f_res;

            hpp::fcl::collide(&f_obj, e_obj.get(), f_req, f_res);

            if (f_res.isCollision())
              return false;
          }
        }
      }
    }
  }

  // if control flow reaches here then no collision was found
  return true;
}

/////////// Interface ////////////////

PinFKCC::PinFKCC()
	: impl_(std::make_unique<Impl>()) {}

PinFKCC::PinFKCC(std::string robot_name,
                 const vamp::collision::Environment<float>& vamp_env)
	: impl_(std::make_unique<Impl>(robot_name, vamp_env)) {}

template <size_t ndim>
bool PinFKCC::fkcc_pin(const ConfigurationBlockDimEigen<ndim> &q_block) {
  return impl_->fkcc_pin<ndim>(q_block);
}

PinFKCC::~PinFKCC() = default;

// Default move semantics
PinFKCC::PinFKCC(PinFKCC &&other) noexcept = default;
PinFKCC& PinFKCC::operator=(PinFKCC &&other) noexcept = default;

// explicit template instantiation because we defined template function
// in cpp
template bool PinFKCC::fkcc_pin<3>(const ConfigurationBlockDimEigen<3>&);
template bool PinFKCC::fkcc_pin<6>(const ConfigurationBlockDimEigen<6>&);
template bool PinFKCC::fkcc_pin<7>(const ConfigurationBlockDimEigen<7>&);
template bool PinFKCC::fkcc_pin<8>(const ConfigurationBlockDimEigen<8>&);
template bool PinFKCC::fkcc_pin<14>(const ConfigurationBlockDimEigen<14>&);
 
}

}
