// ignore unused header warning in IDE, this is needed
#include "matrix_layout.h"
#include "pinocchio/multibody/joint/joint-collection.hpp"
#include "pinocchio/multibody/model.hpp"
#include "pinocchio/algorithm/geometry.hpp"
#include "pinocchio/collision/collision.hpp"
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <hpp/fcl/collision_object.h>
#include <hpp/fcl/shape/geometric_shapes.h>
#include <memory>
#include <pinocchio/multibody/fwd.hpp>
#include <pinocchio/multibody/geometry.hpp>
#include <pinocchio/spatial/fwd.hpp>
#include <string>
#include "pinocchio/parsers/srdf.hpp"
#include "pinocchio/algorithm/joint-configuration.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>
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
using pinocchio::GeometryModel;

using ctup::backend::blazeVecSIMDd;

/////////////////////////////////////////////

struct Sphere {
    double center_x;
    double center_y;
    double center_z;
    double radius;
};

struct Cylinder {
    double center_x;
    double center_y;
    double center_z;
    double radius;
    double xv;
    double yv;
    double zv;
    double rdv;
    bool z_aligned;
};

struct Box {
    double center_x;
    double center_y;
    double center_z;
    double caxis_1_x;
    double caxis_1_y;
    double caxis_1_z;
    double caxis_1_r;
    double caxis_2_x;
    double caxis_2_y;
    double caxis_2_z;
    double caxis_2_r;
    double caxis_3_x;
    double caxis_3_y;
    double caxis_3_z;
    double caxis_3_r;
    bool xyz_aligned;
};

struct Envir_Objects{
    std::vector<Sphere> spheres;
    std::vector<Cylinder> cylinders;
    std::vector<Box> boxs;
};

struct Primitive {
    std::string type;
    std::vector<double> dimensions;
};

struct Pose {
    std::vector<double> position;
    std::vector<double> orientation;
};

struct CollisionObject {
    std::string id;
    Primitive primitive;
    Pose pose;
};

struct LinkSpheres {
  double coarse_x;
  double coarse_y;
  double coarse_z;
  double coarse_r;
  std::vector<double> fine_x;
  std::vector<double> fine_y;
  std::vector<double> fine_z;
  std::vector<double> fine_r;
};

namespace ctup {
template <typename Scalar>
struct Xform : public matrix_layout<Scalar> {
  using matrix_layout<Scalar>::set_entry_to_constant;
  using matrix_layout<Scalar>::set_entry_to_nonconstant;
  dyn_var<Scalar> sinq;
  dyn_var<Scalar> cosq;

  static_var<int> joint_type;
  static_var<int> joint_xform_axis;

  Xform() : matrix_layout<Scalar>(4, 4, SPARSE, FLATTENED, COMPRESSED) {
    matrix_layout<Scalar>::set_identity();
  }

  void set_revolute_axis(char axis) {
    assert((axis == 'X' || axis == 'Y' || axis == 'Z') && "axis must be X,Y,Z");
    joint_xform_axis = axis;
    joint_type = 'R';
  }

  void set_prismatic_axis(char axis) {
    assert((axis == 'X' || axis == 'Y' || axis == 'Z') && "axis must be X,Y,Z");
    joint_xform_axis = axis;
    joint_type = 'P';
  }

  void jcalc(const dyn_var<Scalar> &q_i) {
    sinq = backend::sin<Scalar>(q_i);
    cosq = backend::cos<Scalar>(q_i);

    if (joint_type == 'R') {
      if (joint_xform_axis == 'X') {
        set_entry_to_nonconstant(1, 1, cosq);
        set_entry_to_nonconstant(1, 2, sinq);
        set_entry_to_nonconstant(2, 1, -sinq);
        set_entry_to_nonconstant(2, 2, cosq);
      }
      else if (joint_xform_axis == 'Y') {
        set_entry_to_nonconstant(0, 0, cosq);
        set_entry_to_nonconstant(0, 2, -sinq);
        set_entry_to_nonconstant(2, 0, sinq);
        set_entry_to_nonconstant(2, 2, cosq);
      }
      else if (joint_xform_axis == 'Z') {
        set_entry_to_nonconstant(0, 0, cosq);
        set_entry_to_nonconstant(0, 1, sinq);
        set_entry_to_nonconstant(1, 0, -sinq);
        set_entry_to_nonconstant(1, 1, cosq);
      }
    }
    else if (joint_type == 'P') {
      // negative r-cross, opp signs of featherstone 2.23
      if (joint_xform_axis == 'X') {
        set_entry_to_nonconstant(0, 3, q_i);
      }
      else if (joint_xform_axis == 'Y') {
        set_entry_to_nonconstant(1, 3, q_i);
      }
      else if (joint_xform_axis == 'Z') {
        set_entry_to_nonconstant(2, 3, q_i);
      }
    }
    else {
      assert(false && "jcalc called on non joint xform or joint unset");
    }
  }

  using matrix_layout<Scalar>::operator=;
};
}

template <typename Scalar>
using Xform = ctup::Xform<Scalar>;

/////////////////////////////////////////////

namespace backend {
template <typename T>
struct aligned_vector_t: public builder::custom_type<T> {
  // gen/self_collision.h
  static constexpr const char* type_name = "AlignedSVd8Vector";
  typedef T dereference_type;
  dyn_var<void(int)> size = builder::with_name("size");
  dyn_var<int(void)> resize = builder::with_name("resize");
  dyn_var<T(void)> push_back = builder::with_name("push_back");
};
}

using backend::aligned_vector_t;

namespace runtime {

builder::dyn_var<int (
    // coarse sph 1
    blazeVecSIMDd&, blazeVecSIMDd&, blazeVecSIMDd&, double,
    // fine sph 1
    aligned_vector_t<blazeVecSIMDd>&, aligned_vector_t<blazeVecSIMDd>&, aligned_vector_t<blazeVecSIMDd>&, ctup::vector_t<double>&,
    // coarse sph 2 
    blazeVecSIMDd&, blazeVecSIMDd&, blazeVecSIMDd&, double,
    // fine sph 2
    aligned_vector_t<blazeVecSIMDd>&, aligned_vector_t<blazeVecSIMDd>&, aligned_vector_t<blazeVecSIMDd>&, ctup::vector_t<double>&
        )> 
    self_collision_link_vs_link = builder::as_global("runtime::self_collision_link_vs_link");
}

/////////////////////////////////////////////

static void parseCollisionObjects(const YAML::Node& collisionObjectsNode, std::vector<CollisionObject>& objects) {
  for (const auto& objNode : collisionObjectsNode) {
    CollisionObject obj;
    obj.id = objNode["id"].as<std::string>();
    
    const auto& primitiveNode = objNode["primitives"][0];
    obj.primitive.type = primitiveNode["type"].as<std::string>();
    obj.primitive.dimensions = primitiveNode["dimensions"].as<std::vector<double>>();
    
    const auto& poseNode = objNode["primitive_poses"][0];
    obj.pose.position = poseNode["position"].as<std::vector<double>>();
    obj.pose.orientation = poseNode["orientation"].as<std::vector<double>>();

    objects.push_back(obj);
  }
}

//static dyn_var<int> Sphere_Environment_Collision(
//    const Envir_Objects &obj,
//    // single coarse grained sphere per link
//    dyn_var<blazeVecSIMDd &> coarse_x, 
//    dyn_var<blazeVecSIMDd &> coarse_y, 
//    dyn_var<blazeVecSIMDd &> coarse_z, 
//    dyn_var<double> coarse_r,
//    // many fine grained spheres per link
//    dyn_var<aligned_vector_t<blazeVecSIMDd> &> fine_x, 
//    dyn_var<aligned_vector_t<blazeVecSIMDd> &> fine_y, 
//    dyn_var<aligned_vector_t<blazeVecSIMDd> &> fine_z, 
//    dyn_var<aligned_vector_t<double> &> fine_r) {
//
//}

static std::map<size_t, LinkSpheres> joint_to_child_spheres(
    const pinocchio::Model &model_coarse, 
    const pinocchio::GeometryModel &geom_model_coarse, 
    const pinocchio::Model &model_fine, 
    const pinocchio::GeometryModel &geom_model_fine,
    const std::string joint_name) {
  using namespace pinocchio;

  JointIndex jid = model_coarse.getJointId(joint_name);

  std::map<size_t, LinkSpheres> link_spheres;

  std::map<std::string, size_t> rel_link_num;
  for (size_t i = 0; i < geom_model_coarse.geometryObjects.size(); i++) {
    LinkSpheres ls;

    const GeometryObject &geom_obj = geom_model_coarse.geometryObjects[i];
    // this function does pick out the "true" actuated parent, not the fixed joint parent
    const JointIndex parent_joint_id = geom_obj.parentJoint;

    if (parent_joint_id != jid)
      continue;

    hpp::fcl::NODE_TYPE node_type = geom_obj.geometry->getNodeType();
    assert(node_type == hpp::fcl::GEOM_SPHERE && "we don't support non sphere geoms inside robot");

    Eigen::Vector3d sphere_xyz = geom_obj.placement.translation();
    double sphere_radius = std::dynamic_pointer_cast<hpp::fcl::Sphere>(geom_obj.geometry)->radius;
    std::cout << "Link: " << i << std::endl;
    ls.coarse_x = sphere_xyz[0];
    ls.coarse_y = sphere_xyz[1];
    ls.coarse_z = sphere_xyz[2]; 
    ls.coarse_r = sphere_radius;

    link_spheres[i] = ls;

    rel_link_num[(model_coarse.frames[geom_obj.parentFrame].name)] = i;
  }

  jid = model_fine.getJointId(joint_name);
  for (size_t i = 0; i < geom_model_fine.geometryObjects.size(); i++) {
    const GeometryObject &geom_obj = geom_model_fine.geometryObjects[i];
    // this function does correctly pick out the "true" actuated parent, 
    // not the fixed joint parent
    const JointIndex parent_joint_id = geom_obj.parentJoint;

    if (parent_joint_id != jid)
      continue;

    hpp::fcl::NODE_TYPE node_type = geom_obj.geometry->getNodeType();
    assert(node_type == hpp::fcl::GEOM_SPHERE && 
            "we don't support non sphere geoms inside robot");

    Eigen::Vector3d sphere_xyz = geom_obj.placement.translation();
    double sphere_radius = std::dynamic_pointer_cast<hpp::fcl::Sphere>(
            geom_obj.geometry)->radius;

    size_t link_id = rel_link_num[(model_fine.frames[geom_obj.parentFrame].name)];

    bool no_sphere_overlap = 
        sphere_xyz[0] != link_spheres[link_id].coarse_x || 
        sphere_xyz[1] != link_spheres[link_id].coarse_y || 
        sphere_xyz[2] != link_spheres[link_id].coarse_z || 
        sphere_radius != link_spheres[link_id].coarse_r;

    if (no_sphere_overlap) {
      link_spheres[link_id].fine_x.push_back(sphere_xyz[0]);
      link_spheres[link_id].fine_y.push_back(sphere_xyz[1]);
      link_spheres[link_id].fine_z.push_back(sphere_xyz[2]);
      link_spheres[link_id].fine_r.push_back(sphere_radius);
    }
  }

  return link_spheres;
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

static size_t get_max_n_fine_sph(
    const pinocchio::Model &model_coarse, 
    const pinocchio::GeometryModel &geom_model_coarse, 
    const pinocchio::Model &model_fine, 
    const pinocchio::GeometryModel &geom_model_fine) {
  typedef typename Model::JointIndex JointIndex;

  size_t max_n_fine_sph = 0;

  for (JointIndex i = 1; i < (JointIndex)model_coarse.njoints; i++) {
    std::string joint_name = model_coarse.names[i];
    std::map<size_t, LinkSpheres> link_spheres = joint_to_child_spheres(
            model_coarse, geom_model_coarse,
            model_fine, geom_model_fine,
            joint_name);
    // each joint may have multiple links associated with it
    for (const auto &pair : link_spheres) {
      size_t link_id = pair.first; 
      size_t curr_n_fine_sph = link_spheres[link_id].fine_r.size();
      if (curr_n_fine_sph > max_n_fine_sph) {
        max_n_fine_sph = curr_n_fine_sph;
      }
    }
  }
  return max_n_fine_sph;
}

static void set_X_T(builder::array<Xform<blazeVecSIMDd>>& X_T, const Model &model) {
  typedef typename Model::JointIndex JointIndex;
  static_var<JointIndex> i;

  static_var<size_t> r;
  static_var<size_t> c;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    Eigen::Matrix<double, 4, 4> pin_X_T = model.jointPlacements[i];

    // setting E
    for (r = 0; r < 4; r = r + 1) {
      for (c = 0; c < 4; c = c + 1) {
        double entry = pin_X_T.coeffRef(c, r);
        if (std::abs(entry) < 1e-5)
          X_T[i].set_entry_to_constant(r, c, 0);
        else
          X_T[i].set_entry_to_constant(r, c, entry);
      }
    }
  }
}

static dyn_var<int> fkcc(
    const pinocchio::Model &model_coarse, 
    const pinocchio::GeometryModel &geom_model_coarse, 
    const pinocchio::Model &model_fine, 
    const pinocchio::GeometryModel &geom_model_fine,
    dyn_var<aligned_vector_t<blazeVecSIMDd>&> q) {
  typedef typename Model::JointIndex JointIndex;

  // joint transforms for FK
  builder::array<Xform<blazeVecSIMDd>> X_T;
  builder::array<Xform<blazeVecSIMDd>> X_J;
  builder::array<Xform<blazeVecSIMDd>> X_0;

  X_T.set_size(model_coarse.njoints);
  X_J.set_size(model_coarse.njoints);
  X_0.set_size(model_coarse.njoints);

  // coarse collision geom sphere positions
  // storing one coarse sphere per link
  dyn_var<blazeVecSIMDd[]> coarse_x_0, coarse_y_0, coarse_z_0;
  dyn_var<double[]> coarse_r;

  size_t n_coarse_sph = geom_model_coarse.geometryObjects.size();
  resize_arr(coarse_x_0, n_coarse_sph);
  resize_arr(coarse_y_0, n_coarse_sph);
  resize_arr(coarse_z_0, n_coarse_sph);
  resize_arr(coarse_r, n_coarse_sph);

  // fine collision geom sphere positions
  dyn_var<aligned_vector_t<blazeVecSIMDd>> fine_x_0, fine_y_0, fine_z_0, fine_r;
  // we rewrite to the same array, so we size the array to have
  // the max number of fine spheres present for a single link
  size_t max_n_fine_sph = get_max_n_fine_sph(
          model_coarse, geom_model_coarse, model_fine, geom_model_fine);
  fine_x_0.resize(max_n_fine_sph);
  fine_y_0.resize(max_n_fine_sph);
  fine_z_0.resize(max_n_fine_sph);
  fine_r.resize(max_n_fine_sph);

  // data structure for storing intermediate self collision fine spheres in forward prop order
  // storing vector of fine spheres per link
  dyn_var<aligned_vector_t<blazeVecSIMDd>[]> sc_x, sc_y, sc_z;
  dyn_var<aligned_vector_t<double>[]> sc_r;

  resize_arr(sc_x, model_coarse.njoints);
  resize_arr(sc_y, model_coarse.njoints);
  resize_arr(sc_z, model_coarse.njoints);
  resize_arr(sc_r, model_coarse.njoints);

  static_var<JointIndex> i;

  set_X_T(X_T, model_coarse);

  static_var<int> jtype;
  static_var<int> axis;

  for (i = 1; i < (JointIndex)model_coarse.njoints; i = i+1) {
    jtype = get_jtype(model_coarse, i);
    axis = get_joint_axis(model_coarse, i);

    if (jtype == 'R') {
      X_J[i].set_revolute_axis(axis);
    }
    if (jtype == 'P') {
      X_J[i].set_prismatic_axis(axis);
    }
  }

  Xform<blazeVecSIMDd> X_pi;

  static_var<JointIndex> parent;
  std::string joint_name;

  for (i = 1; i < (JointIndex)model_coarse.njoints; i = i+1) {
    X_J[i].jcalc(q[i-1]);

    X_pi = X_J[i] * X_T[i];
    parent = model_coarse.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = ctup::matrix_layout_expr_leaf<blazeVecSIMDd>(X_pi);
    }

    joint_name = model_coarse.names[i];
    std::cout << joint_name << std::endl;

    // X_0 now contains the global transform of the joint wrt the world

    std::map<size_t, LinkSpheres> link_spheres = joint_to_child_spheres(
            model_coarse, geom_model_coarse,
            model_fine, geom_model_fine,
            joint_name);

    std::map<size_t, LinkSpheres>::iterator outerIt;

    // we now transform the nominal transform of each sphere wrt its joint by X_0
    // to get the global transform of each sphere wrt the world
    // X_0_sph = X_0_j * X_j_sph
    // in code: coarse_0[link_id] = X_0 * link_spheres[link_id]

    for (static_var<size_t> pair_idx = 0; pair_idx < link_spheres.size(); pair_idx = pair_idx+1) {
      outerIt = link_spheres.begin();
      std::advance(outerIt, pair_idx);
      size_t link_id = outerIt->first;
      std::cout << link_id << std::endl;

      coarse_x_0[link_id] = 
          X_0[i].get_entry(0,0) * link_spheres[link_id].coarse_x +
          X_0[i].get_entry(1,0) * link_spheres[link_id].coarse_y +
          X_0[i].get_entry(2,0) * link_spheres[link_id].coarse_z;

      coarse_y_0[link_id] = 
          X_0[i].get_entry(0,1) * link_spheres[link_id].coarse_x +
          X_0[i].get_entry(1,1) * link_spheres[link_id].coarse_y +
          X_0[i].get_entry(2,1) * link_spheres[link_id].coarse_z;

      coarse_z_0[link_id] = 
          X_0[i].get_entry(0,2) * link_spheres[link_id].coarse_x +
          X_0[i].get_entry(1,2) * link_spheres[link_id].coarse_y +
          X_0[i].get_entry(2,2) * link_spheres[link_id].coarse_z;

      // translation component
      coarse_x_0[link_id] += X_0[i].get_entry(0,3);
      coarse_y_0[link_id] += X_0[i].get_entry(1,3);
      coarse_z_0[link_id] += X_0[i].get_entry(2,3);

      coarse_r[link_id] = link_spheres[link_id].coarse_r;

      static_var<size_t> n_fine_sph = link_spheres[link_id].fine_r.size();

      // for fine grained sphere geoms
      for(static_var<size_t> k = 0; k < n_fine_sph; k = k+1){
        fine_x_0[k] = 
            X_0[i].get_entry(0,0) * link_spheres[link_id].fine_x[k] +
            X_0[i].get_entry(1,0) * link_spheres[link_id].fine_y[k] +
            X_0[i].get_entry(2,0) * link_spheres[link_id].fine_z[k];

        fine_y_0[k] = 
            X_0[i].get_entry(0,1) * link_spheres[link_id].fine_x[k] +
            X_0[i].get_entry(1,1) * link_spheres[link_id].fine_y[k] +
            X_0[i].get_entry(2,1) * link_spheres[link_id].fine_z[k];

        fine_z_0[k] = 
            X_0[i].get_entry(0,2) * link_spheres[link_id].fine_x[k] +
            X_0[i].get_entry(1,2) * link_spheres[link_id].fine_y[k] +
            X_0[i].get_entry(2,2) * link_spheres[link_id].fine_z[k];

        fine_x_0[k] += X_0[i].get_entry(0,3);
        fine_y_0[k] += X_0[i].get_entry(1,3);
        fine_z_0[k] += X_0[i].get_entry(2,3);

        fine_r[k] = link_spheres[link_id].fine_r[k];
      }

      dyn_var<int> cc_res;

      for(static_var<size_t> cp_it = 0; cp_it < geom_model_coarse.collisionPairs.size(); cp_it = cp_it+1) {
        const pinocchio::CollisionPair & cp = geom_model_coarse.collisionPairs[cp_it];
        if (cp.second == link_id) {
          std::cout << "collision pair: " << cp.first << "," << cp.second << std::endl;
          std::string cp_str = "collision pair: ";
          cp_str += std::to_string(cp.first) + "," + std::to_string(cp.second);
          builder::annotate(cp_str.c_str());

          // 2-level self collision checking per link
          // we first CC the two coarse spheres associated w the cp
          // if they're in collision, we CC two sets of fine spheres
          // associated w the cp
          cc_res = runtime::self_collision_link_vs_link(
              // coarse sphere assoc. w cp.second
              coarse_x_0[link_id], coarse_y_0[link_id], coarse_z_0[link_id], coarse_r[link_id], 
              // fine spheres assoc. w cp.second
              fine_x_0, fine_y_0, fine_z_0, fine_r, 
              // coarse sphere assoc. w cp.first
              coarse_x_0[cp.first], coarse_y_0[cp.first], coarse_z_0[cp.first], coarse_r[cp.first], 
              // fine spheres assoc. w cp.first
              sc_x[cp.first], sc_y[cp.first], sc_z[cp.first], sc_r[cp.first]);
          // return cc_res // can't do this because static_var bug
        }
      }
      // if we find no self collision, we do a two-level CC of each link against the environment
      //cc_res = ctup::backend::Sphere_Environment_Collision(
      //        coarse_x_0[link_id], coarse_y_0[link_id], coarse_z_0[link_id], coarse_r[link_id],
      //        fine_x_0, fine_y_0, fine_z_0, fine_r);
      // return cc_res // can't do this because static_var bug

      // if cc_res is not in collision, we store the current global position of fine grained spheres corres. to link_id
      // we're exploiting the fact that we don't need to recalculate 
      // parent link global positions when iterating down the chain in FK
      sc_x[link_id] = fine_x_0;
      sc_y[link_id] = fine_y_0;
      sc_z[link_id] = fine_z_0;
      sc_r[link_id] = fine_r;
    }
  }

  return 0;
}

int main(int argc, char* argv[]) {
  //--------------------------
  //LOAD URDF FILE
  //--------------------------

  // Path to the URDF file 1
  const char* urdf_filename = argv[1];
  std::cout << urdf_filename << "\n";

  const char* urdf_filename_2 = argv[2];
  std::cout << urdf_filename_2 << "\n";
  //--------------------------
  //END LOAD URDF FILE
  //--------------------------

  //--------------------------
  //LOAD YAML FILE
  //--------------------------
  const std::string yaml_filename = argv[3];
  std::cout << yaml_filename << "\n";

  YAML::Node root = YAML::LoadFile(yaml_filename);
  // Parse collision objects
  std::vector<CollisionObject> collisionObjects;
  if (root["world"] && root["world"]["collision_objects"]) {
      parseCollisionObjects(root["world"]["collision_objects"], collisionObjects);
  } else {
      std::cerr << "No collision objects found in the YAML file." << std::endl;
      return 1;
  }
  std::vector<Sphere> spheres;
  std::vector<Cylinder> cylinders;
  std::vector<Box> boxs;
  Envir_Objects env_obj;
  for (const auto& obj : collisionObjects) {
      if(obj.primitive.type=="box"){
          Box a;
          a.center_x=obj.pose.position[0];
          a.center_y=obj.pose.position[1];
          a.center_z=obj.pose.position[2];

          a.caxis_1_r=obj.primitive.dimensions[0];
          a.caxis_2_r=obj.primitive.dimensions[1];
          a.caxis_3_r=obj.primitive.dimensions[2];

          if(obj.pose.orientation[0]==0 && obj.pose.orientation[1]==0 && obj.pose.orientation[2]==0 && obj.pose.orientation[3]==1){
              a.caxis_1_x=1;
              a.caxis_1_y=0;
              a.caxis_1_z=0;
              
              a.caxis_2_x=0;
              a.caxis_2_y=1;
              a.caxis_2_z=0;

              a.caxis_3_x=0;
              a.caxis_3_y=0;
              a.caxis_3_z=1;

              a.xyz_aligned=true;
          }
          else{
              std::cout << "  Not alligned ";
              std::cout << std::endl;
              // TO DO
          }

          boxs.push_back(a);
      }
      else if(obj.primitive.type=="cylinder"){
          Cylinder a;
          a.center_x=obj.pose.position[0];
          a.center_y=obj.pose.position[1];
          a.center_z=obj.pose.position[2];

          a.radius=obj.primitive.dimensions[0];
          a.rdv=obj.primitive.dimensions[1];

          if(obj.pose.orientation[0]==0 && obj.pose.orientation[1]==0 && obj.pose.orientation[2]==0 && obj.pose.orientation[3]==1){
              a.z_aligned=true;
          }
          a.xv=obj.pose.orientation[0];
          a.yv=obj.pose.orientation[1];
          a.zv=obj.pose.orientation[2];

          cylinders.push_back(a);
      }
  }

  env_obj.spheres=spheres;
  env_obj.cylinders=cylinders;
  env_obj.boxs=boxs;
  //--------------------------
  //END LOAD YAML FILE
  //--------------------------

  const std::string header_filename = (argc <= 5) ? "./fk_gen.h" : argv[5];
  std::cout << header_filename << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  GeometryModel geom_model;
  pinocchio::urdf::buildGeom(model, urdf_filename, pinocchio::COLLISION, geom_model);

  geom_model.addAllCollisionPairs();
  const std::string srdf_filename = argv[4];
  pinocchio::srdf::removeCollisionPairs(model, geom_model, srdf_filename);

  Model model_2;
  GeometryModel geom_model_2;
  pinocchio::urdf::buildModel(urdf_filename_2, model_2);
  pinocchio::urdf::buildGeom(model_2, urdf_filename_2, pinocchio::COLLISION, geom_model_2);

  //joint_to_spheres(model, geom_model, model_2, geom_model_2, "wrist_3_joint");
  //std::cout<<"---------------"<<std::endl;
  /*
  for(size_t k = 0; k < geom_model.collisionPairs.size(); ++k)
  {
    const pinocchio::CollisionPair & cp = geom_model.collisionPairs[k];
    std::cout << "collision pair: " << cp.first << " , " << cp.second<<std::endl;
  }
  */

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  of << "#include \"blaze/Math.h\"\n\n";
  of << "#include \"self_collision.h\"\n\n";
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

  //of << "static ";
  //auto ast = context.extract_function_ast(Sphere_Environment_Collision, "Sphere_Environment_Collision", env_obj);
  //block::c_code_generator::generate_code(ast, of, 0);
  of << "static ";
  auto ast = context.extract_function_ast(fkcc, "fkcc", model, geom_model, model_2, geom_model_2);
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
