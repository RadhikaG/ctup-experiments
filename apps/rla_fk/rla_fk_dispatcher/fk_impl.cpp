#include "robot_traits.h"
#include "fk_dispatcher.h"

// Include generated FK headers
#include "rla_fk/gen/scalar/fk_gen_baxter.h"
#include "rla_fk/gen/scalar/fk_gen_hyq.h"
#include "rla_fk/gen/scalar/fk_gen_iiwa.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_baxter.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_hyq.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_iiwa.h"
#include "rla_fk/gen/batched/fk_gen_baxter.h"
#include "rla_fk/gen/batched/fk_gen_hyq.h"
#include "rla_fk/gen/batched/fk_gen_iiwa.h"

// Synth_12 robot headers
#include "rla_fk/gen/scalar/fk_gen_serial_12dof.h"
#include "rla_fk/gen/scalar/fk_gen_dual_6dof.h"
#include "rla_fk/gen/scalar/fk_gen_triple_4dof.h"
#include "rla_fk/gen/scalar/fk_gen_quad_3dof.h"
#include "rla_fk/gen/scalar/fk_gen_tree_2_5_5.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_serial_12dof.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_dual_6dof.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_triple_4dof.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_quad_3dof.h"
#include "rla_fk/gen/eigenmatrix/fk_gen_tree_2_5_5.h"
#include "rla_fk/gen/batched/fk_gen_serial_12dof.h"
#include "rla_fk/gen/batched/fk_gen_dual_6dof.h"
#include "rla_fk/gen/batched/fk_gen_triple_4dof.h"
#include "rla_fk/gen/batched/fk_gen_quad_3dof.h"
#include "rla_fk/gen/batched/fk_gen_tree_2_5_5.h"

// This file forces the FK implementations to be compiled into object code
// with -march=native, creating an ABI boundary between SIMD code and
// non-SIMD code (like Pinocchio)

// Wrapper functions that will be compiled with -march=native and linked into the static library

Eigen::Matrix<double, 6, 6> fk_scalar_baxter(Eigen::VectorXd& q) {
    return ctup_gen_baxter::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_scalar_hyq(Eigen::VectorXd& q) {
    return ctup_gen_hyq::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_scalar_iiwa(Eigen::VectorXd& q) {
    return ctup_gen_iiwa::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_baxter(Eigen::VectorXd& q) {
    return ctup_gen_baxter::eigenmatrix_fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_hyq(Eigen::VectorXd& q) {
    return ctup_gen_hyq::eigenmatrix_fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_iiwa(Eigen::VectorXd& q) {
    return ctup_gen_iiwa::eigenmatrix_fk(q);
}

void fk_batched_baxter_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::baxter, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_baxter::batched_fk(q, result);
}

void fk_batched_hyq_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::hyq, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_hyq::batched_fk(q, result);
}

void fk_batched_iiwa_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::iiwa, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_iiwa::batched_fk(q, result);
}

// Synth_12 robot wrappers
Eigen::Matrix<double, 6, 6> fk_scalar_serial_12dof(Eigen::VectorXd& q) {
    return ctup_gen_serial_12dof::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_scalar_dual_6dof(Eigen::VectorXd& q) {
    return ctup_gen_dual_6dof::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_scalar_triple_4dof(Eigen::VectorXd& q) {
    return ctup_gen_triple_4dof::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_scalar_quad_3dof(Eigen::VectorXd& q) {
    return ctup_gen_quad_3dof::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_scalar_tree_2_5_5(Eigen::VectorXd& q) {
    return ctup_gen_tree_2_5_5::fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_serial_12dof(Eigen::VectorXd& q) {
    return ctup_gen_serial_12dof::eigenmatrix_fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_dual_6dof(Eigen::VectorXd& q) {
    return ctup_gen_dual_6dof::eigenmatrix_fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_triple_4dof(Eigen::VectorXd& q) {
    return ctup_gen_triple_4dof::eigenmatrix_fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_quad_3dof(Eigen::VectorXd& q) {
    return ctup_gen_quad_3dof::eigenmatrix_fk(q);
}

Eigen::Matrix<double, 6, 6> fk_eigenmatrix_tree_2_5_5(Eigen::VectorXd& q) {
    return ctup_gen_tree_2_5_5::eigenmatrix_fk(q);
}

void fk_batched_serial_12dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_serial_12dof::batched_fk(q, result);
}

void fk_batched_dual_6dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_dual_6dof::batched_fk(q, result);
}

void fk_batched_triple_4dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_triple_4dof::batched_fk(q, result);
}

void fk_batched_quad_3dof_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_quad_3dof::batched_fk(q, result);
}

void fk_batched_tree_2_5_5_double_8(const ctup_runtime::ConfigurationBlock<ctup_runtime::robots::synth_12, double, 8>& q, Eigen::MatrixXd& result) {
    ctup_gen_tree_2_5_5::batched_fk(q, result);
}
