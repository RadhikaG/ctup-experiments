#pragma once

#include "robot_traits.h"
#include <functional>
#include <stdexcept>
#include <string>

namespace ctup_runtime::dispatcher {

struct FkDispatcher {
    // Scalar FK function type
    using FkScalarFunction = std::function<Eigen::Matrix<double, 6, 6>(Eigen::VectorXd&)>;

    // Eigenmatrix FK function type
    using FkEigenmatrixFunction = std::function<Eigen::Matrix<double, 6, 6>(Eigen::VectorXd&)>;

    static FkScalarFunction get_fk_scalar_function(const std::string& robot) {
        if (robot == "baxter") {
            return BaxterTraits::fk_scalar;
        } else if (robot == "hyq") {
            return HyqTraits::fk_scalar;
        } else if (robot == "iiwa") {
            return iiwaTraits::fk_scalar;
        } else {
            throw std::runtime_error("Unknown robot: " + robot);
        }
    }

    static FkEigenmatrixFunction get_fk_eigenmatrix_function(const std::string& robot) {
        if (robot == "baxter") {
            return BaxterTraits::fk_eigenmatrix;
        } else if (robot == "hyq") {
            return HyqTraits::fk_eigenmatrix;
        } else if (robot == "iiwa") {
            return iiwaTraits::fk_eigenmatrix;
        } else {
            throw std::runtime_error("Unknown robot: " + robot);
        }
    }

    // Template-based batched FK dispatcher
    // Returns the batched FK function for a given RobotTraits type, dtype, and batch size
    template<typename RobotTraits, typename Scalar = double, size_t BatchSize = 8>
    static typename RobotTraits::template FkBatchedFunc<Scalar, BatchSize> get_fk_batched_function() {
        // For now, only double with batch size 8 is implemented
        // This will be extended as more implementations are added
        static_assert(std::is_same<Scalar, double>::value && BatchSize == 8,
                      "Only double precision with batch size 8 is currently supported");
        return RobotTraits::fk_batched_double_8;
    }
};

} // namespace ctup_runtime::dispatcher
