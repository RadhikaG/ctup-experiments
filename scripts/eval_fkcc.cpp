#include <blaze/Math.h>
#include "fk_cc.h"
#include <iostream>
#include <chrono>

int main(int argc, char ** argv)
{
    const int NBT = 16;
    int it=100000;

    blaze::StaticVector<blaze::StaticVector<double, 16>, 14> qs;
    for (size_t i = 0; i < NBT; ++i){
        for (size_t j = 0; j < 14; ++j){
            qs[i][j]=i+0.1*j+i*j*0.01;
        }
    }

    auto start = std::chrono::steady_clock::now();
    int res;
    for(int i=0;i<it;++i){
        res=ctup_gen::fk(qs);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "SIMD BLAZE FK+CC (ns): \t\t\t\t" << elapsed.count()/(it)<<std::endl;

    if(res){
        std::cout << "COLLIISON FOUND"<<std::endl;
    }
    else{
         std::cout << "VALID CONFIGURATIONS"<<std::endl;
    }

}