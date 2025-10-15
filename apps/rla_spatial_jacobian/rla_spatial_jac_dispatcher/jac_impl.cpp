#include "robot_traits.h"
#include "rla_spatial_jacobian/gen/scalar/jac_gen_panda.h"
#include "rla_spatial_jacobian/gen/batched/jac_gen_panda.h"
#include "rla_spatial_jacobian/gen/scalar/jac_gen_iiwa.h"
#include "rla_spatial_jacobian/gen/batched/jac_gen_iiwa.h"
#include "rla_spatial_jacobian/gen/scalar/jac_gen_hyq.h"
#include "rla_spatial_jacobian/gen/batched/jac_gen_hyq.h"
#include "rla_spatial_jacobian/gen/scalar/jac_gen_baxter.h"
#include "rla_spatial_jacobian/gen/batched/jac_gen_baxter.h"

namespace rla_jac_runtime::dispatcher {

//==============================================================================
// Panda Implementations (use generated code)
//==============================================================================

void jac_scalar_panda(const Eigen::VectorXd& q, Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter (no return value)
    Eigen::VectorXd q_copy = q;  // Generated code takes non-const reference
    rla_jac_gen_panda::get_eef_world_jacobian(q_copy, J);
}

void jac_batched_panda_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Panda, float, 8>& q,
    Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter and handles float->double conversion
    rla_jac_gen_panda::batched_jac(q, J);
}

//==============================================================================
// iiwa Implementations (use generated code)
//==============================================================================

void jac_scalar_iiwa(const Eigen::VectorXd& q, Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter (no return value)
    Eigen::VectorXd q_copy = q;  // Generated code takes non-const reference
    rla_jac_gen_iiwa::get_eef_world_jacobian(q_copy, J);
}

void jac_batched_iiwa_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::iiwa, float, 8>& q,
    Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter and handles float->double conversion
    rla_jac_gen_iiwa::batched_jac(q, J);
}

//==============================================================================
// Hyq Implementations (use generated code)
//==============================================================================

void jac_scalar_hyq(const Eigen::VectorXd& q, Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter (no return value)
    Eigen::VectorXd q_copy = q;  // Generated code takes non-const reference
    rla_jac_gen_hyq::get_eef_world_jacobian(q_copy, J);
}

void jac_batched_hyq_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Hyq, float, 8>& q,
    Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter and handles float->double conversion
    rla_jac_gen_hyq::batched_jac(q, J);
}

//==============================================================================
// Baxter Implementations (use generated code)
//==============================================================================

void jac_scalar_baxter(const Eigen::VectorXd& q, Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter (no return value)
    Eigen::VectorXd q_copy = q;  // Generated code takes non-const reference
    rla_jac_gen_baxter::get_eef_world_jacobian(q_copy, J);
}

void jac_batched_baxter_float_8(
    const rla_jac_runtime::ConfigurationBlock<rla_jac_runtime::robots::Baxter, float, 8>& q,
    Eigen::MatrixXd& J) {
    // Call generated code - it writes directly to output parameter and handles float->double conversion
    rla_jac_gen_baxter::batched_jac(q, J);
}

} // namespace rla_jac_runtime::dispatcher
