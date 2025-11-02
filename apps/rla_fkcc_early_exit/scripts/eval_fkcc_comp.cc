#include "ctup/typedefs.h"
#include "rla_fkcc_early_exit/gen/fkcc_panda.h"
#include "vamp/vector.hh"
#include "vamp/utils.hh"
#include "vamp/robots/panda/fk.hh"
#include "rla_fkcc_early_exit/pin_compat/pin_collision.h"
#include <argparse/argparse.hpp>
#include <iostream>

int main(int argc, char ** argv)
{
  argparse::ArgumentParser program("eval_fkcc_comp");

  program.add_argument("--ctup")
      .help("run CTUP benchmark")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--vamp")
      .help("run VAMP benchmark")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--pin")
      .help("run Pinocchio benchmark")
      .default_value(false)
      .implicit_value(true);

  program.add_argument("--n_it")
      .help("number of iterations")
      .default_value(100000)
      .scan<'i', int>();

  try {
      program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      return 1;
  }

  bool ctup = program.get<bool>("--ctup");
  bool vamp = program.get<bool>("--vamp");
  bool pin = program.get<bool>("--pin");
  size_t N_IT = program.get<int>("--n_it");

  //=========== CTUP ================
  //
  // empty env for debug
  if (ctup)
  {
    vamp::collision::Environment<ctup_runtime::avx256f> env_ctup;

    std::array<ctup_runtime::avx256f, 7> q_ctup;
    q_ctup[0] = -0.28;
    q_ctup[1] = -0.47;
    q_ctup[2] = -0.5;
    q_ctup[3] = -1.2;
    q_ctup[4] =  0.82;
    q_ctup[5] = -0.15;
    q_ctup[6] = 0.15;

    bool res;
    auto start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < N_IT; i++)
      res = ctup_gen::fkcc(env_ctup, q_ctup);
    auto nanoseconds = vamp::utils::get_elapsed_nanoseconds(start_time);

    std::cout << "CTUP config valid? " << res << "\n";
    std::cout << "ns taken: " << nanoseconds << "\n";
    std::cout << "avg ns: " << nanoseconds / float(N_IT) << "\n";

    std::cout << "=================================================\n";
  }

  //=========== VAMP ================
  
  // empty env for debug
  if (vamp)
  {
    vamp::collision::Environment<vamp::FloatVector<8>> env_vamp;

    vamp::FloatVector<8, 7> q_vamp;
    q_vamp[0] = -0.28;
    q_vamp[1] = -0.47;
    q_vamp[2] = -0.5;
    q_vamp[3] = -1.2;
    q_vamp[4] =  0.82;
    q_vamp[5] = -0.15;
    q_vamp[6] = 0.15;

    bool res;
    auto start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < N_IT; i++)
      res = vamp::robots::panda::interleaved_sphere_fk<8>(env_vamp, q_vamp);
    auto nanoseconds = vamp::utils::get_elapsed_nanoseconds(start_time);

    std::cout << "VAMP config valid? " << res << "\n";
    std::cout << "ns taken: " << nanoseconds << "\n";
    std::cout << "avg ns: " << nanoseconds / float(N_IT) << "\n";

    std::cout << "=================================================\n";
  }

  //=========== PINOCCHIO  ================

  if (pin)
  {
    vamp::collision::Environment<float> env_pin;
    ctup_runtime::pin_compat::PinFKCC pin_fkcc_data("panda", env_pin);

    ctup_runtime::pin_compat::ConfigurationBlockDimEigen<7> pin_block;

    pin_block[0](0, 0) = -0.28;
    pin_block[0](1, 0) = -0.47;
    pin_block[0](2, 0) = -0.5;
    pin_block[0](3, 0) = -1.2;
    pin_block[0](4, 0) =  0.82;
    pin_block[0](5, 0) = -0.15;
    pin_block[0](6, 0) = 0.15;

    bool res;
    auto start_time = std::chrono::steady_clock::now();
    for (size_t i = 0; i < N_IT; i++)
      res = pin_fkcc_data.fkcc_pin<7>(pin_block);
    auto nanoseconds = vamp::utils::get_elapsed_nanoseconds(start_time);

    std::cout << "Pin config valid? " << res << "\n";
    std::cout << "ns taken: " << nanoseconds << "\n";
    std::cout << "avg ns: " << nanoseconds / float(N_IT) << "\n";
  }

  //=========== BOILERPLATE END ================
}
