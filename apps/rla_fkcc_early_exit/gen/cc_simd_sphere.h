// clang-format off

#include "Eigen/Dense"

#include "ctup/typedefs.h"

#include "rla_fkcc_early_exit/runtime/collision.h"

namespace ctup_gen {

static int fkcc (vamp::collision::Environment<blaze::StaticVector<float, 8>> const& arg4, ctup_runtime::ConfigurationBlockRobot<ctup_runtime::robots::Sphere> const& arg5) {
  return true;
}

}
