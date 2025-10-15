#ifndef RLA_SPATIAL_JAC_DISPATCHER_ROBOT_TRAITS_H
#define RLA_SPATIAL_JAC_DISPATCHER_ROBOT_TRAITS_H

#include "rla_spatial_jacobian/runtime/utils.h"
#include <Eigen/Dense>

namespace rla_jac_runtime::dispatcher {

// Forward declarations of implementation functions
// Scalar Jacobian functions (writes 6 x ndof matrix to output parameter)
void jac_scalar_panda(const Eigen::VectorXd& q, Eigen::MatrixXd& J);
void jac_scalar_iiwa(const Eigen::VectorXd& q, Eigen::MatrixXd& J);
void jac_scalar_hyq(const Eigen::VectorXd& q, Eigen::MatrixXd& J);
void jac_scalar_baxter(const Eigen::VectorXd& q, Eigen::MatrixXd& J);

// Batched Jacobian functions - float, batch size 8
void jac_batched_panda_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Panda, float, 8>& q,
    Eigen::MatrixXd& J);
void jac_batched_iiwa_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::iiwa, float, 8>& q,
    Eigen::MatrixXd& J);
void jac_batched_hyq_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Hyq, float, 8>& q,
    Eigen::MatrixXd& J);
void jac_batched_baxter_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Baxter, float, 8>& q,
    Eigen::MatrixXd& J);

//==============================================================================
// Robot Trait Structs
//==============================================================================

struct PandaTraits {
    static constexpr const char* name = "panda";
    using RobotType = rla_jac_runtime::robots::Panda;
    static constexpr int ndim = RobotType::ndim;

    // Scalar Jacobian: writes 6 x ndim matrix to output parameter
    using JacScalarFunc = void(*)(const Eigen::VectorXd&, Eigen::MatrixXd&);
    static constexpr JacScalarFunc jac_scalar = jac_scalar_panda;

    // Batched Jacobian: float, batch size 8
    using JacBatchedFunc = void(*)(
        const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Panda, float, 8>&,
        Eigen::MatrixXd&);
    static constexpr JacBatchedFunc jac_batched_float_8 = jac_batched_panda_float_8;
};

struct iiwaTraits {
    static constexpr const char* name = "iiwa";
    using RobotType = rla_jac_runtime::robots::iiwa;
    static constexpr int ndim = RobotType::ndim;

    // Scalar Jacobian: writes 6 x ndim matrix to output parameter
    using JacScalarFunc = void(*)(const Eigen::VectorXd&, Eigen::MatrixXd&);
    static constexpr JacScalarFunc jac_scalar = jac_scalar_iiwa;

    // Batched Jacobian: float, batch size 8
    using JacBatchedFunc = void(*)(
        const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::iiwa, float, 8>&,
        Eigen::MatrixXd&);
    static constexpr JacBatchedFunc jac_batched_float_8 = jac_batched_iiwa_float_8;
};

struct hyqTraits {
    static constexpr const char* name = "hyq";
    using RobotType = rla_jac_runtime::robots::Hyq;
    static constexpr int ndim = RobotType::ndim;

    // Scalar Jacobian: writes 6 x ndim matrix to output parameter
    using JacScalarFunc = void(*)(const Eigen::VectorXd&, Eigen::MatrixXd&);
    static constexpr JacScalarFunc jac_scalar = jac_scalar_hyq;

    // Batched Jacobian: float, batch size 8
    using JacBatchedFunc = void(*)(
        const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Hyq, float, 8>&,
        Eigen::MatrixXd&);
    static constexpr JacBatchedFunc jac_batched_float_8 = jac_batched_hyq_float_8;
};

struct baxterTraits {
    static constexpr const char* name = "baxter";
    using RobotType = rla_jac_runtime::robots::Baxter;
    static constexpr int ndim = RobotType::ndim;

    // Scalar Jacobian: writes 6 x ndim matrix to output parameter
    using JacScalarFunc = void(*)(const Eigen::VectorXd&, Eigen::MatrixXd&);
    static constexpr JacScalarFunc jac_scalar = jac_scalar_baxter;

    // Batched Jacobian: float, batch size 8
    using JacBatchedFunc = void(*)(
        const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Baxter, float, 8>&,
        Eigen::MatrixXd&);
    static constexpr JacBatchedFunc jac_batched_float_8 = jac_batched_baxter_float_8;
};

} // namespace rla_jac_runtime::dispatcher

#endif // RLA_SPATIAL_JAC_DISPATCHER_ROBOT_TRAITS_H
