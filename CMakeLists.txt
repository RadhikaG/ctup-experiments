cmake_minimum_required(VERSION 3.15)
project(ctup-experiments)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

################################################
# Compiling dependencies from source
# These are pulled into the deps/ directory
################################################

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(LLVM ${LLVM_VERSION} REQUIRED)
find_package(Clang ${LLVM_VERSION} REQUIRED)

set(EIGEN3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/eigen")
find_package(Eigen3 3.3 REQUIRED HINTS ${EIGEN3_INCLUDE_DIR})
add_definitions(-DOPENCV_DISABLE_EIGEN_TENSOR_SUPPORT)
set(BLAZE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/blaze")

# Configure the helper CMakeLists with the dependencies
configure_file(CMakeLists.txt.in ${CMAKE_BINARY_DIR}/deps-build/CMakeLists.txt)

# Build it
execute_process(COMMAND ${CMAKE_COMMAND} .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps-build)

execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps-build)  

find_package(pinocchio REQUIRED)

set(PINOCCHIO_MODEL_DIR ${CMAKE_SOURCE_DIR}/deps/pinocchio/models)
add_compile_definitions(PINOCCHIO_MODEL_DIR="${PINOCCHIO_MODEL_DIR}")

find_package(coal REQUIRED)
find_package(cppad QUIET)
if(NOT cppad_FOUND)
  pkg_check_modules(cppad REQUIRED cppad)
endif()
find_library(urdf-compiler urdf-compiler PATHS ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/build)
find_library(buildit buildit PATHS ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/buildit/build)

find_package(yaml-cpp REQUIRED)
find_package(argparse REQUIRED)

add_compile_definitions(LLVM_VERSION_MAJOR=${LLVM_VERSION_MAJOR}
                            LLVM_VERSION_MINOR=${LLVM_VERSION_MINOR})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${Clang_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
link_directories(${Clang_LIBRARY_DIRS})

set(CFLAGS_PEDANTIC
    -Wall
    -Wextra
    -Wno-unused-variable
    -Wno-unused-parameter
    -Wno-unused-but-set-variable
    -Wno-unused-function
    -Wno-missing-field-initializers
    -Wmissing-declarations
    -Woverloaded-virtual
    -Wno-deprecated
    -Wdelete-non-virtual-dtor
    -Werror
    -Wno-template-id-cdtor
    -Wno-vla
    -pedantic-errors
)


################################################
# Compiling code generators
# Code generators are located in samples/ 
################################################

#SAMPLES
set(SAMPLES_SOURCES
    samples/eigenmatrix_fk.cpp
    samples/scalar_rla_fk.cpp
    samples/scalar_rla_rnea.cpp
    samples/batched_rla_fk.cpp
    samples/batched_fk_intrin.cpp
    samples/batched_fkcc_early_exit.cpp
    samples/franken_batched_fkcc_early_exit.cpp
    samples/scalar_spatial_jacobian.cpp
    samples/batched_grad_self_collision.cpp
    samples/batched_spatial_jacobian.cpp
    samples/rla_fk_batch_size_sweep.cpp
    samples/batched_self_collision_sd.cpp
    samples/batched_rla_fk_ct_tt_study.cpp
)


#Compile SAMPLES
foreach(SAMPLE_SOURCE ${SAMPLES_SOURCES})
    get_filename_component(SAMPLE_NAME ${SAMPLE_SOURCE} NAME_WE)
    add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
    target_link_libraries(${SAMPLE_NAME} PUBLIC Eigen3::Eigen)
    target_link_libraries(${SAMPLE_NAME} PUBLIC pinocchio::pinocchio)
    target_link_libraries(${SAMPLE_NAME} PUBLIC coal::coal)
    target_link_libraries(${SAMPLE_NAME} PUBLIC ${buildit})
    target_link_libraries(${SAMPLE_NAME} PUBLIC ${urdf-compiler})
    target_link_libraries(${SAMPLE_NAME} PUBLIC ${YAML_CPP_LIBRARIES})
    target_include_directories(${SAMPLE_NAME} PUBLIC
        ${YAML_CPP_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/include
        ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/buildit/include
        ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/buildit/build/gen_headers
    )
    target_compile_options(${SAMPLE_NAME} PRIVATE 
        -O2 -g # Debug
        ${CFLAGS_PEDANTIC}
    )
endforeach()

################################################
# Generating code from code generators using robot as input
# Generated code dumped in gen/ directory.
################################################

#add_custom_command(
#  OUTPUT ${CMAKE_SOURCE_DIR}/gen/fk_gen_dense.h
#  COMMAND ${CMAKE_BINARY_DIR}/sample8 ${CMAKE_SOURCE_DIR}/deps/pinocchio/models/baxter_simple.urdf ${CMAKE_SOURCE_DIR}/gen/fk_gen_dense.h
#  DEPENDS ${CMAKE_BINARY_DIR}/sample8
#  COMMENT "Executing sample8"
#  VERBATIM
#)
#
#add_custom_target(
#  FK_GEN_DENSE ALL
#  DEPENDS ${CMAKE_SOURCE_DIR}/gen/fk_gen_dense.h
#)
#
#add_custom_command(
#  OUTPUT ${CMAKE_SOURCE_DIR}/gen/cc_simd_ur5_2.h
#  COMMAND ${CMAKE_BINARY_DIR}/sample17 ${CMAKE_SOURCE_DIR}/models/ur5_spherized_1.urdf ${CMAKE_SOURCE_DIR}/models/ur5_spherized.urdf  ${CMAKE_SOURCE_DIR}/environment/scene001.yaml ${CMAKE_SOURCE_DIR}/models/ur5.srdf  ${CMAKE_SOURCE_DIR}/gen/cc_simd_ur5_2.h
#  DEPENDS ${CMAKE_BINARY_DIR}/sample17
#  COMMENT "Executing sample17"
#  VERBATIM
#)
#
#add_custom_target(
#  CC_SIMD ALL
#  DEPENDS ${CMAKE_SOURCE_DIR}/gen/cc_simd_ur5_2.h
#)

################################################
# Compiling experiment scripts for comparing baselines with generated code.
# Experiment scripts are located in the scripts/ dir.
################################################

list(APPEND CTUP_RUNTIME_INCLUDES
    ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/runtime
)

# Try to find VAMP automatically
if(NOT DEFINED VAMP_DIR)
    # Check common locations
    set(VAMP_SEARCH_PATHS
        "${CMAKE_SOURCE_DIR}/../vamp"
        "${CMAKE_SOURCE_DIR}/../../vamp"
        "$ENV{HOME}/vamp"
    )

    foreach(SEARCH_PATH ${VAMP_SEARCH_PATHS})
        if(EXISTS "${SEARCH_PATH}/src/impl")
            set(VAMP_DIR "${SEARCH_PATH}")
            message(STATUS "Found VAMP at: ${VAMP_DIR}")
            break()
        endif()
    endforeach()
endif()

option(BUILD_APPS "Build the apps/ subdirectories" ON)

if(BUILD_APPS)
    add_subdirectory(apps/rla_fk)
    add_subdirectory(apps/rla_fk_batch_size_sweep)
    add_subdirectory(apps/rla_fk_ct_tt_study)
    add_subdirectory(apps/rla_rnea)
    add_subdirectory(apps/rla_spatial_jacobian)

    # Only build rla_fkcc_early_exit and rla_fk_intrin if VAMP is available
    if(DEFINED VAMP_DIR AND EXISTS "${VAMP_DIR}/src/impl")
        add_subdirectory(apps/rla_fkcc_early_exit)
        add_subdirectory(apps/rla_fk_intrin)
    else()
        message(WARNING "VAMP not found. Skipping apps/rla_fkcc_early_exit and apps/rla_fk_intrin. Set VAMP_DIR to enable.")
    endif()

    add_subdirectory(apps/rla_grad_self_collision)
endif()

#set(BATCHED_SCRIPT_SOURCES
#  scripts/ctup_fk_batched.cpp
#)
#foreach(SCRIPT_SOURCE ${BATCHED_SCRIPT_SOURCES})
#    # get filename without extension
#    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)
#    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})
#    target_link_libraries(${SCRIPT_NAME} PUBLIC Eigen3::Eigen)
#    target_include_directories(${SCRIPT_NAME} PUBLIC 
#        ${CMAKE_CURRENT_SOURCE_DIR}/gen
#        ${EIGEN3_INCLUDE_DIR}
#        ${BLAZE_INCLUDE_DIR}
#    )
#    target_compile_options(${SCRIPT_NAME} PRIVATE 
#        -O3 -DNDEBUG
#        -ffast-math
#        -march=skylake-avx512
#        ${CFLAGS_PEDANTIC}
#    )
#endforeach()
