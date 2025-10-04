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
    samples/sample8.cpp
    samples/sample9.cpp
    samples/sample10.cpp
    samples/sample11.cpp
    samples/sample12.cpp
    samples/sample13.cpp
    samples/sample14.cpp
    samples/sample15.cpp
    samples/sample16.cpp
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
    ${CMAKE_SOURCE_DIR}/apps
    ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/runtime
)

#SCRIPTS
set(SCRIPT_SOURCES
    scripts/eval_fk.cpp
    scripts/debug_fk.cpp
    scripts/debug_fkcc.cpp
    scripts/debug_eef_jac.cpp
    scripts/debug_sd_grad.cpp
    scripts/debug_jacobian.cpp
    scripts/eval_fkcc.cpp
    scripts/debug_rnea.cpp
    scripts/eval_rnea.cpp
    scripts/pin_fk.cpp
    scripts/pin_fk_codegen.cpp
    scripts/pin_eef_jac_codegen.cpp
    scripts/pin_fk_codegen_vectorized_comp.cpp
    scripts/pin_rnea_codegen.cpp
    scripts/eval_fk_batched.cpp
    scripts/debug_fk_batched.cpp
    scripts/naive_fk_batched.cpp
    scripts/naive_fk.cpp
)

#Compile SCRIPTS
foreach(SCRIPT_SOURCE ${SCRIPT_SOURCES})
    # get filename without extension
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)
    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${LLVM_MODULE_LIBS})
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${Clang_LIBS})

    target_link_libraries(${SCRIPT_NAME} PUBLIC pinocchio::pinocchio)
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${cppad_LIBRARIES})
    target_link_libraries(${SCRIPT_NAME} PUBLIC coal::coal)
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${YAML_CPP_LIBRARIES})

    target_include_directories(${SCRIPT_NAME} PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/gen
        ${CMAKE_BINARY_DIR}/install/CppADCodeGen/include
        ${YAML_CPP_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
        ${BLAZE_INCLUDE_DIR}
        ${CTUP_RUNTIME_INCLUDES}
    )
    target_compile_options(${SCRIPT_NAME} PRIVATE 
        -O3 -g -DNDEBUG
        -ffast-math
        ${CFLAGS_PEDANTIC}
    )
endforeach()

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
