cmake_minimum_required(VERSION 3.14)
project(pin_fkcc_static LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build flags: safe for linking into AVX2 downstream
add_compile_options(-O2)
add_compile_options(-g)

# Dependencies

set(CTUP_ROOT "${CMAKE_SOURCE_DIR}/../../../../")
set(CTUP_BUILD_ROOT "${CMAKE_SOURCE_DIR}/../../../../build")

#### Eigen
set(EIGEN3_INCLUDE_DIR "${CTUP_ROOT}/deps/compile-time-urdf-parser/deps/eigen")
find_package(Eigen3 3.3 REQUIRED HINTS ${EIGEN3_INCLUDE_DIR})

#### Pinocchio
find_package(pinocchio
    PATHS ${CTUP_BUILD_ROOT}/install/pinocchio/lib
    REQUIRED CONFIG
)

#### hpp-fcl
find_library(hpp-fcl hpp-fcl 
    HINTS ${CTUP_BUILD_ROOT}/install/hpp-fcl/lib)

#### VAMP (to get environment)
set(VAMP_INCLUDE_DIR "${CTUP_ROOT}/../vamp/src/impl")

#### Blaze (VAMP collision headers complain otherwise)
set(BLAZE_INCLUDE_DIR "${CTUP_ROOT}/deps/compile-time-urdf-parser/deps/blaze")

#### pdqsort (VAMP collision headers complain otherwise)
set(PDQDORT_INCLUDE_DIR "${CTUP_ROOT}/../vamp/build/_deps/pdqsort-src")

# Add static library
add_library(pin_fkcc STATIC
    pin_collision.cpp
)

# Link dependencies
target_link_libraries(pin_fkcc
  PUBLIC
    pinocchio::pinocchio
    ${hpp-fcl}
    Eigen3::Eigen
)

# Include directories for consumers
target_include_directories(pin_fkcc
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${VAMP_INCLUDE_DIR}
    ${BLAZE_INCLUDE_DIR}
    ${PDQDORT_INCLUDE_DIR}
)
