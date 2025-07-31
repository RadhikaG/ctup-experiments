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
#include <ostream>
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

using ctup::backend::blaze_avx256f;

/////////////////////////////////////////////

struct Sphere {
    float center_x;
    float center_y;
    float center_z;
    float radius;
};

struct Cylinder {
    float center_x;
    float center_y;
    float center_z;
    float radius;
    float xv;
    float yv;
    float zv;
    float rdv;
    bool z_aligned;
};

struct Box {
    float center_x;
    float center_y;
    float center_z;
    float caxis_1_x;
    float caxis_1_y;
    float caxis_1_z;
    float caxis_1_r;
    float caxis_2_x;
    float caxis_2_y;
    float caxis_2_z;
    float caxis_2_r;
    float caxis_3_x;
    float caxis_3_y;
    float caxis_3_z;
    float caxis_3_r;
    bool xyz_aligned;
};

struct Envir_Objects{
    std::vector<Sphere> spheres;
    std::vector<Cylinder> cylinders;
    std::vector<Box> boxs;
};

struct Primitive {
    std::string type;
    std::vector<float> dimensions;
};

struct Pose {
    std::vector<float> position;
    std::vector<float> orientation;
};

struct CollisionObject {
    std::string id;
    Primitive primitive;
    Pose pose;
};

struct LinkSpheres {
  float coarse_x;
  float coarse_y;
  float coarse_z;
  float coarse_r;
  std::vector<float> fine_x;
  std::vector<float> fine_y;
  std::vector<float> fine_z;
  std::vector<float> fine_r;
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
      // switching to pinocchio transpose repr because
      // regular featherstone notation isn't working with
      // homogeneous transforms for some godforesaken reason.
      // suspect it has sth to do with the X_T that pinocchio
      // is spitting out.
      // reverse the signs of the sines for feath (hah)
      if (joint_xform_axis == 'X') {
        set_entry_to_nonconstant(1, 1, cosq);
        set_entry_to_nonconstant(1, 2, -sinq);
        set_entry_to_nonconstant(2, 1, sinq);
        set_entry_to_nonconstant(2, 2, cosq);
      }
      else if (joint_xform_axis == 'Y') {
        set_entry_to_nonconstant(0, 0, cosq);
        set_entry_to_nonconstant(0, 2, sinq);
        set_entry_to_nonconstant(2, 0, -sinq);
        set_entry_to_nonconstant(2, 2, cosq);
      }
      else if (joint_xform_axis == 'Z') {
        set_entry_to_nonconstant(0, 0, cosq);
        set_entry_to_nonconstant(0, 1, -sinq);
        set_entry_to_nonconstant(1, 0, sinq);
        set_entry_to_nonconstant(1, 1, cosq);
      }
    }
    else if (joint_type == 'P') {
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
///// DEBUG HELPERS

builder::dyn_var<void(ctup::BlazeStaticMatrix<float> &)> print_matrix = builder::as_global("print_matrix");
builder::dyn_var<void(char *)> print_string = builder::as_global("print_string");

template <typename Scalar>
static void print_Xmat(std::string prefix, Xform<Scalar> &xform) {
  print_string(prefix.c_str());
  print_matrix(xform.denseify());
}

/////////////////////////////////////////////

namespace backend {

template <typename T>
struct aligned_vector_t: public builder::custom_type<T> {
  static constexpr const char* type_name = "ctup_runtime::AlignedVec";
  typedef T dereference_type;
  dyn_var<void(int)> size = builder::with_name("size");
  dyn_var<int(void)> resize = builder::with_name("resize");
  dyn_var<T(void)> push_back = builder::with_name("push_back");
};

template <typename T>
void set_inner_size_arr(dyn_var<ctup::std_array_t<T>[]> &arr, size_t std_array_size) {
  auto type_inner = block::to<block::array_type>(arr.block_var->var_type);
  auto type = block::to<block::named_type>(type_inner->element_type);
  auto s = std::make_shared<block::named_type>();
  s->type_name = std::to_string(std_array_size);
  type->template_args.push_back(s);
}

}

using ctup::std_array_t;

namespace runtime {

namespace robots {
constexpr char robots_ur5_name[] = "ctup_runtime::robots::UR5";
using UR5 = typename builder::name<robots_ur5_name>;

constexpr char robots_panda_name[] = "ctup_runtime::robots::Panda";
using Panda = typename builder::name<robots_panda_name>;

constexpr char robots_baxter_name[] = "ctup_runtime::robots::Baxter";
using Baxter = typename builder::name<robots_baxter_name>;

constexpr char robots_fetch_name[] = "ctup_runtime::robots::Fetch";
using Fetch = typename builder::name<robots_fetch_name>;
}

constexpr char environment_t_name[] = "vamp::collision::Environment";
template <typename DataT>
using environment_t = typename builder::name<environment_t_name, DataT>;

constexpr char configuration_block_robot_name[] = "ctup_runtime::ConfigurationBlockRobot";
template <typename RobotT>
using configuration_block_robot_t = typename builder::name<configuration_block_robot_name, RobotT>;

builder::dyn_var<int (
    // geom_id_1, helpful for debug
    size_t,
    // coarse sph 1
    blaze_avx256f&, blaze_avx256f&, blaze_avx256f&, float,
    // # of fine sphs 1
    size_t,
    // fine sph 1
    std_array_t<blaze_avx256f>&, std_array_t<blaze_avx256f>&, std_array_t<blaze_avx256f>&, std_array_t<float>&,
    // geom_id_2, helpful for debug
    size_t,
    // coarse sph 2 
    blaze_avx256f&, blaze_avx256f&, blaze_avx256f&, float,
    // # of fine sphs 2
    size_t,
    // fine sph 2
    std_array_t<blaze_avx256f>&, std_array_t<blaze_avx256f>&, std_array_t<blaze_avx256f>&, std_array_t<float>&
        )> 
    self_collision_link_vs_link = builder::as_global("ctup_runtime::self_collision_link_vs_link");

builder::dyn_var<int (
    // coarse sph
    blaze_avx256f&, blaze_avx256f&, blaze_avx256f&, float,
    // # of fine sphs
    size_t,
    // fine sphs
    std_array_t<blaze_avx256f>&, std_array_t<blaze_avx256f>&, std_array_t<blaze_avx256f>&, std_array_t<float>&,
    // vamp environment type
    environment_t<blaze_avx256f>
        )>
    link_vs_environment_collision = builder::as_global("ctup_runtime::link_vs_environment_collision");

}

/////////////////////////////////////////////

static void parseCollisionObjects(const YAML::Node& collisionObjectsNode, std::vector<CollisionObject>& objects) {
  for (const auto& objNode : collisionObjectsNode) {
    CollisionObject obj;
    obj.id = objNode["id"].as<std::string>();
    
    const auto& primitiveNode = objNode["primitives"][0];
    obj.primitive.type = primitiveNode["type"].as<std::string>();
    obj.primitive.dimensions = primitiveNode["dimensions"].as<std::vector<float>>();
    
    const auto& poseNode = objNode["primitive_poses"][0];
    obj.pose.position = poseNode["position"].as<std::vector<float>>();
    obj.pose.orientation = poseNode["orientation"].as<std::vector<float>>();

    objects.push_back(obj);
  }
}

//static dyn_var<int> Sphere_Environment_Collision(
//    const Envir_Objects &obj,
//    // single coarse grained sphere per link
//    dyn_var<blaze_avx256f &> coarse_x, 
//    dyn_var<blaze_avx256f &> coarse_y, 
//    dyn_var<blaze_avx256f &> coarse_z, 
//    dyn_var<float> coarse_r,
//    // many fine grained spheres per link
//    dyn_var<aligned_vector_t<blaze_avx256f> &> fine_x, 
//    dyn_var<aligned_vector_t<blaze_avx256f> &> fine_y, 
//    dyn_var<aligned_vector_t<blaze_avx256f> &> fine_z, 
//    dyn_var<aligned_vector_t<float> &> fine_r) {
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
    float sphere_radius = std::dynamic_pointer_cast<hpp::fcl::Sphere>(geom_obj.geometry)->radius;
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
    float sphere_radius = std::dynamic_pointer_cast<hpp::fcl::Sphere>(
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

static void set_X_T(builder::array<Xform<blaze_avx256f>>& X_T, const Model &model) {
  typedef typename Model::JointIndex JointIndex;
  static_var<JointIndex> i;

  static_var<size_t> r;
  static_var<size_t> c;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    // todo: understand what the heck is this outputing
    // for homogeneous transforms
    Eigen::Matrix<double, 4, 4> pin_X_T = model.jointPlacements[i].toHomogeneousMatrix();

    // setting E
    for (r = 0; r < 4; r = r + 1) {
      for (c = 0; c < 4; c = c + 1) {
        float entry = pin_X_T.coeffRef(r, c);
        if (std::abs(entry) < 1e-5)
          X_T[i].set_entry_to_constant(r, c, 0);
        else
          X_T[i].set_entry_to_constant(r, c, entry);
      }
    }
  }
}

// return 0 (invalid) if collision, 1 (valid) if collision-free
static dyn_var<int> fkcc(
    const pinocchio::Model &model_coarse, 
    const pinocchio::GeometryModel &geom_model_coarse, 
    const pinocchio::Model &model_fine, 
    const pinocchio::GeometryModel &geom_model_fine,
    dyn_var<const runtime::environment_t<blaze_avx256f>&> environment,
    // hack: we need to hardcode the robot template type for now
    dyn_var<const runtime::configuration_block_robot_t<runtime::robots::Panda>&> q) {

  typedef typename Model::JointIndex JointIndex;

  // joint transforms for FK
  builder::array<Xform<blaze_avx256f>> X_T;
  builder::array<Xform<blaze_avx256f>> X_J;
  builder::array<Xform<blaze_avx256f>> X_0;

  X_T.set_size(model_coarse.njoints);
  X_J.set_size(model_coarse.njoints);
  X_0.set_size(model_coarse.njoints);

  // coarse collision geom sphere positions
  // storing one coarse sphere per link
  dyn_var<blaze_avx256f[]> coarse_x_0, coarse_y_0, coarse_z_0;
  // one coarse sph only has single radius
  // indexed as: coarse[link_id]
  dyn_var<float[]> coarse_r;

  size_t n_coarse_sph = geom_model_coarse.geometryObjects.size();
  resize_arr(coarse_x_0, n_coarse_sph);
  resize_arr(coarse_y_0, n_coarse_sph);
  resize_arr(coarse_z_0, n_coarse_sph);
  resize_arr(coarse_r, n_coarse_sph);

  // storing number of fine sphs per link
  // indexed as: n_fine_sph_per_link[link_id]
  dyn_var<size_t[]> n_fine_sph_for_link;
  resize_arr(n_fine_sph_for_link, n_coarse_sph);

  // we know max number of fine sphs for a link at compile-time
  size_t max_n_fine_sph = get_max_n_fine_sph(
          model_coarse, geom_model_coarse, model_fine, geom_model_fine);

  // fine collision geom sphere positions
  dyn_var<std_array_t<blaze_avx256f>[]> fine_x_0, fine_y_0, fine_z_0;
  dyn_var<std_array_t<float>[]> fine_r;
  // storing info for each fine sph for each link
  // indexed as: fine[link_id][sph_id_for_link_id]
  // within each fine_xyz[link_id][sph_id_for_link_id], 
  // all the values will be different (since different x,y,zs for each vector of fine sphs)
  // but fine_r[sph_id_for_link_id] will be a single value, 
  // since radius of all the fine sphs will be the same
  backend::set_inner_size_arr(fine_x_0, max_n_fine_sph);
  backend::set_inner_size_arr(fine_y_0, max_n_fine_sph);
  backend::set_inner_size_arr(fine_z_0, max_n_fine_sph);
  backend::set_inner_size_arr(fine_r, max_n_fine_sph);
  resize_arr(fine_x_0, n_coarse_sph);
  resize_arr(fine_y_0, n_coarse_sph);
  resize_arr(fine_z_0, n_coarse_sph);
  resize_arr(fine_r, n_coarse_sph);

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

  Xform<blaze_avx256f> X_pi;

  static_var<JointIndex> parent;
  std::string joint_name;

  for (i = 0; i < (JointIndex)model_coarse.njoints; i = i+1) {
    if (i == 0) {
      // special case different from generic FK
      // the "universe" joint has child spheres associated with it, that we
      // must process prior to running self collision checks for
      // collision pairs assoc. with child sphs of joint 1 against
      // child sphs of "universe"/joint 0
      X_0[i].set_identity();
    }
    else {
      X_J[i].jcalc(q[i-1]);

      // todo: figure out why standard featherstone matmul
      // ordering not working with X_T from pinocchio
      //X_pi = X_J[i] * X_T[i]; // feath
      X_pi = X_T[i] * X_J[i]; // pin
      parent = model_coarse.parents[i];
      if (parent > 0) {
        //X_0[i] = X_pi * X_0[parent]; // feath
        X_0[i] = X_0[parent] * X_pi; // pin
      }
      else {
        X_0[i] = ctup::matrix_layout_expr_leaf<blaze_avx256f>(X_pi);
      }
    }

    joint_name = model_coarse.names[i];

    // X_0 now contains the global transform of the joint wrt the world

    // joint_to_child_spheres returns a map:
    // link_spheres[link_id] = {coarse sph, list of fine sphs}
    std::map<size_t, LinkSpheres> link_spheres = joint_to_child_spheres(
            model_coarse, geom_model_coarse,
            model_fine, geom_model_fine,
            joint_name);

    std::map<size_t, LinkSpheres>::iterator outerIt;

    // we now transform the nominal transform of each sphere wrt its joint by X_0
    // to get the global transform of each sphere wrt the world
    // X_0_sph = X_0_j * X_j_sph
    //
    // in code: 
    // coarse_0[link_id] = X_0 * link_spheres[link_id]
    // But, we only care about the translation component so:
    // coarse_0[link_id].trans = X_0.rot * link_spheres[link_id].trans + X_0.trans

    for (static_var<size_t> pair_idx = 0; pair_idx < link_spheres.size(); pair_idx = pair_idx+1) {
      outerIt = link_spheres.begin();
      std::advance(outerIt, pair_idx);
      static_var<size_t> link_id = outerIt->first;
      // child link of joint_name
      // joint_name is always a true actuated joint, child links can be 
      // connected via fixed joints to joint_name as well.
      //std::cout << "child link: " << link_id << std::endl;

      //std::cout << link_spheres[link_id].coarse_x << " " <<
      //      link_spheres[link_id].coarse_y << " " <<
      //      link_spheres[link_id].coarse_z << "\n";

      coarse_x_0[link_id] = 
          X_0[i].get_entry(0,0) * link_spheres[link_id].coarse_x +
          X_0[i].get_entry(0,1) * link_spheres[link_id].coarse_y +
          X_0[i].get_entry(0,2) * link_spheres[link_id].coarse_z;

      coarse_y_0[link_id] = 
          X_0[i].get_entry(1,0) * link_spheres[link_id].coarse_x +
          X_0[i].get_entry(1,1) * link_spheres[link_id].coarse_y +
          X_0[i].get_entry(1,2) * link_spheres[link_id].coarse_z;

      coarse_z_0[link_id] = 
          X_0[i].get_entry(2,0) * link_spheres[link_id].coarse_x +
          X_0[i].get_entry(2,1) * link_spheres[link_id].coarse_y +
          X_0[i].get_entry(2,2) * link_spheres[link_id].coarse_z;

      // translation component
      coarse_x_0[link_id] += X_0[i].get_entry(0,3);
      coarse_y_0[link_id] += X_0[i].get_entry(1,3);
      coarse_z_0[link_id] += X_0[i].get_entry(2,3);

      coarse_r[link_id] = link_spheres[link_id].coarse_r;

      static_var<size_t> n_fine_sph = link_spheres[link_id].fine_r.size();
      n_fine_sph_for_link[link_id] = n_fine_sph;

      // for fine grained sphere geoms
      for(static_var<size_t> k = 0; k < n_fine_sph; k = k+1){
        fine_x_0[link_id][k] = 
            X_0[i].get_entry(0,0) * link_spheres[link_id].fine_x[k] +
            X_0[i].get_entry(0,1) * link_spheres[link_id].fine_y[k] +
            X_0[i].get_entry(0,2) * link_spheres[link_id].fine_z[k];

        fine_y_0[link_id][k] = 
            X_0[i].get_entry(1,0) * link_spheres[link_id].fine_x[k] +
            X_0[i].get_entry(1,1) * link_spheres[link_id].fine_y[k] +
            X_0[i].get_entry(1,2) * link_spheres[link_id].fine_z[k];

        fine_z_0[link_id][k] = 
            X_0[i].get_entry(2,0) * link_spheres[link_id].fine_x[k] +
            X_0[i].get_entry(2,1) * link_spheres[link_id].fine_y[k] +
            X_0[i].get_entry(2,2) * link_spheres[link_id].fine_z[k];

        fine_x_0[link_id][k] += X_0[i].get_entry(0,3);
        fine_y_0[link_id][k] += X_0[i].get_entry(1,3);
        fine_z_0[link_id][k] += X_0[i].get_entry(2,3);

        fine_r[link_id][k] = link_spheres[link_id].fine_r[k];
      }

      dyn_var<int> cc_res;

      // for each child link of joint_name, we perform self collision checks
      // against previously cached FK geometries higher up the kinematic chain
      for(static_var<size_t> cp_it = 0; cp_it < geom_model_coarse.collisionPairs.size(); cp_it = cp_it+1) {
        const pinocchio::CollisionPair & cp = geom_model_coarse.collisionPairs[cp_it];
        if (cp.second == link_id) {
          //std::cout << "collision pair: " << cp.first << "," << cp.second << std::endl;
          std::string cp_str = "collision pair: ";
          cp_str += std::to_string(cp.first) + "," + std::to_string(cp.second);
          cp_str += " : " + geom_model_coarse.geometryObjects[cp.first].name + "," + geom_model_coarse.geometryObjects[cp.second].name;
          builder::annotate(cp_str.c_str());

          // 2-level self collision checking per link
          // we first CC the two coarse spheres associated w the cp
          // if they're in collision, we CC two sets of fine spheres
          // associated w the cp
          cc_res = runtime::self_collision_link_vs_link(
              cp.first,
              // coarse sphere assoc. w cp.first
              coarse_x_0[cp.first], coarse_y_0[cp.first], coarse_z_0[cp.first], coarse_r[cp.first], 
              // # of fine spheres assoc. w cp.first
              n_fine_sph_for_link[cp.first],
              // fine spheres assoc. w cp.first
              fine_x_0[cp.first], fine_y_0[cp.first], fine_z_0[cp.first], fine_r[cp.first],
              cp.second,
              // coarse sphere assoc. w cp.second
              coarse_x_0[cp.second], coarse_y_0[cp.second], coarse_z_0[cp.second], coarse_r[cp.second], 
              // # of fine spheres assoc. w cp.second
              n_fine_sph_for_link[cp.second],
              // fine spheres assoc. w cp.second
              fine_x_0[cp.second], fine_y_0[cp.second], fine_z_0[cp.second], fine_r[cp.second]
          );

          //if (cc_res)
          //  return 0; // can't do this because static_var bug
        }
      }

      if (i > 0) {
        // no link vs. environment CC for universe joint
        // if we find no self collision, we do a two-level CC of each link against the environment
        cc_res = runtime::link_vs_environment_collision(
                coarse_x_0[link_id], coarse_y_0[link_id], coarse_z_0[link_id], coarse_r[link_id],
                n_fine_sph_for_link[link_id],
                fine_x_0[link_id], fine_y_0[link_id], fine_z_0[link_id], fine_r[link_id],
                environment);
        //if (cc_res)
        //  return 0; // can't do this because static_var bug
      }
    }
  }

  return 1;
}

int main(int argc, char* argv[]) {
  //--------------------------
  //LOAD URDF FILE
  //--------------------------

  // Path to the URDF file 1
  const char* urdf_filename_coarse = argv[1];
  std::cout << urdf_filename_coarse << "\n";

  const char* urdf_filename_fine = argv[2];
  std::cout << urdf_filename_fine << "\n";
  //--------------------------
  //END LOAD URDF FILE
  //--------------------------

  //--------------------------
  //LOAD YAML FILE
  //--------------------------
  const std::string env_filename = argv[3];
  std::cout << env_filename << "\n";

  YAML::Node root = YAML::LoadFile(env_filename);
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

  Model model_coarse;
  pinocchio::urdf::buildModel(urdf_filename_coarse, model_coarse);
  GeometryModel geom_model_coarse;
  pinocchio::urdf::buildGeom(model_coarse, urdf_filename_coarse, pinocchio::COLLISION, geom_model_coarse);

  /////
  //for (std::size_t i = 0; i < geom_model_coarse.geometryObjects.size(); ++i)
  //{
  //  const pinocchio::GeometryObject & geom_obj = geom_model_coarse.geometryObjects[i];
  //  const pinocchio::SE3 & placement = geom_obj.placement;

  //  std::string joint_name = model_coarse.names[geom_obj.parentJoint];

  //  std::cout << "Geometry: " << geom_obj.name << std::endl;
  //  std::cout << "  Parent joint: " << joint_name << std::endl;
  //  std::cout << "  Placement translation: ["
  //            << placement.translation().transpose() << "]" << std::endl;
  //  std::cout << std::endl;
  //}
  //return 0;
  //////

  geom_model_coarse.addAllCollisionPairs();
  const std::string srdf_filename = argv[4];
  pinocchio::srdf::removeCollisionPairs(model_coarse, geom_model_coarse, srdf_filename);

  Model model_fine;
  GeometryModel geom_model_fine;
  pinocchio::urdf::buildModel(urdf_filename_fine, model_fine);
  pinocchio::urdf::buildGeom(model_fine, urdf_filename_fine, pinocchio::COLLISION, geom_model_fine);

  //joint_to_spheres(model_coarse, geom_model_coarse, model_fine, geom_model_fine, "wrist_3_joint");
  //std::cout<<"---------------"<<std::endl;
  /*
  for(size_t k = 0; k < geom_model_coarse.collisionPairs.size(); ++k)
  {
    const pinocchio::CollisionPair & cp = geom_model_coarse.collisionPairs[k];
    std::cout << "collision pair: " << cp.first << " , " << cp.second<<std::endl;
  }
  */

  std::ofstream of(header_filename);
  block::c_code_generator codegen(of);

  of << "// clang-format off\n\n";
  of << "#include \"Eigen/Dense\"\n\n";
  of << "#include \"ctup/typedefs.h\"\n\n";
  of << "#include \"ctup_fkcc/runtime/typedefs.h\"\n\n";
  of << "#include \"ctup_fkcc/runtime/collision.h\"\n\n";
  of << "#include <iostream>\n\n";
  of << "namespace ctup_gen {\n\n";

  of << "static void print_string(const char* str) {\n";
  of << "  std::cout << str << \"\\n\";\n";
  of << "}\n\n";

  of << "template<typename MT>\n";
  of << "static void print_matrix(const blaze::DenseMatrix<MT, blaze::rowMajor>& matrix) {\n";
  of << "  std::cout << matrix << \"\\n\";\n";
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
  //
  of << "static ";
  auto ast = context.extract_function_ast(fkcc, "fkcc", model_coarse, geom_model_coarse, model_fine, geom_model_fine);
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
