#ifndef RLA_SD_GRAD_DISPATCHER_H
#define RLA_SD_GRAD_DISPATCHER_H

#include <string>
#include <stdexcept>
#include "Eigen/Dense"
#include "rla_grad_self_collision/runtime/utils.h"

namespace cg_sd_runtime {
namespace dispatcher {

// Type aliases for each robot's signed distance gradient function
// These ensure type safety - each robot has its own configuration block type

using PandaSdGradFunc = void(*)(
    const ConfigurationBlockRobot<robots::Panda>&,
    Eigen::MatrixXd&,  // signed_distances output: (batch_dim, n_collision_pairs)
    Eigen::MatrixXd&   // constraint_jacobian output: (batch_dim * n_collision_pairs, ndof)
);

using UR5SdGradFunc = void(*)(
    const ConfigurationBlockRobot<robots::UR5>&,
    Eigen::MatrixXd&,
    Eigen::MatrixXd&
);

// Metadata about a specific robot-fidelity model
struct ModelInfo {
    std::string robot;
    std::string fidelity;
    int ndof;
    size_t n_collision_pairs;

    ModelInfo(const std::string& r, const std::string& f, int n, size_t ncp)
        : robot(r), fidelity(f), ndof(n), n_collision_pairs(ncp) {}
};

// Main dispatcher class with per-robot accessor functions
struct SdGradDispatcher {
    // Get function pointer for a specific Panda fidelity
    // Supported fidelities: "spherized_1", "spherized", etc.
    // Returns nullptr if fidelity not found
    static PandaSdGradFunc get_panda_function(const std::string& fidelity);

    // Get function pointer for a specific UR5 fidelity
    // Returns nullptr if fidelity not found
    static UR5SdGradFunc get_ur5_function(const std::string& fidelity);

    // Get metadata about a specific robot-fidelity combination
    // Throws std::runtime_error if combination not found
    static ModelInfo get_model_info(const std::string& robot, const std::string& fidelity);

    // List all available fidelities for a given robot
    // Returns empty vector if robot not found
    static std::vector<std::string> list_fidelities(const std::string& robot);
};

} // namespace dispatcher
} // namespace cg_sd_runtime

#endif // RLA_SD_GRAD_DISPATCHER_H
