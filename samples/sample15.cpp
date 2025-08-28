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
#include "jacobian_layouts.h"
#include "backend.h"

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;
using pinocchio::GeometryModel;

using ctup::backend::blaze_avx256f;

/////////////////////////////////////////////

struct LinkSpheres {
  std::vector<float> x;
  std::vector<float> y;
  std::vector<float> z;
  std::vector<float> r;
};

/////////////////////////////////////////////

using ctup::Xform;
using ctup::SingletonSpatialVector;
using ctup::SpatialVector;

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

template <typename T>
void set_std_array_size(dyn_var<ctup::std_array_t<T>> &arr, size_t std_array_size) {
  auto type = block::to<block::named_type>(arr.block_var->var_type);
  auto s = std::make_shared<block::named_type>();
  s->type_name = std::to_string(std_array_size);
  type->template_args.push_back(s);
}

}

using ctup::std_array_t;

namespace runtime {

namespace robots {
constexpr char robots_panda_name[] = "cg_sd_runtime::robots::Panda";
using Panda = typename builder::name<robots_panda_name>;
}

constexpr char configuration_block_robot_name[] = "cg_sd_runtime::ConfigurationBlockRobot";
template <typename RobotT>
using configuration_block_robot_t = typename builder::name<configuration_block_robot_name, RobotT>;

builder::dyn_var<void (
    size_t flattened_idx,
    blaze_avx256f&, ctup::EigenMatrix<float, 8, -1>&
        )> map_blaze_avxtype_to_eigen_batch_dim = builder::as_global("cg_sd_runtime::map_blaze_avxtype_to_eigen_batch_dim");

// NV: dim velocity vector
// NCP: number of collision pairs
template <size_t NV, size_t NCP>
builder::dyn_var<void (
    size_t collision_pair_id, // we write-out to this index in sd and grad_sd
    ctup::BlazeStaticMatrix<blaze_avx256f, 6, NV>&, // jac1
    ctup::BlazeStaticMatrix<blaze_avx256f, 6, NV>&, // jac2
    blaze_avx256f &, blaze_avx256f &, blaze_avx256f &, float, // sph_[x,y,z,r]1
    blaze_avx256f &, blaze_avx256f &, blaze_avx256f &, float, // sph_[x,y,z,r]2
    ctup::BlazeStaticVector<blaze_avx256f, NCP> &, // signed_distance (modified in-place)
    ctup::BlazeStaticMatrix<blaze_avx256f, NCP, NV> & // sd_jac (modified in-place); left rest of template params unspecified
        )> compute_sph_sph_cp_sd_grad = builder::as_global("cg_sd_runtime::compute_sph_sph_cp_sd_grad");

}

/////////////////////////////////////////////

static std::map<size_t, LinkSpheres> joint_to_child_spheres(
    const pinocchio::Model &model, 
    const pinocchio::GeometryModel &geom_model,
    const std::string joint_name) {
  using namespace pinocchio;

  JointIndex jid = model.getJointId(joint_name);

  std::map<size_t, LinkSpheres> link_spheres;
  std::map<std::string, size_t> rel_link_num;

  for (size_t i = 0; i < model.frames.size(); i++) {
    const JointIndex parent_joint_id = model.frames[i].parentJoint;

    if (parent_joint_id != jid)
      continue;

    // link_name to idx mapping
    rel_link_num[model.frames[i].name] = i;

    LinkSpheres ls;
    link_spheres[i] = ls;
  }

  for (size_t i = 0; i < geom_model.geometryObjects.size(); i++) {
    const GeometryObject &geom_obj = geom_model.geometryObjects[i];
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

    size_t link_id = rel_link_num[(model.frames[geom_obj.parentFrame].name)];

    link_spheres[link_id].x.push_back(sphere_xyz[0]);
    link_spheres[link_id].y.push_back(sphere_xyz[1]);
    link_spheres[link_id].z.push_back(sphere_xyz[2]);
    link_spheres[link_id].r.push_back(sphere_radius);
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


// computes signed distances and jacobians for 8 robot configurations at once (batch size = 8)
// returns:
// distances: shape: (batch_size, n_collision_pairs)
// jacobians: shape: (batch_size * n_collision_pairs, n_dof)
static void self_collision_signed_distances_and_jacobians(
    const pinocchio::Model &model, 
    const pinocchio::GeometryModel &geom_model, 
    // hack: we need to hardcode the robot template type for now
    dyn_var<const runtime::configuration_block_robot_t<runtime::robots::Panda>&> q
    // Eigen::VectorXd distances
    // Eigen::MatrixXd jacobians
    ) 
{
  typedef typename Model::JointIndex JointIndex;

  static_var<JointIndex> i, j;

  ////////// for forward kinematics /////////////////

  // joint transforms for FK
  builder::array<Xform<blaze_avx256f>> X_T;
  builder::array<Xform<blaze_avx256f>> X_J;
  builder::array<Xform<blaze_avx256f>> X_0;

  X_T.set_size(model.njoints);
  X_J.set_size(model.njoints);
  X_0.set_size(model.njoints);

  ///////////////////////////////////////////////

  ////////// for spatial jacobian /////////////////
  builder::array<SingletonSpatialVector<blaze_avx256f>> S;
  S.set_size(model.njoints);

  ctup::Adjoint<blaze_avx256f> adj;
  SpatialVector<blaze_avx256f> S_world;

  // no sparsity in Jacobian for now
  builder::array<dyn_var<ctup::BlazeStaticMatrix<blaze_avx256f, 8, -1>>> J_joints;
  J_joints.set_size(model.njoints);

  for (i = 0; i < (JointIndex)model.njoints; i = i+1) {
    J_joints[i].set_matrix_fixed_size(6, model.nv);
  }

  ///////////////////////////////////////////////

  ////////// for child sph FK /////////////////
  // 0th link is root
  size_t n_links = model.nbodies-1;

  // fine collision geom sphere positions
  builder::array<dyn_var<std_array_t<blaze_avx256f>>> x_0, y_0, z_0;
  builder::array<dyn_var<std_array_t<float>>> r;
  // storing info for each fine sph for each link
  // indexed as: fine[link_id][sph_id_for_link_id]
  // within each xyz[link_id][sph_id_for_link_id], 
  // all the values will be different (since different x,y,zs for each vector of fine sphs)
  // but r[sph_id_for_link_id] will be a single value, 
  // since radius of all the fine sphs in the vector will be the same
  x_0.set_size(n_links);
  y_0.set_size(n_links);
  z_0.set_size(n_links);
  r.set_size(n_links);

  for (i = 0; i < (JointIndex)model.njoints; i = i+1) {
    std::string joint_name = model.names[i];
    std::map<size_t, LinkSpheres> link_spheres = joint_to_child_spheres(
            model, geom_model,
            joint_name);

    // roundabout way of iterating to ensure static_var is used correctly in
    // control flow
    std::map<size_t, LinkSpheres>::iterator outerIt;
    // each joint may have multiple links associated with it
    for (static_var<size_t> pair_idx = 0; pair_idx < link_spheres.size(); pair_idx = pair_idx+1) {
      outerIt = link_spheres.begin();
      std::advance(outerIt, pair_idx);
      static_var<size_t> link_id = outerIt->first;

      // number of fine sph for link_id
      size_t curr_n_sph = link_spheres[link_id].r.size();
      backend::set_std_array_size(x_0[link_id], curr_n_sph);
      backend::set_std_array_size(y_0[link_id], curr_n_sph);
      backend::set_std_array_size(z_0[link_id], curr_n_sph);
      backend::set_std_array_size(r[link_id], curr_n_sph);
    }
  }
  ///////////////////////////////////////////////

  set_X_T(X_T, model);

  static_var<int> jtype;
  static_var<int> axis;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
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

  Xform<blaze_avx256f> X_pi;

  static_var<JointIndex> parent;
  std::string joint_name;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    if (i > 0) {
      // run FK and Jacobian calcs for non-universe joints
      // we do want to calc frame offsets for child geoms of the universe joint
      // which is why we don't skip them altogether

      X_J[i].jcalc(q[i-1]);

      // todo: figure out why standard featherstone matmul
      // ordering not working with X_T from pinocchio
      //X_pi = X_J[i] * X_T[i]; // feath
      X_pi = X_T[i] * X_J[i]; // pin
      parent = model.parents[i];
      if (parent > 0) {
        //X_0[i] = X_pi * X_0[parent]; // feath
        X_0[i] = X_0[parent] * X_pi; // pin
      }
      else {
        X_0[i] = ctup::blocked_layout_expr_leaf<blaze_avx256f>(X_pi);
      }

      // loop for spatial jacobian calculation
      for (j = 1; j < (JointIndex)model.njoints; j = j+1) {
        if (!is_joint_ancestor(model, j, i)) {
            continue;
        }
        // since we know j is ancestor of i,
        // X_0[j] is guaranteed to have been
        // calculated already.
        adj.set_rotation_and_translation(X_0[j].get_rotation(), X_0[j].get_translation());

        S_world = adj * S[j];

        for (static_var<size_t> r = 0; r < 6; r = r + 1) {
          // j-1 because j=0 is universe joint
          // jac storage convention is:
          // jac(batch_dim, r * model.nv + c), where (r,c) are the 2D indices of
          // a vanilla jacobian matrix.
          // r * model.nv + c is a flattened index
          runtime::map_blaze_avxtype_to_eigen_batch_dim((size_t)(r * (size_t)model.nv + j-1), 
                  S_world.get_entry(r, 0), J_joints[i]);
        }
      }
      ////////////////////////////////////////////////
    }

    //////////// Frame offset for child links + SD calc ///////////

    joint_name = model.names[i];

    // X_0 now contains the global transform of the joint wrt the world

    // joint_to_child_spheres returns a map:
    // link_spheres[link_id] = {list of sphs}
    std::map<size_t, LinkSpheres> link_spheres = joint_to_child_spheres(
            model, geom_model,
            joint_name);

    std::map<size_t, LinkSpheres>::iterator outerIt;

    // we now transform the nominal transform of each sphere wrt its joint by X_0
    // to get the global transform of each sphere wrt the world
    // X_0_sph = X_0_j * X_j_sph
    //
    // in code: 
    // 0[link_id] = X_0 * link_spheres[link_id]
    // But, we only care about the translation component so:
    // 0[link_id].trans = X_0.rot * link_spheres[link_id].trans + X_0.trans

    for (static_var<size_t> pair_idx = 0; pair_idx < link_spheres.size(); pair_idx = pair_idx+1) {
      outerIt = link_spheres.begin();
      std::advance(outerIt, pair_idx);
      static_var<size_t> link_id = outerIt->first;
      // child link of joint_name
      // joint_name is always a true actuated joint, child links can be 
      // connected via fixed joints to joint_name as well.
      //std::cout << "child link: " << link_id << std::endl;

      //std::cout << link_spheres[link_id].x << " " <<
      //      link_spheres[link_id].y << " " <<
      //      link_spheres[link_id].z << "\n";

      // each link in the URDF may have many sphs associated with it
      static_var<size_t> n_sph = link_spheres[link_id].r.size();

      for (static_var<size_t> k = 0; k < n_sph; k = k+1) {
        x_0[link_id][k] = 
            X_0[i].get_entry(0,0) * link_spheres[link_id].x[k] +
            X_0[i].get_entry(0,1) * link_spheres[link_id].y[k] +
            X_0[i].get_entry(0,2) * link_spheres[link_id].z[k];

        y_0[link_id][k] = 
            X_0[i].get_entry(1,0) * link_spheres[link_id].x[k] +
            X_0[i].get_entry(1,1) * link_spheres[link_id].y[k] +
            X_0[i].get_entry(1,2) * link_spheres[link_id].z[k];

        z_0[link_id][k] = 
            X_0[i].get_entry(2,0) * link_spheres[link_id].x[k] +
            X_0[i].get_entry(2,1) * link_spheres[link_id].y[k] +
            X_0[i].get_entry(2,2) * link_spheres[link_id].z[k];

        // translation component
        x_0[link_id][k] += X_0[i].get_entry(0,3);
        y_0[link_id][k] += X_0[i].get_entry(1,3);
        z_0[link_id][k] += X_0[i].get_entry(2,3);

        r[link_id][k] = link_spheres[link_id].r[k];
      }

      // for each child link of joint_name, we perform self collision checks
      // against previously cached FK geometries higher up the kinematic chain
      //for (static_var<size_t> cp_it = 0; cp_it < geom_model.collisionPairs.size(); cp_it = cp_it+1) {
      //  const pinocchio::CollisionPair & cp = geom_model.collisionPairs[cp_it];
      //  if (cp.second == link_id) {
      //    std::string cp_str = "collision pair: ";
      //    cp_str += std::to_string(cp.first) + "," + std::to_string(cp.second);
      //    cp_str += " : " + geom_model.geometryObjects[cp.first].name + "," + geom_model.geometryObjects[cp.second].name;
      //    builder::annotate(cp_str.c_str());

      //    static_var<size_t> par_first = geom_model.geometryObjects[cp.first].parentJoint;
      //    static_var<size_t> par_second = geom_model.geometryObjects[cp.second].parentJoint;

      //    // [x|y|z|r]_0[link_id] is a std::array of all the sphs in the link

      //    runtime::compute_sph_sph_cp_sd_grad(
      //        cp_it,
      //        J_joints[par_first], J_joints[par_second],
      //        x_0[cp.first], y_0[cp.first], z_0[cp.first], r[cp.first],
      //        x_0[cp.second], y_0[cp.second], z_0[cp.second], r[cp.second],
      //        signed_distances,
      //        sd_jacs
      //    );
      //  }
      //}
    }
    
    ////////////////////////////////////////////////
  }
}

int main(int argc, char* argv[]) {
  //--------------------------
  //LOAD URDF FILE
  //--------------------------
  const char* urdf_filename = argv[1];
  std::cout << urdf_filename << "\n";

  //--------------------------
  //END LOAD URDF FILE
  //--------------------------

  const std::string header_filename = (argc <= 3) ? "./fk_gen.h" : argv[3];
  std::cout << header_filename << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);
  GeometryModel geom_model;
  pinocchio::urdf::buildGeom(model, urdf_filename, pinocchio::COLLISION, geom_model);

  /////
  //for (std::size_t i = 0; i < geom_model.geometryObjects.size(); ++i)
  //{
  //  const pinocchio::GeometryObject & geom_obj = geom_model.geometryObjects[i];
  //  const pinocchio::SE3 & placement = geom_obj.placement;

  //  std::string joint_name = model.names[geom_obj.parentJoint];

  //  std::cout << "Geometry: " << geom_obj.name << std::endl;
  //  std::cout << "  Parent joint: " << joint_name << std::endl;
  //  std::cout << "  Placement translation: ["
  //            << placement.translation().transpose() << "]" << std::endl;
  //  std::cout << std::endl;
  //}
  //return 0;
  //////

  geom_model.addAllCollisionPairs();
  const std::string srdf_filename = argv[2];
  pinocchio::srdf::removeCollisionPairs(model, geom_model, srdf_filename);

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
  auto ast = context.extract_function_ast(
          self_collision_signed_distances_and_jacobians, 
          "self_collision_signed_distances_and_jacobians", 
          model, geom_model);
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}

