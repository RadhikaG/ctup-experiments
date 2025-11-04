#pragma once

#include <Eigen/Dense>
#include "rla_fk/runtime/utils.h"

// Forward declarations for wrapper functions (implemented in fk_impl.cpp)
// These wrappers are compiled with -march=native and create an ABI boundary

// Scalar FK wrappers
Eigen::Matrix<double, 6, 6> fk_scalar_baxter(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_scalar_hyq(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_scalar_iiwa(Eigen::VectorXd& q);

// Eigenmatrix FK wrappers
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_baxter(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_hyq(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_iiwa(Eigen::VectorXd& q);

// Batched FK wrappers (uses types from utils.h)
// Naming convention: fk_batched_{robot}_{dtype}_{batchsize}
void fk_batched_baxter_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::baxter, double, 8>& q, Eigen::MatrixXd& result);
void fk_batched_hyq_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::hyq, double, 8>& q, Eigen::MatrixXd& result);
void fk_batched_iiwa_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::iiwa, double, 8>& q, Eigen::MatrixXd& result);

// Synth_12 robot wrappers
Eigen::Matrix<double, 6, 6> fk_scalar_serial_12dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_scalar_dual_6dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_scalar_triple_4dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_scalar_quad_3dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_scalar_tree_2_5_5(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_serial_12dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_dual_6dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_triple_4dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_quad_3dof(Eigen::VectorXd& q);
Eigen::Matrix<double, 6, 6> fk_eigenmatrix_tree_2_5_5(Eigen::VectorXd& q);
void fk_batched_serial_12dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result);
void fk_batched_dual_6dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result);
void fk_batched_triple_4dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result);
void fk_batched_quad_3dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result);
void fk_batched_tree_2_5_5_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result);

// ============================================================================
// Robot Traits for FK
// ============================================================================

namespace ctup_runtime::dispatcher {

struct BaxterTraits {
    static constexpr const char* name = "baxter";
    using RobotType = ctup_runtime::robots::baxter;
    static constexpr int ndof = RobotType::ndof;

    // Scalar FK: returns end-effector 6x6 transform
    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_baxter;

    // Eigenmatrix FK: returns end-effector 6x6 transform
    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_baxter;

    // Batched FK: template parameterized by dtype and batch size
    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::baxter, Scalar, BatchSize>&, Eigen::MatrixXd&);

    // Default batched FK (double, batch size 8)
    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_baxter_double_8;
};

struct HyqTraits {
    static constexpr const char* name = "hyq";
    using RobotType = ctup_runtime::robots::hyq;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_hyq;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_hyq;

    // Batched FK: template parameterized by dtype and batch size
    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::hyq, Scalar, BatchSize>&, Eigen::MatrixXd&);

    // Default batched FK (double, batch size 8)
    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_hyq_double_8;
};

struct iiwaTraits {
    static constexpr const char* name = "iiwa";
    using RobotType = ctup_runtime::robots::iiwa;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_iiwa;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_iiwa;

    // Batched FK: template parameterized by dtype and batch size
    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::iiwa, Scalar, BatchSize>&, Eigen::MatrixXd&);

    // Default batched FK (double, batch size 8)
    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_iiwa_double_8;
};

struct Serial12dofTraits {
    static constexpr const char* name = "serial_12dof";
    using RobotType = ctup_runtime::robots::synth_12;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_serial_12dof;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_serial_12dof;

    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, Scalar, BatchSize>&, Eigen::MatrixXd&);

    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_serial_12dof_double_8;
};

struct Dual6dofTraits {
    static constexpr const char* name = "dual_6dof";
    using RobotType = ctup_runtime::robots::synth_12;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_dual_6dof;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_dual_6dof;

    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, Scalar, BatchSize>&, Eigen::MatrixXd&);

    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_dual_6dof_double_8;
};

struct Triple4dofTraits {
    static constexpr const char* name = "triple_4dof";
    using RobotType = ctup_runtime::robots::synth_12;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_triple_4dof;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_triple_4dof;

    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, Scalar, BatchSize>&, Eigen::MatrixXd&);

    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_triple_4dof_double_8;
};

struct Quad3dofTraits {
    static constexpr const char* name = "quad_3dof";
    using RobotType = ctup_runtime::robots::synth_12;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_quad_3dof;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_quad_3dof;

    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, Scalar, BatchSize>&, Eigen::MatrixXd&);

    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_quad_3dof_double_8;
};

struct Tree255Traits {
    static constexpr const char* name = "tree_2_5_5";
    using RobotType = ctup_runtime::robots::synth_12;
    static constexpr int ndof = RobotType::ndof;

    using FkScalarFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkScalarFunc fk_scalar = fk_scalar_tree_2_5_5;

    using FkEigenmatrixFunc = Eigen::Matrix<double, 6, 6>(*)(Eigen::VectorXd&);
    static constexpr FkEigenmatrixFunc fk_eigenmatrix = fk_eigenmatrix_tree_2_5_5;

    template<typename Scalar, size_t BatchSize>
    using FkBatchedFunc = void(*)(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, Scalar, BatchSize>&, Eigen::MatrixXd&);

    static constexpr FkBatchedFunc<double, 8> fk_batched_double_8 = fk_batched_tree_2_5_5_double_8;
};

} // namespace ctup_runtime::dispatcher
