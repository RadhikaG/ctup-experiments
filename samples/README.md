### Sample descriptions

* sample8: self contained unrolled FK implementation using raw dyn\_var Eigen::Matrix isolated from ctup
* sample9: scalar FK using ctup
* sample10: scalar RNEA using ctup
* sample11: batched FK using ctup
* sample12: batched FK with no trace-time sparsity, no unrolling, so dyn\_var loops with structure known at stage 1 compile-time
* sample13: batched fused FKCC with early exit
* sample14: scalar spatial jacobian wrt WORLD
* sample15: batched fused FKCC with signed distance and gradient calcs (no early exit)
* sample16: batched spatial jacobian wrt WORLD (output: jacobian for final joint)
