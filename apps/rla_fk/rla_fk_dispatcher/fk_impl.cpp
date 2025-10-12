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
