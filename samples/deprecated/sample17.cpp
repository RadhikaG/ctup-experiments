// ./build/sample9 ./deps/pinocchio/models/baxter_simple.urdf ../ctup-experiments/gen/fk_gen_unrolled.h
#include "backend.h"
#include "deprecated/xform_impl.h"
#include "deprecated/xform_operators.h"
#include "deprecated/utils.h"

#include "blocks/block_visitor.h"
#include "blocks/c_code_generator.h"
#include "builder/builder_base.h"
#include "builder/builder_context.h"
#include "builder/dyn_var.h"
#include "builder/forward_declarations.h"
#include "Eigen/Dense"
#include "builder/static_var.h"
#include "builder/lib/utils.h"
#include "builder/array.h"

// ignore unused header warning in IDE, this is needed
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

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;
using pinocchio::GeometryModel;

using ctup::Xform;
using ctup::EigenMatrix;
using ctup::vector_t;


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

static dyn_var<int> Sphere_Environment_Collision(
const Envir_Objects& obj,
dyn_var<ctup::BlazeStaticVector<double,16>&> ax, dyn_var<ctup::BlazeStaticVector<double,16>&> ay, dyn_var<ctup::BlazeStaticVector<double,16>&> az, dyn_var<double> ar,
dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>&> bx, dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>&> by, dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>&> bz, dyn_var<vector_t<double>&> br) {
  dyn_var<int> res=false;
  for(static_var<size_t> l=0;l<std::size(obj.spheres);l=l+1){
    const Sphere& sphere=obj.spheres[l];
    dyn_var<ctup::BlazeStaticVector<double,16>> xs = (ax - sphere.center_x);
    dyn_var<ctup::BlazeStaticVector<double,16>> ys = (ay - sphere.center_y);
    dyn_var<ctup::BlazeStaticVector<double,16>> zs = (az - sphere.center_z);

    dyn_var<ctup::BlazeStaticVector<double,16>> sum= xs*xs+ys*ys+zs*zs;
    dyn_var<double> rs = ar + sphere.radius;

    sum = sum - rs*rs;

    res=(ctup::backend::min<double, 16>(sum) < 0.0);

    if(res){
      if(bx.size() == 0){
        return 1;
      }

      for(dyn_var<size_t> i=0;i<bx.size();i=i+1){
        xs = (bx[i] - sphere.center_x);
        ys = (by[i] - sphere.center_y);
        zs = (bz[i] - sphere.center_z);

        sum= xs*xs+ys*ys+zs*zs;
        rs = br[i] + sphere.radius;

        sum = sum - rs*rs;

        if(ctup::backend::min<double, 16>(sum)<0.0) return true;
      }
      res=false;
    }
  }
  for(static_var<size_t> l=0;l<std::size(obj.cylinders);l=l+1){
    const Cylinder& cylinder=obj.cylinders[l];
    if(cylinder.z_aligned){
      dyn_var<ctup::BlazeStaticVector<double,16>> xs = (ax - cylinder.center_x);
      dyn_var<ctup::BlazeStaticVector<double,16>> ys = (ay - cylinder.center_y);
      dyn_var<ctup::BlazeStaticVector<double,16>> zs = (az - cylinder.center_z);
      dyn_var<ctup::BlazeStaticVector<double,16>> dot= zs*cylinder.zv;
      
      dyn_var<ctup::BlazeStaticVector<double,16>> cdf = ctup::backend::max<double, 16>(ctup::backend::min<double, 16>((dot * cylinder.rdv),1.0),0.0);

      zs = (az - (cylinder.center_z+cylinder.zv*cdf));

      dyn_var<ctup::BlazeStaticVector<double,16>> sum= xs*xs+ys*ys+zs*zs;

      dyn_var<double> rs = ar + cylinder.radius;

      sum = sum - rs*rs;

      res=(ctup::backend::min<double, 16>(sum) < 0.0);

      if(res){
        if(bx.size() == 0){
          return 1;
        }
        
        for(dyn_var<size_t> i=0;i<bx.size();i=i+1){
          xs = (bx[i] - cylinder.center_x);
          ys = (by[i] - cylinder.center_y);
          zs = (bz[i] - cylinder.center_z);

          cdf = ctup::backend::max<double, 16>(ctup::backend::min<double, 16>((dot * cylinder.rdv),1.0),0.0);
          zs = (az - (cylinder.center_z+cylinder.zv*cdf));

          sum= xs*xs+ys*ys+zs*zs;
          rs = br[i] + cylinder.radius;
          sum = sum - rs*rs;

          if(ctup::backend::min<double, 16>(sum)<0.0) return true;
        }
        res=false;
      }
    }
    else{
      std::cout<<"Error not alligned cylinder"<<std::endl;
    }
  }
  for(static_var<size_t> l=0;l<std::size(obj.boxs);l=l+1){
  const Box& box=obj.boxs[l];
    if(box.xyz_aligned){
      dyn_var<ctup::BlazeStaticVector<double,16>> xs = (ax - box.center_x);
      dyn_var<ctup::BlazeStaticVector<double,16>> ys = (ay - box.center_y);
      dyn_var<ctup::BlazeStaticVector<double,16>> zs = (az - box.center_z);

      dyn_var<ctup::BlazeStaticVector<double,16>> a1 = ctup::backend::max<double, 16>((ctup::backend::abs<double, 16>(xs) - box.caxis_1_r),0.0);
      dyn_var<ctup::BlazeStaticVector<double,16>> a2 = ctup::backend::max<double, 16>((ctup::backend::abs<double, 16>(ys) - box.caxis_2_r),0.0);
      dyn_var<ctup::BlazeStaticVector<double,16>> a3 = ctup::backend::max<double, 16>((ctup::backend::abs<double, 16>(zs) - box.caxis_3_r),0.0);

      dyn_var<ctup::BlazeStaticVector<double,16>> sum= a1*a1+a2*a2+a3*a3;

      sum = sum - ar*ar;

      res=(ctup::backend::min<double, 16>(sum)<0.0);

      if(res){
        if(bx.size() == 0){
        return 1;
        } 
        
        for(dyn_var<size_t> i=0;i<bx.size();i=i+1){
          xs = (bx[i] - box.center_x);
          ys = (by[i] - box.center_y);
          zs = (bz[i] - box.center_z);

          a1 = ctup::backend::max<double, 16>((ctup::backend::abs<double, 16>(xs) - box.caxis_1_r),0.0);
          a2 = ctup::backend::max<double, 16>((ctup::backend::abs<double, 16>(ys) - box.caxis_2_r),0.0);
          a3 = ctup::backend::max<double, 16>((ctup::backend::abs<double, 16>(zs) - box.caxis_3_r),0.0);

          sum= a1*a1+a2*a2+a3*a3;
          sum = sum - br[i]*br[i];

          if(ctup::backend::min<double, 16>(sum)<0.0) return true;
        }
        res=false;
      }
    }
    else{
      std::cout<<"Error not alligned box"<<std::endl;
    }
  }
  return 0;
}

static std::map<int, std::map<std::string, std::map<std::string, std::vector<float>>>>  joint_to_spheres(const pinocchio::Model &model, const pinocchio::GeometryModel &geom_model, const pinocchio::Model &model_2, const pinocchio::GeometryModel &geom_model_2, const std::string joint_name) {
  using namespace pinocchio;

  JointIndex jid = model.getJointId(joint_name);

  std::map<int, std::map<std::string,std::map<std::string,std::vector<float>>>> spheres;  
  std::map<std::string, int> rel_link_num;
  for (size_t i = 0; i < geom_model.geometryObjects.size(); i++) {
    const GeometryObject &geom_obj = geom_model.geometryObjects[i];
    // this function does pick out the "true" actuated parent, not the fixed joint parent
    const JointIndex parent_joint_id = geom_obj.parentJoint;

    if (parent_joint_id != jid)
      continue;

    hpp::fcl::NODE_TYPE node_type = geom_obj.geometry->getNodeType();
    assert(node_type == hpp::fcl::GEOM_SPHERE && "we don't support non sphere geoms inside robot");

    Eigen::Vector3d sphere_xyz = geom_obj.placement.translation();
    double sphere_radius = std::dynamic_pointer_cast<hpp::fcl::Sphere>(geom_obj.geometry)->radius;
    std::cout<<"Link: "<<i<<std::endl;
    (spheres[i]["one_sphere"]["x"]).push_back(sphere_xyz[0]);
    (spheres[i]["one_sphere"]["y"]).push_back(sphere_xyz[1]);
    (spheres[i]["one_sphere"]["z"]).push_back(sphere_xyz[2]); 
    (spheres[i]["one_sphere"]["r"]).push_back(sphere_radius);

    rel_link_num[(model.frames[geom_obj.parentFrame].name)]=i;
  }

  jid = model_2.getJointId(joint_name);
  for (size_t i = 0; i < geom_model_2.geometryObjects.size(); i++) {
    const GeometryObject &geom_obj = geom_model_2.geometryObjects[i];
    // this function does pick out the "true" actuated parent, not the fixed joint parent
    const JointIndex parent_joint_id = geom_obj.parentJoint;

    if (parent_joint_id != jid)
      continue;

    hpp::fcl::NODE_TYPE node_type = geom_obj.geometry->getNodeType();
    assert(node_type == hpp::fcl::GEOM_SPHERE && "we don't support non sphere geoms inside robot");

    Eigen::Vector3d sphere_xyz = geom_obj.placement.translation();
    double sphere_radius = std::dynamic_pointer_cast<hpp::fcl::Sphere>(geom_obj.geometry)->radius;

    int link_id = rel_link_num[(model_2.frames[geom_obj.parentFrame].name)];
    //std::cout<<"Link: "<<link_id<<std::endl;
    if(sphere_xyz[0]!=(spheres[link_id]["one_sphere"]["x"])[0] or sphere_xyz[1]!=(spheres[link_id]["one_sphere"]["y"])[0] or sphere_xyz[2]!=(spheres[link_id]["one_sphere"]["z"])[0] or sphere_radius!=(spheres[link_id]["one_sphere"]["r"])[0]){
      (spheres[link_id]["multiple_sphere"]["x"]).push_back(sphere_xyz[0]);
      (spheres[link_id]["multiple_sphere"]["y"]).push_back(sphere_xyz[1]);
      (spheres[link_id]["multiple_sphere"]["z"]).push_back(sphere_xyz[2]);
      (spheres[link_id]["multiple_sphere"]["r"]).push_back(sphere_radius);
    }
  }

  return spheres;
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

static void set_X_T(Xform<double> X_T[], const Model &model) {
  typedef typename Model::JointIndex JointIndex;
  static_var<JointIndex> i;

  static_var<size_t> r;
  static_var<size_t> c;

  for (i = 1; i < (JointIndex)model.njoints; i = i+1) {
    Eigen::Matrix<double, 6, 6> pin_X_T = model.jointPlacements[i];

    // setting E
    for (r = 0; r < 3; r = r + 1) {
      for (c = 0; c < 3; c = c + 1) {
        double entry = pin_X_T.coeffRef(c, r);
        if (std::abs(entry) < 1e-5)
          X_T[i].rot.set_entry_to_constant(r, c, 0);
        else
          X_T[i].rot.set_entry_to_constant(r, c, entry);
      }
    }

    // setting -E*r-cross terms

    for (r = 0; r < 3; r = r + 1) {
      for (c = 0; c < 3; c = c + 1) {
        double entry = pin_X_T.coeffRef(c, r+3);
        X_T[i].minus_E_rcross.set_entry_to_constant(r, c, entry);
      }
    }
  }
}

static dyn_var<int> fk(const Model &model,const GeometryModel &geom_model, const Model &model_2, const GeometryModel &geom_model_2 ,dyn_var<ctup::EigenMatrix<ctup::BlazeStaticVector<double,16>>> q) {
  Xform<double> X_T[model.njoints];
  //builder::array<Xform<double>> X_T; X_T.set_size(model.njoints);
  Xform<ctup::EigenMatrix<double,16,1>> X_J[model.njoints];
  Xform<ctup::EigenMatrix<double,16,1>> X_0[model.njoints];
  typedef typename Model::JointIndex JointIndex;
  static_var<size_t> i;
  set_X_T(X_T, model);

  static_var<int> jtype;
  static_var<int> axis;

  static_var<JointIndex> parent;
  std::string joint_name;
  Xform<ctup::EigenMatrix<double,16,1>> X_pi;

  builder::array<dyn_var<ctup::BlazeStaticVector<double,16>>> dx; dx.set_size(geom_model.geometryObjects.size());
  builder::array<dyn_var<ctup::BlazeStaticVector<double,16>>> dy; dy.set_size(geom_model.geometryObjects.size());
  builder::array<dyn_var<ctup::BlazeStaticVector<double,16>>> dz; dz.set_size(geom_model.geometryObjects.size());
  builder::array<dyn_var<double>> dr; dr.set_size(geom_model.geometryObjects.size());

  builder::array<dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>>> sx; sx.set_size(geom_model.geometryObjects.size());
  builder::array<dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>>> sy; sy.set_size(geom_model.geometryObjects.size());
  builder::array<dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>>> sz; sz.set_size(geom_model.geometryObjects.size());
  builder::array<dyn_var<vector_t<double>>> sr; sr.set_size(geom_model.geometryObjects.size());

  const int constante=2;
  ctup::BlazeStaticVector<double,constante> test;
  //Joint 0
  {
    dx[0]=0;
    dy[0]=0;
    dz[0]=0.9144;
    dr[0]=0.08;
  }

  for (i = 1; i < (size_t)model.njoints; i = i+1) {
    jtype = get_jtype(model, i);
    axis = get_joint_axis(model, i);

    if (jtype == 'R') {
      X_J[i].set_revolute_axis(axis);
    }
    if (jtype == 'P') {
      X_J[i].set_prismatic_axis(axis);
    }
    
    X_J[i].jcalc(q[i-1]);//changed for blaze

    X_pi = X_J[i] * X_T[i];
    parent = model.parents[i];
    if (parent > 0) {
      X_0[i] = X_pi * X_0[parent];
    }
    else {
      X_0[i] = X_pi;
    }

    joint_name = model.names[i];
    std::cout<<joint_name<<std::endl;

    //Transform from relative position to global positions

    dyn_var<ctup::EigenMatrix<double,16,1>> t[3];

    t[0]=-(ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(3, 1)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 2)
    +ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(4, 1)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 2)
    +ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(5, 1)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 2));

    t[1]=(ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(3, 0)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 2)
    +ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(4, 0)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 2)
    +ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(5, 0)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 2));

    t[2]=-(ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(3, 0)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 1)
    +ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(4, 0)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 1)
    +ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(5, 0)*ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 1));
    
    std::map<int, std::map<std::string,std::map<std::string,std::vector<float>>>> spheres = joint_to_spheres(model, geom_model, model_2, geom_model_2, joint_name);
    
    std::map<int, std::map<std::string, std::map<std::string, std::vector<float>>>>::iterator outerIt;

    for (static_var<size_t> pair_idx = 0; pair_idx < spheres.size(); pair_idx=pair_idx+1) {
      outerIt = spheres.begin();
      std::advance(outerIt, pair_idx);
      size_t link_id=outerIt->first;
      std::cout <<link_id<<std::endl;
      
      dx[link_id]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 0) * (spheres[link_id]["one_sphere"]["x"][0]);
      
      dx[link_id]=dx[link_id] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 0) * (spheres[link_id]["one_sphere"]["y"][0]);
      dx[link_id]=dx[link_id] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 0) * (spheres[link_id]["one_sphere"]["z"][0]);
      
      dy[link_id]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 1) * (spheres[link_id]["one_sphere"]["x"])[0];
      dy[link_id]=dy[link_id] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 1) * (spheres[link_id]["one_sphere"]["y"])[0];
      dy[link_id]=dy[link_id] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 1) * (spheres[link_id]["one_sphere"]["z"])[0];

      dz[link_id] = ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 2) * (spheres[link_id]["one_sphere"]["x"])[0];
      dz[link_id]=dz[link_id] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 2) * (spheres[link_id]["one_sphere"]["y"])[0];
      dz[link_id]=dz[link_id] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 2) * (spheres[link_id]["one_sphere"]["z"])[0];
      
      dx[link_id]=dx[link_id] + t[0];
      dy[link_id]=dy[link_id] + t[1];
      dz[link_id]=dz[link_id] + t[2];
    
      dr[link_id]=(spheres[link_id]["one_sphere"]["r"])[0];

      static_var<size_t> num_sph=(spheres[link_id]["mult_sphere"]["x"]).size();

      assert(num_sph == 0 && "blah");

      dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> x;
      x.resize(num_sph);
      dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> y;
      y.resize(num_sph);
      dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> z;
      z.resize(num_sph);
      dyn_var<vector_t<double>> rad_sph;
      rad_sph.resize(num_sph);

      for(static_var<size_t> k=0;k<num_sph;k=k+1){
        x[k]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 0) * (spheres[link_id]["mult_sphere"]["x"])[k];
        x[k]= x[k] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 1) * (spheres[link_id]["mult_sphere"]["y"])[k];
        x[k]= x[k] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 2) * (spheres[link_id]["mult_sphere"]["z"])[k];

        y[k]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 0) * (spheres[link_id]["mult_sphere"]["x"])[k];
        y[k]= y[k] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 1) * (spheres[link_id]["mult_sphere"]["y"])[k];
        y[k]= y[k] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 2) * (spheres[link_id]["mult_sphere"]["z"])[k];

        z[k]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 0) * (spheres[link_id]["mult_sphere"]["x"])[k];
        z[k]=z[k] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 1) * (spheres[link_id]["mult_sphere"]["y"])[k];
        z[k]=z[k] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 2) * (spheres[link_id]["mult_sphere"]["z"])[k];

        x[k]=x[k] + t[0];
        y[k]=y[k] + t[1];
        z[k]=z[k] + t[2];

        rad_sph[k]= (spheres[link_id]["mult_sphere"]["r"])[k];
      }

      dyn_var<int> res;
      
      for(static_var<size_t> k = 0; k < geom_model.collisionPairs.size(); k=k+1)
      {
        const pinocchio::CollisionPair & cp = geom_model.collisionPairs[k];
        if(cp.second==link_id){
          std::cout << "collision pair: " << cp.first << " , " << cp.second<<std::endl;
          std::string cp_str = "collision pair: ";
          cp_str += std::to_string(cp.first) + ", " + std::to_string(cp.second);
          builder::annotate(cp_str.c_str());
          res= ctup::backend::self_collision(dx[link_id], dy[link_id], dz[link_id], dr[link_id], x, y, z, rad_sph, dx[cp.first], dy[cp.first], dz[cp.first], dr[cp.first], sx[cp.first], sy[cp.first], sz[cp.first], sr[cp.first]);
        }
      }
      res= ctup::backend::Sphere_Environment_Collision(dx[link_id], dy[link_id], dz[link_id], dr[link_id], x, y, z, rad_sph);

      sx[link_id]=x;
      sy[link_id]=y;
      sz[link_id]=z;
      sr[link_id]=rad_sph; 
      
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

  of << "static ";
  auto ast = context.extract_function_ast(Sphere_Environment_Collision, "Sphere_Environment_Collision", env_obj);
  block::c_code_generator::generate_code(ast, of, 0);
  of << "static ";
  ast = context.extract_function_ast(fk, "fk", model, geom_model, model_2, geom_model_2);
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}
