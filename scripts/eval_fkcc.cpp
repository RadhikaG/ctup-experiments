#include <blaze/Math.h>
#include "cc_simd_blah.h"
#include <iostream>
#include <chrono>

int main(int argc, char ** argv)
{
    const int NBT = 16;
    int it=100000;

    AlignedSVd8Vector q;
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
