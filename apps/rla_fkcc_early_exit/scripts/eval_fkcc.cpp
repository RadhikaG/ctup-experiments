// export CXX=/home/ubuntu/build/gcc-15.1-build/gcc-15.1.0-install/bin/g++
// $CXX -std=c++17 -O3 -ffast-math -gno-as-locview-support -I../gen -I../deps/compile-time-urdf-parser/deps/eigen -I../deps/compile-time-urdf-parser/deps/blaze ../scripts/eval_fkcc.cpp -o eval_fkcc
// export LD_LIBRARY_PATH=/home/ubuntu/build/gcc-15.1-build/gcc-15.1.0-install/lib64/
#include <blaze/Math.h>
#include "rla_fkcc_early_exit/gen/fkcc_ur5.h"
#include "rla_fkcc_early_exit/runtime/typedefs.h"
#include <iostream>
#include <chrono>
#include <argparse/argparse.hpp>

int main(int argc, char ** argv)
{
    argparse::ArgumentParser program("eval_fkcc");

    program.add_argument("urdf")
        .help("path to the URDF file");

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    const int NBT = 16;
    int it=100000;

    ctup_runtime::ConfigurationBlockRobot<ctup_runtime::robots::UR5> q;
    q.resize(6);

    q[0] = -0.3369;
    q[1] = 1.2966;
    q[2] = -0.6775;
    q[3] = -0.6775;
    q[4] = -1.4218;
    q[5] = -0.7067;

    auto start = std::chrono::steady_clock::now();
    int res;
    for(int i=0;i<it;++i){
        res=ctup_gen::fkcc(q);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "SIMD BLAZE FK+CC (ns): \t\t\t\t" << elapsed.count()/(it)<<std::endl;

    if(res){
        std::cout << "COLLISION FOUND"<<std::endl;
    }
    else{
         std::cout << "VALID CONFIGURATIONS"<<std::endl;
    }

}
