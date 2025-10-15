#include <vector>
#include <array>
#include <iostream>
#include <iomanip>

#include <vamp/collision/factory.hh>
#include <vamp/planning/validate.hh>
#include <vamp/planning/rrtc.hh>
#include <vamp/planning/simplify.hh>
#include <vamp/robots/panda.hh>
#include <vamp/random/halton.hh>
#include <vamp/utils.hh>

#include "ctup/typedefs.h"
#include "rla_fkcc_early_exit/pin_compat/pin_collision.h"
#include <argparse/argparse.hpp>

using Robot = vamp::robots::Panda;
static constexpr const std::size_t rake = vamp::FloatVectorWidth;
using EnvironmentInput = vamp::collision::Environment<float>;
using EnvironmentVector = vamp::collision::Environment<vamp::FloatVector<rake>>;
using EnvironmentVectorCTUP = vamp::collision::Environment<ctup_runtime::avx256f>;
using RRTC = vamp::planning::RRTC<Robot, rake, Robot::resolution>;

// Start and goal configurations
static constexpr Robot::ConfigurationArray start = {0., -0.785, 0., -2.356, 0., 1.571, 0.785};
static constexpr Robot::ConfigurationArray goal = {2.35, 1., 0., -0.8, 0, 2.5, 0.785};

// Spheres for the cage problem - (x, y, z) center coordinates with fixed, common radius defined below
static const std::vector<std::array<float, 3>> problem = {
    {0.55, 0, 0.25},
    {0.35, 0.35, 0.25},
    {0, 0.55, 0.25},
    {-0.55, 0, 0.25},
    {-0.35, -0.35, 0.25},
    {0, -0.55, 0.25},
    {0.35, -0.35, 0.25},
    {0.35, 0.35, 0.8},
    {0, 0.55, 0.8},
    {-0.35, 0.35, 0.8},
    {-0.55, 0, 0.8},
    {-0.35, -0.35, 0.8},
    {0, -0.55, 0.8},
    {0.35, -0.35, 0.8},
};

// Radius for obstacle spheres
static constexpr float radius = 0.2;

auto main(int argc, char **argv) -> int
{
    argparse::ArgumentParser program("eval_rrtc_comp");

    program.add_argument("--ctup")
        .help("run CTUP RRTConnect benchmark")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("--vamp")
        .help("run VAMP RRTConnect benchmark")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("--pin")
        .help("run Pinocchio RRTConnect benchmark")
        .default_value(false)
        .implicit_value(true);

    program.add_argument("--n_it")
        .help("number of planning iterations")
        .default_value(100)
        .scan<'i', int>();

    program.add_argument("--simplify")
        .help("simplify the path after planning")
        .default_value(false)
        .implicit_value(true);

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    bool run_ctup = program.get<bool>("--ctup");
    bool run_vamp = program.get<bool>("--vamp");
    bool run_pin = program.get<bool>("--pin");
    size_t N_IT = program.get<int>("--n_it");
    bool do_simplify = program.get<bool>("--simplify");

    // Build sphere cage environment
    EnvironmentInput environment;
    for (const auto &sphere : problem)
    {
        environment.spheres.emplace_back(vamp::collision::factory::sphere::array(sphere, radius));
    }

    environment.sort();
    auto env_v = EnvironmentVector(environment);
    auto env_v_ctup = EnvironmentVectorCTUP(environment);

    // Create RNG for planning
    auto rng = std::make_shared<vamp::rng::Halton<Robot::dimension>>();

    // Setup RRTC settings
    vamp::planning::RRTCSettings rrtc_settings;
    rrtc_settings.range = 1.0;

    vamp::planning::PlanningResult<Robot::dimension> result;

    //========= CTUP =================
    if (run_ctup)
    {
        std::cout << "Running CTUP RRTConnect benchmark...\n";

        auto start_time = std::chrono::steady_clock::now();
        for (size_t i = 0; i < N_IT; i++) {
            rng->reset();  // Reset RNG for fair comparison
            result = RRTC::solve(Robot::Configuration(start),
                                Robot::Configuration(goal),
                                env_v_ctup,
                                rrtc_settings,
                                rng);
        }
        auto nanoseconds = vamp::utils::get_elapsed_nanoseconds(start_time);

        // If successful
        if (result.path.size() > 0)
        {
            if (do_simplify)
            {
                // Simplify path with default settings
                vamp::planning::SimplifySettings simplify_settings;
                auto simplify_result = vamp::planning::simplify<Robot, rake, Robot::resolution>(
                    result.path, env_v_ctup, simplify_settings, rng);

                std::cout << "Simplified path from " << result.path.size()
                         << " to " << simplify_result.path.size() << " waypoints\n";

                // Output configurations of simplified path
                std::cout << std::fixed << std::setprecision(3);
                std::cout << "Simplified path configurations:\n";
                for (const auto &config : simplify_result.path)
                {
                    const auto &array = config.to_array();
                    for (auto i = 0U; i < Robot::dimension; ++i)
                    {
                        std::cout << array[i] << ", ";
                    }
                    std::cout << std::endl;
                }
            }
        }
        else
        {
            std::cout << "CTUP: No path found!\n";
        }

        std::cout << "\nCTUP Results:\n";
        std::cout << "  Path size: " << result.path.size() << " waypoints\n";
        std::cout << "  Total time: " << nanoseconds / 1e6 << " ms\n";
        std::cout << "  Avg time per iteration: " << nanoseconds / float(N_IT) / 1e6 << " ms\n";
        std::cout << "=================================================\n";
    }

    //========= VAMP =================
    if (run_vamp)
    {
        std::cout << "Running VAMP RRTConnect benchmark...\n";

        auto start_time = std::chrono::steady_clock::now();
        for (size_t i = 0; i < N_IT; i++) {
            rng->reset();  // Reset RNG for fair comparison
            result = RRTC::solve(Robot::Configuration(start),
                                Robot::Configuration(goal),
                                env_v,
                                rrtc_settings,
                                rng);
        }
        auto nanoseconds = vamp::utils::get_elapsed_nanoseconds(start_time);

        // If successful
        if (result.path.size() > 0)
        {
            if (do_simplify)
            {
                // Simplify path with default settings
                vamp::planning::SimplifySettings simplify_settings;
                auto simplify_result = vamp::planning::simplify<Robot, rake, Robot::resolution>(
                    result.path, env_v, simplify_settings, rng);

                std::cout << "Simplified path from " << result.path.size()
                         << " to " << simplify_result.path.size() << " waypoints\n";

                // Output configurations of simplified path
                std::cout << std::fixed << std::setprecision(3);
                std::cout << "Simplified path configurations:\n";
                for (const auto &config : simplify_result.path)
                {
                    const auto &array = config.to_array();
                    for (auto i = 0U; i < Robot::dimension; ++i)
                    {
                        std::cout << array[i] << ", ";
                    }
                    std::cout << std::endl;
                }
            }
        }
        else
        {
            std::cout << "VAMP: No path found!\n";
        }

        std::cout << "\nVAMP Results:\n";
        std::cout << "  Path size: " << result.path.size() << " waypoints\n";
        std::cout << "  Total time: " << nanoseconds / 1e6 << " ms\n";
        std::cout << "  Avg time per iteration: " << nanoseconds / float(N_IT) / 1e6 << " ms\n";
        std::cout << "=================================================\n";
    }

    //========= PINOCCHIO =================
    if (run_pin)
    {
        std::cout << "Running Pinocchio RRTConnect benchmark...\n";

        auto start_time = std::chrono::steady_clock::now();
        for (size_t i = 0; i < N_IT; i++) {
            rng->reset();  // Reset RNG for fair comparison
            result = RRTC::solve(Robot::Configuration(start),
                                Robot::Configuration(goal),
                                environment,  // Scalar environment for Pinocchio
                                rrtc_settings,
                                rng);
        }
        auto nanoseconds = vamp::utils::get_elapsed_nanoseconds(start_time);

        // If successful
        if (result.path.size() > 0)
        {
            if (do_simplify)
            {
                // Simplify path - use VAMP backend for simplification
                vamp::planning::SimplifySettings simplify_settings;
                auto simplify_result = vamp::planning::simplify<Robot, rake, Robot::resolution>(
                    result.path, env_v, simplify_settings, rng);

                std::cout << "Simplified path from " << result.path.size()
                         << " to " << simplify_result.path.size() << " waypoints\n";

                // Output configurations of simplified path
                std::cout << std::fixed << std::setprecision(3);
                std::cout << "Simplified path configurations:\n";
                for (const auto &config : simplify_result.path)
                {
                    const auto &array = config.to_array();
                    for (auto i = 0U; i < Robot::dimension; ++i)
                    {
                        std::cout << array[i] << ", ";
                    }
                    std::cout << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Pinocchio: No path found!\n";
        }

        std::cout << "\nPinocchio Results:\n";
        std::cout << "  Path size: " << result.path.size() << " waypoints\n";
        std::cout << "  Total time: " << nanoseconds / 1e6 << " ms\n";
        std::cout << "  Avg time per iteration: " << nanoseconds / float(N_IT) / 1e6 << " ms\n";
        std::cout << "=================================================\n";
    }

    return 0;
}
