#pragma once

#include "robot_traits.h"
#include <functional>
#include <stdexcept>
#include <string>

namespace ctup_runtime::dispatcher {

struct FkIntrinDispatcher {
    // Template-based intrinsic FK dispatcher
    // Returns the intrinsic FK function for a given RobotTraits type
    template<typename RobotTraits>
    static typename RobotTraits::FkIntrinFunc get_fk_intrin_function() {
        return RobotTraits::fk_intrin;
    }
};

} // namespace ctup_runtime::dispatcher
