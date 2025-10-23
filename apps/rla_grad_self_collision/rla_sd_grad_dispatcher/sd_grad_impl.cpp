#include "rla_grad_self_collision/rla_sd_grad_dispatcher/sd_grad_dispatcher.h"

// Include generated code for each robot-fidelity combination
#include "rla_grad_self_collision/gen/panda_spherized.h"
#include "rla_grad_self_collision/gen/panda_spherized_1.h"
#include "rla_grad_self_collision/gen/ur5_spherized.h"
#include "rla_grad_self_collision/gen/ur5_spherized_1.h"

namespace cg_sd_runtime {
namespace dispatcher {

PandaSdGradFunc SdGradDispatcher::get_panda_function(const std::string& fidelity) {
    if (fidelity == "spherized_1") {
        return &cg_sd_gen_panda_spherized_1::self_collision_signed_distances_and_jacobians;
    }
    else if (fidelity == "spherized") {
        return &cg_sd_gen_panda_spherized::self_collision_signed_distances_and_jacobians;
    }

    // Unknown fidelity
    return nullptr;
}

UR5SdGradFunc SdGradDispatcher::get_ur5_function(const std::string& fidelity) {
    if (fidelity == "spherized_1") {
        return &cg_sd_gen_ur5_spherized_1::self_collision_signed_distances_and_jacobians;
    }
    else if (fidelity == "spherized") {
        return &cg_sd_gen_ur5_spherized::self_collision_signed_distances_and_jacobians;
    }

    return nullptr;
}


ModelInfo SdGradDispatcher::get_model_info(const std::string& robot, const std::string& fidelity) {
    // Panda models
    if (robot == "panda") {
        if (fidelity == "spherized_1") {
            return ModelInfo("panda", "spherized_1", 7, 21);
        }
        else if (fidelity == "spherized") {
            return ModelInfo("panda", "spherized", 7, 690);
        }
    }

    // UR5 models
    else if (robot == "ur5") {
        if (fidelity == "spherized_1") {
            return ModelInfo("ur5", "spherized_1", 6, 56);
        }
        else if (fidelity == "spherized") {
            return ModelInfo("ur5", "spherized", 6, 294);
        }
    }

    // Not found
    throw std::runtime_error(
        "Unknown robot-fidelity combination: robot='" + robot +
        "', fidelity='" + fidelity + "'"
    );
}

std::vector<std::string> SdGradDispatcher::list_fidelities(const std::string& robot) {
    std::vector<std::string> fidelities;

    if (robot == "panda") {
        fidelities.push_back("spherized_1");
        fidelities.push_back("spherized");
    }
    else if (robot == "ur5") {
        fidelities.push_back("spherized_1");
        fidelities.push_back("spherized");
    }

    return fidelities;
}

} // namespace dispatcher
} // namespace cg_sd_runtime
