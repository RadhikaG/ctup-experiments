#pragma once

#include "rla_rnea/gen/rnea_gen_baxter.h"
#include "rla_rnea/gen/rnea_gen_hyq.h"
#include "rla_rnea/gen/rnea_gen_iiwa.h"

#include <Eigen/Dense>

// ============================================================================
// Input Traits
// ============================================================================

// Scalar input (batch size = 1)
template<int NDOF>
struct ScalarInput {
    static constexpr int batch_size = 1;

    using ConfigVec = Eigen::VectorXd;
    using VelocityVec = Eigen::VectorXd;
    using TorqueVec = Eigen::VectorXd;
};

// TODO: Add BatchedInput when batched RNEA code generation is implemented

// ============================================================================
// Robot Traits
// ============================================================================

struct BaxterTraits {
    static constexpr const char* name = "baxter";
    static constexpr int ndof = 19;

    using RneaFunc = Eigen::VectorXd(*)(Eigen::VectorXd&, Eigen::VectorXd&);
    static constexpr RneaFunc rnea = ctup_gen_baxter::rnea;
};

struct HyqTraits {
    static constexpr const char* name = "hyq";
    static constexpr int ndof = 12;

    using RneaFunc = Eigen::VectorXd(*)(Eigen::VectorXd&, Eigen::VectorXd&);
    static constexpr RneaFunc rnea = ctup_gen_hyq::rnea;
};

struct IiwaTraits {
    static constexpr const char* name = "iiwa";
    static constexpr int ndof = 7;

    using RneaFunc = Eigen::VectorXd(*)(Eigen::VectorXd&, Eigen::VectorXd&);
    static constexpr RneaFunc rnea = ctup_gen_iiwa::rnea;
};
