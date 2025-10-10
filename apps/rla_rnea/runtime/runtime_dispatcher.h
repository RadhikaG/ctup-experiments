#pragma once

#include "robot_traits.h"
#include <functional>
#include <stdexcept>
#include <string>

struct RneaDispatcher {
    using RneaFunction = std::function<Eigen::VectorXd(Eigen::VectorXd&, Eigen::VectorXd&)>;

    static RneaFunction get_rnea_function(const std::string& robot) {
        if (robot == "baxter") {
            return BaxterTraits::rnea;
        } else if (robot == "hyq") {
            return HyqTraits::rnea;
        } else if (robot == "iiwa") {
            return IiwaTraits::rnea;
        } else {
            throw std::runtime_error("Unknown robot: " + robot);
        }
    }
};
