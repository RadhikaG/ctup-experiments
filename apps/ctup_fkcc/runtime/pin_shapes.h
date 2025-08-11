#ifndef CTUP_FKCC_PIN_SHAPES_H
#define CTUP_FKCC_PIN_SHAPES_H

#include <memory>
#include <pinocchio/fwd.hpp>
#include "pinocchio/collision/collision.hpp"
#include <vamp/collision/environment.hh>
#include <vamp/collision/shapes.hh>

namespace ctup_runtime {

namespace pin_compat {

using Transform3f = hpp::fcl::Transform3f;

template <typename T>
std::shared_ptr<hpp::fcl::CollisionObject> to_fcl_box(const vamp::collision::Cuboid<T> &box)
{
    auto geom = std::make_shared<hpp::fcl::Box>(
        box.axis_1_r * 2,
        box.axis_2_r * 2,
        box.axis_3_r * 2
    );

    Eigen::Matrix3d rot;
    rot.col(0) = Eigen::Vector3d(box.axis_1_x, box.axis_1_y, box.axis_1_z);
    rot.col(1) = Eigen::Vector3d(box.axis_2_x, box.axis_2_y, box.axis_2_z);
    rot.col(2) = Eigen::Vector3d(box.axis_3_x, box.axis_3_y, box.axis_3_z);

    Eigen::Vector3d trans(box.x, box.y, box.z); 

    Transform3f tf;
    tf.setRotation(rot);
    tf.setTranslation(trans);

    return std::make_shared<hpp::fcl::CollisionObject>(geom, tf);
}


template <typename T>
static std::shared_ptr<hpp::fcl::CollisionObject> to_fcl_cylinder(const vamp::collision::Cylinder<T> &cyl)
{
    float length = std::sqrt(cyl.xv * cyl.xv + cyl.yv * cyl.yv + cyl.zv * cyl.zv);
    auto geom = std::make_shared<hpp::fcl::Cylinder>(cyl.r, length);

    Eigen::Vector3d axis(cyl.xv, cyl.yv, cyl.zv);
    axis.normalize();

    Eigen::Matrix3d rot;
    Eigen::Vector3d z_axis = axis;
    Eigen::Vector3d tmp = (std::abs(z_axis.z()) < 0.99)
                            ? Eigen::Vector3d::UnitZ()
                            : Eigen::Vector3d::UnitY();
    Eigen::Vector3d x_axis = (tmp.cross(z_axis)).normalized();
    Eigen::Vector3d y_axis = z_axis.cross(x_axis);

    rot.col(0) = x_axis;
    rot.col(1) = y_axis;
    rot.col(2) = z_axis;

    Eigen::Vector3d center(
        cyl.x1 + 0.5 * cyl.xv,
        cyl.y1 + 0.5 * cyl.yv,
        cyl.z1 + 0.5 * cyl.zv
    );

    Transform3f tf;
    tf.setRotation(rot);
    tf.setTranslation(center);

    return std::make_shared<hpp::fcl::CollisionObject>(geom, tf);
}

template <typename T>
static std::shared_ptr<hpp::fcl::CollisionObject> to_fcl_sphere(const vamp::collision::Sphere<T> &sphere)
{
    auto geom = std::make_shared<hpp::fcl::Sphere>(sphere.r);

    Transform3f tf;
    Eigen::Vector3d trans(sphere.x, sphere.y, sphere.z);
    tf.setTranslation(trans);
    Eigen::Matrix3d I = Eigen::Matrix3d::Identity();
    tf.setRotation(I);

    return std::make_shared<hpp::fcl::CollisionObject>(geom, tf);
}

template <typename T>
static std::shared_ptr<hpp::fcl::CollisionObject> to_fcl_capsule(const vamp::collision::Capsule<T> &caps)
{
    float length = std::sqrt(caps.xv * caps.xv + caps.yv * caps.yv + caps.zv * caps.zv);
    auto geom = std::make_shared<hpp::fcl::Capsule>(caps.r, length);

    Eigen::Vector3d axis(caps.xv, caps.yv, caps.zv);
    axis.normalize();

    Eigen::Matrix3d rot;
    Eigen::Vector3d z_axis = axis;
    Eigen::Vector3d tmp = (std::abs(z_axis.z()) < 0.99)
                            ? Eigen::Vector3d::UnitZ()
                            : Eigen::Vector3d::UnitY();
    Eigen::Vector3d x_axis = (tmp.cross(z_axis)).normalized();
    Eigen::Vector3d y_axis = z_axis.cross(x_axis);

    rot.col(0) = x_axis;
    rot.col(1) = y_axis;
    rot.col(2) = z_axis;

    Eigen::Vector3d center(
        caps.x1 + 0.5 * caps.xv,
        caps.y1 + 0.5 * caps.yv,
        caps.z1 + 0.5 * caps.zv
    );

    Transform3f tf;
    tf.setRotation(rot);
    tf.setTranslation(center);

    return std::make_shared<hpp::fcl::CollisionObject>(geom, tf);
}

}

}

#endif
