#ifndef CTUP_FKCC_PIN_TYPEDEFS_H
#define CTUP_FKCC_PIN_TYPEDEFS_H
#include <memory>
#include "Eigen/Dense"
#include <vamp/collision/environment.hh>

namespace ctup_runtime {

namespace pin_compat {

template <typename Robot>
using ConfigurationBlockRobotEigen = std::array<Eigen::Matrix<float, Robot::ndim, 1>, 8>;

template <size_t ndim>
using ConfigurationBlockDimEigen = std::array<Eigen::Matrix<float, ndim, 1>, 8>;

struct PinFKCC {

  PinFKCC();

  PinFKCC(std::string robot_name, const vamp::collision::Environment<float> &vamp_env);

  ~PinFKCC();

  // Delete copy semantics
  PinFKCC(const PinFKCC&) = delete;
  PinFKCC& operator=(const PinFKCC&) = delete;

  // Default move semantics
  PinFKCC(PinFKCC&&) noexcept;
  PinFKCC& operator=(PinFKCC&&) noexcept;

  
  template <size_t ndim>
  bool fkcc_pin(const ConfigurationBlockDimEigen<ndim> &q_block);

  struct Impl;
  std::unique_ptr<Impl> impl_;
};

}

}

#endif
