#ifndef RLA_SPATIAL_JAC_DISPATCHER_H
#define RLA_SPATIAL_JAC_DISPATCHER_H

#include "robot_traits.h"
#include <string>
#include <functional>
#include <stdexcept>

namespace rla_jac_runtime::dispatcher {

struct JacDispatcher {
    // Scalar Jacobian function type (pass-by-reference for ABI safety)
    using JacScalarFunction = std::function<void(const Eigen::VectorXd&, Eigen::MatrixXd&)>;

    // Get scalar Jacobian function by robot name
    static JacScalarFunction get_jac_scalar_function(const std::string& robot) {
        if (robot == "panda") {
            return PandaTraits::jac_scalar;
        } else if (robot == "iiwa") {
            return iiwaTraits::jac_scalar;
        } else if (robot == "hyq") {
            return hyqTraits::jac_scalar;
        } else if (robot == "baxter") {
            return baxterTraits::jac_scalar;
        } else {
            throw std::runtime_error("Unknown robot: " + robot);
        }
    }

    // Get batched Jacobian function by robot name (float_8 only for now)
    template<typename RobotTraits>
    static typename RobotTraits::JacBatchedFunc get_jac_batched_function() {
        return RobotTraits::jac_batched_float_8;
    }

    // Runtime dispatch version for batched Jacobian
    using JacBatchedFunction = std::function<void(const void*, Eigen::MatrixXd&)>;

    // Helper to get batched function by robot name at runtime
    // Note: Caller must ensure the configuration block matches the robot type
    template<typename Robot>
    static auto get_jac_batched_function_by_name(const std::string& robot) {
        if (robot == "panda") {
            return PandaTraits::jac_batched_float_8;
        } else if (robot == "iiwa") {
            return iiwaTraits::jac_batched_float_8;
        } else if (robot == "hyq") {
            return hyqTraits::jac_batched_float_8;
        } else if (robot == "baxter") {
            return baxterTraits::jac_batched_float_8;
        } else {
            throw std::runtime_error("Unknown robot: " + robot);
        }
    }
};

} // namespace rla_jac_runtime::dispatcher

#endif // RLA_SPATIAL_JAC_DISPATCHER_H
