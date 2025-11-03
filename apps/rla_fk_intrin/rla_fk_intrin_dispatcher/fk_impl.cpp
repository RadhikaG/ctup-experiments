#include "robot_traits.h"
#include "fk_dispatcher.h"
#include "rla_fk_intrin/runtime/utils.h"

// Include generated FK headers (will be generated later)
// #include "rla_fk_intrin/gen/fk_intrin_baxter.h"
// #include "rla_fk_intrin/gen/fk_intrin_hyq.h"
#include "rla_fk_intrin/gen/fk_intrin_iiwa.h"
// #include "rla_fk_intrin/gen/fk_intrin_panda.h"

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
