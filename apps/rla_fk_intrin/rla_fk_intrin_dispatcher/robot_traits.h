#pragma once

#include <Eigen/Dense>

// Forward declarations for wrapper functions (implemented in fk_impl.cpp)
// These wrappers are compiled with -march=native and create an ABI boundary
// Input: float array of size [ndof * 8] in column-major order (joint-major)
// Output: Eigen::MatrixXd of size [8, 36] with batched results

// Intrinsic FK wrappers (batch size 8, float precision)
// void fk_intrin_baxter(const float* q_data, Eigen::MatrixXd& result);
// void fk_intrin_hyq(const float* q_data, Eigen::MatrixXd& result);
void fk_intrin_iiwa(const float* q_data, Eigen::MatrixXd& result);
// void fk_intrin_panda(const float* q_data, Eigen::MatrixXd& result);

// Synth12 robot wrappers
void fk_intrin_serial_12dof(const float* q_data, Eigen::MatrixXd& result);
void fk_intrin_dual_6dof(const float* q_data, Eigen::MatrixXd& result);
void fk_intrin_triple_4dof(const float* q_data, Eigen::MatrixXd& result);
void fk_intrin_quad_3dof(const float* q_data, Eigen::MatrixXd& result);
void fk_intrin_tree_2_5_5(const float* q_data, Eigen::MatrixXd& result);

// Forward declare robot namespace (defined in utils.h)
namespace ctup_runtime {
namespace robots {
struct iiwa;
struct Synth12;
}
}

// ============================================================================
// Robot Traits for FK with VAMP intrinsics
// ============================================================================

namespace ctup_runtime::dispatcher {

// struct BaxterTraits {
//     static constexpr const char* name = "baxter";
//     using RobotType = ctup_runtime::robots::Baxter;
//     static constexpr int ndof = RobotType::ndof;

//     // Intrinsic FK (batch size 8)
//     using FkIntrinFunc = void(*)(const ctup_runtime::ConfigurationBlock<8, ndof>&, Eigen::MatrixXd&);
//     static constexpr FkIntrinFunc fk_intrin = fk_intrin_baxter;
// };

// struct HyQTraits {
//     static constexpr const char* name = "hyq";
//     using RobotType = ctup_runtime::robots::HyQ;
//     static constexpr int ndof = RobotType::ndof;

//     using FkIntrinFunc = void(*)(const ctup_runtime::ConfigurationBlock<8, ndof>&, Eigen::MatrixXd&);
//     static constexpr FkIntrinFunc fk_intrin = fk_intrin_hyq;
// };

struct iiwaTraits {
    static constexpr const char* name = "iiwa";
    static constexpr int ndof = 7;

    using FkIntrinFunc = void(*)(const float*, Eigen::MatrixXd&);
    static constexpr FkIntrinFunc fk_intrin = fk_intrin_iiwa;
};

// struct PandaTraits {
//     static constexpr const char* name = "panda";
//     using RobotType = ctup_runtime::robots::Panda;
//     static constexpr int ndof = RobotType::ndof;

//     using FkIntrinFunc = void(*)(const ctup_runtime::ConfigurationBlock<8, ndof>&, Eigen::MatrixXd&);
//     static constexpr FkIntrinFunc fk_intrin = fk_intrin_panda;
// };

struct Serial12dofTraits {
    static constexpr const char* name = "serial_12dof";
    static constexpr int ndof = 12;

    using FkIntrinFunc = void(*)(const float*, Eigen::MatrixXd&);
    static constexpr FkIntrinFunc fk_intrin = fk_intrin_serial_12dof;
};

struct Dual6dofTraits {
    static constexpr const char* name = "dual_6dof";
    static constexpr int ndof = 12;

    using FkIntrinFunc = void(*)(const float*, Eigen::MatrixXd&);
    static constexpr FkIntrinFunc fk_intrin = fk_intrin_dual_6dof;
};

struct Triple4dofTraits {
    static constexpr const char* name = "triple_4dof";
    static constexpr int ndof = 12;

    using FkIntrinFunc = void(*)(const float*, Eigen::MatrixXd&);
    static constexpr FkIntrinFunc fk_intrin = fk_intrin_triple_4dof;
};

struct Quad3dofTraits {
    static constexpr const char* name = "quad_3dof";
    static constexpr int ndof = 12;

    using FkIntrinFunc = void(*)(const float*, Eigen::MatrixXd&);
    static constexpr FkIntrinFunc fk_intrin = fk_intrin_quad_3dof;
};

struct Tree255Traits {
    static constexpr const char* name = "tree_2_5_5";
    static constexpr int ndof = 12;

    using FkIntrinFunc = void(*)(const float*, Eigen::MatrixXd&);
    static constexpr FkIntrinFunc fk_intrin = fk_intrin_tree_2_5_5;
};

} // namespace ctup_runtime::dispatcher
