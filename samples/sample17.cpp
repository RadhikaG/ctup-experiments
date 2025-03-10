// ./build/sample9 ./deps/pinocchio/models/baxter_simple.urdf ../ctup-experiments/gen/fk_gen_unrolled.h
#include "backend.h"
#include "spatial_algebra.h"
#include "utils.h"

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
#include "pinocchio/parsers/urdf.hpp"
#include "assert.h"
#include <memory>
#include <string>

#include <tinyxml2.h>
#include <yaml-cpp/yaml.h>

using builder::dyn_var;
using builder::static_var;

using pinocchio::Model;

using ctup::Xform;
using ctup::EigenMatrix;


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

static std::vector<double> set_spheres(const tinyxml2::XMLElement* root_one_sph, const tinyxml2::XMLElement* root_mult_sph, const std::string joint_name){
  int found=false;
  std::vector<double> spheres;
  
  //READ 1 SPH COLLIISON
  const tinyxml2::XMLElement* joint = root_one_sph->FirstChildElement("joint");
  while(joint != nullptr && not(found)){
  //for (const tinyxml2::XMLElement* joint = root_one_sph->FirstChildElement("joint"); joint != nullptr && not(found); joint = joint->NextSiblingElement("joint")) {
    const char* joint_name_2 = joint->Attribute("name");
    if(joint_name_2==joint_name){
      // Get the child link name from the <child> tag
      const tinyxml2::XMLElement* child = joint->FirstChildElement("child");
      if (child) {
        const char* child_link_name = child->Attribute("link");

        // Find the <link> element matching the child link name
        for (const tinyxml2::XMLElement* link = root_one_sph->FirstChildElement("link"); link != nullptr && not(found); link = link->NextSiblingElement("link")) {
          const char* link_name = link->Attribute("name");
          if (link_name && child_link_name && std::string(link_name) == child_link_name) {
            // Get the <collision> elements inside the child link
            for (const tinyxml2::XMLElement* collision = link->FirstChildElement("collision"); collision != nullptr; collision = collision->NextSiblingElement("collision")) {
                const tinyxml2::XMLElement* origin = collision->FirstChildElement("origin");
                if (origin) {
                  const tinyxml2::XMLElement* sphere_col = (collision->FirstChildElement("geometry"))->FirstChildElement("sphere");
                  const char* rad = sphere_col->Attribute("radius");

                  const char* xyz = origin->Attribute("xyz");
                  //std::cout << "XYZ: " << xyz << std::endl;
                  //std::cout << "Radius: " << rad << std::endl<<std::endl;

                  std::string token;
                  std::istringstream ss(xyz);
                  while (std::getline(ss, token, ' ')) {
                    spheres.push_back(std::stod(token));
                    //std::cout << token << std::endl<<std::endl;
                  }
                  spheres.push_back(std::stod(rad));
                }
            }
            found=true; // Stop looking for the child link once found
          }
        }
        found=false;
        for (const tinyxml2::XMLElement* link = root_mult_sph->FirstChildElement("link"); link != nullptr && not(found); link = link->NextSiblingElement("link")) {
          const char* link_name = link->Attribute("name");
          if (link_name && child_link_name && std::string(link_name) == child_link_name) {
            // Get the <collision> elements inside the child link
            for (const tinyxml2::XMLElement* collision = link->FirstChildElement("collision"); collision != nullptr; collision = collision->NextSiblingElement("collision")) {
                const tinyxml2::XMLElement* origin = collision->FirstChildElement("origin");
                if (origin) {
                  const tinyxml2::XMLElement* sphere_col = (collision->FirstChildElement("geometry"))->FirstChildElement("sphere");
                  const char* rad_2 = sphere_col->Attribute("radius");
                  const char* xyz2 = origin->Attribute("xyz");

                  std::string token;
                  std::istringstream ss(xyz2);

                  int same= true;
                  int loop=0;
                  while (std::getline(ss, token,' ') && same) {
                    if(double(std::stod(token))-spheres[loop]!=0){
                      same=false;
                    }
                    loop=loop+1;
                  }
                  if(spheres[loop]!=std::stod(rad_2)) same=false;

                  std::string token2;
                  std::istringstream ss2(xyz2);
                  if(not(same)){
                    while (std::getline(ss2, token2,' ') ) {
                      spheres.push_back(std::stod(token2));
                      //std::cout << "Token: " << token2 << std::endl;
                    }
                    //std::cout << "XYZ: " << xyz2 << std::endl;
                    //std::cout << "Radius: " << rad_2 << std::endl;
                    spheres.push_back(std::stod(rad_2));
                  }
                  
                }
            }
            found=true; // Stop looking for the child link once found
          }
        }
        

      }
    }

    joint = joint->NextSiblingElement("joint");
  }
  //std::cout << std::endl;
  
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

static dyn_var<int> fk(const Model &model,const tinyxml2::XMLElement* root_one_sph, const tinyxml2::XMLElement* root_mult_sph,dyn_var<ctup::EigenMatrix<ctup::BlazeStaticVector<double,16>>> q) {
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

  dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> dx;
  dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> dy;
  dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> dz;
  dyn_var<vector_t<double>> dr;

  dyn_var<vector_t<vector_t<ctup::BlazeStaticVector<double,16>>>> sx;
  dyn_var<vector_t<vector_t<ctup::BlazeStaticVector<double,16>>>> sy;
  dyn_var<vector_t<vector_t<ctup::BlazeStaticVector<double,16>>>> sz;
  dyn_var<vector_t<vector_t<double>>> sr;

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
  /*
    if(i==2){
      dyn_var<EigenMatrix<ctup::EigenMatrix<double,16,1>, 6, 6>> final_ans;
      toPinEigen(final_ans, X_0[2]);
    }
  */

    joint_name = model.names[i];
    std::cout<<joint_name<<std::endl;

    std::vector<double> spheres=set_spheres(root_one_sph, root_mult_sph, joint_name);
    if(spheres.size()!=0){
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

      dyn_var<ctup::EigenMatrix<double,16,1>> p_global[3];
      for(static_var<size_t> l=0;l<3;l=l+1){
          p_global[l]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, l) * spheres[0];
          for(static_var<size_t> j=1;j<3;j=j+1){
            p_global[l]=p_global[l] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(j, l) * spheres[j];
          }
      }

      p_global[0]=p_global[0] + t[0];
      p_global[1]=p_global[1] + t[1];
      p_global[2]=p_global[2] + t[2];

      dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> x;
      x.resize((spheres.size()-4)/4);
      dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> y;
      y.resize((spheres.size()-4)/4);
      dyn_var<vector_t<ctup::BlazeStaticVector<double,16>>> z;
      z.resize((spheres.size()-4)/4);

      dyn_var<vector_t<double>> rad_sph;
      rad_sph.resize((spheres.size()-4)/4);

      for(static_var<size_t> k=7;k<spheres.size();k=k+4){
        static_var<int> ind=-1+(k/4);

        x[ind]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, 0) * spheres[0+ind*4];
        for(static_var<size_t> j=1;j<3;j=j+1){
          x[ind]=x[ind] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(0, j) * spheres[j+ind*4];
        }

        y[ind]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, 0) * spheres[0+ind*4];
        for(static_var<size_t> j=1;j<3;j=j+1){
          y[ind]=y[ind] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(1, j) * spheres[j+ind*4];
        }

        z[ind]= ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, 0) * spheres[0+ind*4];
        for(static_var<size_t> j=1;j<3;j=j+1){
          z[ind]=z[ind] + ctup::Xform_expr_leaf<ctup::EigenMatrix<double,16,1>>(X_0[i]).get_value_at(2, j) * spheres[j+ind*4];
        }


        x[ind]=x[ind] + t[0];
        y[ind]=y[ind] + t[1];
        z[ind]=z[ind] + t[2];

        rad_sph[ind]=spheres[k];
      }
      dyn_var<int> res;
      if(i!=1){
        res= ctup::backend::self_collision(p_global[0], p_global[1], p_global[2], spheres[3], x, y, z, rad_sph, dx, dy, dz, dr, sx, sy, sz, sr);
      }
      res= ctup::backend::Sphere_Environment_Collision(p_global[0], p_global[1], p_global[2], spheres[3], x, y, z, rad_sph);

      if(i!=(size_t)model.njoints-1){
        dx.push_back(p_global[0]);
        dy.push_back(p_global[1]);
        dz.push_back(p_global[2]);
        dr.push_back(spheres[3]);

        sx.push_back(x);
        sy.push_back(y);
        sz.push_back(z);
        sr.push_back(rad_sph);
      }
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

  // Load the URDF file
  tinyxml2::XMLDocument doc;
  if (doc.LoadFile(urdf_filename) != tinyxml2::XML_SUCCESS) {
      std::cerr << "Failed to load URDF file: " << urdf_filename << std::endl;
      return -1;
  }

  // Get the root element
  tinyxml2::XMLElement* root_one_sph = doc.RootElement();
  if (!root_one_sph) {
      std::cerr << "Invalid URDF structure." << std::endl;
      return -1;
  }

  const char* urdf_filename_2 = argv[2];
  std::cout << urdf_filename_2 << "\n";

  // Load the URDF file 2
  tinyxml2::XMLDocument doc_2;
  if (doc_2.LoadFile(urdf_filename_2) != tinyxml2::XML_SUCCESS) {
      std::cerr << "Failed to load URDF file: " << urdf_filename_2 << std::endl;
      return -1;
  }

  // Get the root element
  tinyxml2::XMLElement* root_mult_sph = doc_2.RootElement();
  if (!root_mult_sph) {
      std::cerr << "Invalid URDF structure." << std::endl;
      return -1;
  }

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

  const std::string header_filename = (argc <= 4) ? "./fk_gen.h" : argv[4];
  std::cout << header_filename << "\n";

  Model model;
  pinocchio::urdf::buildModel(urdf_filename, model);

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
  ast = context.extract_function_ast(fk, "fk", model, root_one_sph, root_mult_sph);
  block::c_code_generator::generate_code(ast, of, 0);

  of << "}\n";
}