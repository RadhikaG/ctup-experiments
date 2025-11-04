#include "robot_traits.h"
#include "fk_dispatcher.h"
#include "rla_fk_intrin/runtime/utils.h"

// Include generated FK headers (will be generated later)
// #include "rla_fk_intrin/gen/fk_intrin_baxter.h"
// #include "rla_fk_intrin/gen/fk_intrin_hyq.h"
#include "rla_fk_intrin/gen/fk_intrin_iiwa.h"
// #include "rla_fk_intrin/gen/fk_intrin_panda.h"

// Synth12 robot headers
#include "rla_fk_intrin/gen/fk_intrin_serial_12dof.h"
#include "rla_fk_intrin/gen/fk_intrin_dual_6dof.h"
#include "rla_fk_intrin/gen/fk_intrin_triple_4dof.h"
#include "rla_fk_intrin/gen/fk_intrin_quad_3dof.h"
#include "rla_fk_intrin/gen/fk_intrin_tree_2_5_5.h"

// This file forces the FK implementations to be compiled into object code
// with -march=native, creating an ABI boundary between SIMD code and
// non-SIMD code (like Pinocchio)

// Wrapper functions that will be compiled with -march=native and linked into the static library

// void fk_intrin_baxter(const ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Baxter::ndof>& q, Eigen::MatrixXd& result) {
//     ctup_gen_baxter::batched_fk_vamp(q, result);
// }

// void fk_intrin_hyq(const ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::HyQ::ndof>& q, Eigen::MatrixXd& result) {
//     ctup_gen_hyq::batched_fk_vamp(q, result);
// }

void fk_intrin_iiwa(const float* q_data, Eigen::MatrixXd& result) {
    // Construct VAMP ConfigurationBlock from float array using VAMP's unaligned constructor
    // Pass false to indicate the data may not be 32-byte aligned
    ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::iiwa::ndof> q(q_data, false);
    ctup_gen_iiwa::batched_fk_vamp(q, result);
}

// void fk_intrin_panda(const ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Panda::ndof>& q, Eigen::MatrixXd& result) {
//     ctup_gen_panda::batched_fk_vamp(q, result);
// }

// Synth12 robot wrappers
void fk_intrin_serial_12dof(const float* q_data, Eigen::MatrixXd& result) {
    ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Synth12::ndof> q(q_data, false);
    ctup_gen_serial_12dof::batched_fk_vamp(q, result);
}

void fk_intrin_dual_6dof(const float* q_data, Eigen::MatrixXd& result) {
    ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Synth12::ndof> q(q_data, false);
    ctup_gen_dual_6dof::batched_fk_vamp(q, result);
}

void fk_intrin_triple_4dof(const float* q_data, Eigen::MatrixXd& result) {
    ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Synth12::ndof> q(q_data, false);
    ctup_gen_triple_4dof::batched_fk_vamp(q, result);
}

void fk_intrin_quad_3dof(const float* q_data, Eigen::MatrixXd& result) {
    ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Synth12::ndof> q(q_data, false);
    ctup_gen_quad_3dof::batched_fk_vamp(q, result);
}

void fk_intrin_tree_2_5_5(const float* q_data, Eigen::MatrixXd& result) {
    ctup_runtime::ConfigurationBlock<8, ctup_runtime::robots::Synth12::ndof> q(q_data, false);
    ctup_gen_tree_2_5_5::batched_fk_vamp(q, result);
}
