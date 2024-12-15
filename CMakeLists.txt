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

find_package(Eigen3 REQUIRED CONFIG)
add_definitions(-DOPENCV_DISABLE_EIGEN_TENSOR_SUPPORT)

# Configure the helper CMakeLists with the dependencies
configure_file(CMakeLists.txt.in ${CMAKE_BINARY_DIR}/deps-build/CMakeLists.txt)

# Build it
execute_process(COMMAND ${CMAKE_COMMAND} .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps-build)

execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps-build)  

link_directories(${CMAKE_BINARY_DIR}/install/pinocchio/lib)
find_package(pinocchio
        PATHS ${CMAKE_BINARY_DIR}/install/pinocchio
        REQUIRED CONFIG
)

find_library(cppad_lib cppad_lib HINTS ${CMAKE_BINARY_DIR}/install/CppAD/lib)
find_library(urdf-compiler urdf-compiler PATHS ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/build)
find_library(buildit buildit PATHS ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/buildit/build)

set(PINOCCHIO_MODEL_DIR ${CMAKE_SOURCE_DIR}/deps/pinocchio/models)
add_compile_definitions(PINOCCHIO_MODEL_DIR="${PINOCCHIO_MODEL_DIR}")



add_compile_definitions(LLVM_VERSION_MAJOR=${LLVM_VERSION_MAJOR}
                            LLVM_VERSION_MINOR=${LLVM_VERSION_MINOR})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${Clang_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
link_directories(${Clang_LIBRARY_DIRS})

################################################
# Compiling code generators
# Code generators are located in samples/ 
################################################

# Default: compile code generators in Debug mode with no optimizations
set(CMAKE_BUILD_TYPE Debug)

#SAMPLES
set(SAMPLES_SOURCES
    samples/sample8.cpp
    samples/sample9.cpp
    samples/sample10.cpp
)


#Compile SAMPLES
foreach(SAMPLE_SOURCE ${SAMPLES_SOURCES})
    get_filename_component(SAMPLE_NAME ${SAMPLE_SOURCE} NAME_WE)
    add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
    target_link_libraries(${SAMPLE_NAME} PUBLIC Eigen3::Eigen)
    target_link_libraries(${SAMPLE_NAME} PUBLIC pinocchio::pinocchio)
    target_link_libraries(${SAMPLE_NAME} PUBLIC ${buildit})
    target_link_libraries(${SAMPLE_NAME} PUBLIC ${urdf-compiler})
    target_include_directories(${SAMPLE_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/install/pinocchio/include
        ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/include
        ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/buildit/include
        ${CMAKE_SOURCE_DIR}/deps/compile-time-urdf-parser/deps/buildit/build/gen_headers
    )
    target_compile_options(${SAMPLE_NAME} PRIVATE
        -Wall
        -Wextra
        -Wno-unused-parameter
        -Wno-missing-field-initializers
        -Wmissing-declarations
        -Woverloaded-virtual
        -Wno-deprecated
        -Wdelete-non-virtual-dtor
        -Werror
        -Wno-vla
        -pedantic-errors
    )
endforeach()

################################################
# Generating code from code generators using robot as input
# Generated code dumped in gen/ directory.
################################################

add_custom_command(
  OUTPUT ${CMAKE_SOURCE_DIR}/gen/fk_gen_dense.h
  COMMAND ${CMAKE_BINARY_DIR}/sample8 ${CMAKE_SOURCE_DIR}/deps/pinocchio/models/baxter_simple.urdf ${CMAKE_SOURCE_DIR}/gen/fk_gen_dense.h
  DEPENDS ${CMAKE_BINARY_DIR}/sample8
  COMMENT "Executing sample8"
  VERBATIM
)

add_custom_target(
  FK_GEN_DENSE ALL
  DEPENDS ${CMAKE_SOURCE_DIR}/gen/fk_gen_dense.h
)

################################################
# Compiling experiment scripts for comparing baselines with generated code.
# Experiment scripts are located in the scripts/ dir.
################################################

# Default: compile evaluation of generated code with optimizations on
set(CMAKE_BUILD_TYPE RelWithDebInfo)

#SCRIPTS
set(SCRIPT_SOURCES
    scripts/eval_fk.cpp
    scripts/gen_fk.cpp
    scripts/pin_fk.cpp
    scripts/pin_fk_codegen.cpp
    scripts/pin_rnea_codegen.cpp
)

#Compile SCRIPTS
foreach(SCRIPT_SOURCE ${SCRIPT_SOURCES})
    # get filename without extension
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)
    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${LLVM_MODULE_LIBS})
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${Clang_LIBS})

    target_link_libraries(${SCRIPT_NAME} PUBLIC pinocchio::pinocchio)
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${cppad_lib})
    target_link_libraries(${SCRIPT_NAME} PUBLIC Eigen3::Eigen)

    target_include_directories(${SCRIPT_NAME} PUBLIC 
        ${CMAKE_BINARY_DIR}/install/CppAD/include
        ${CMAKE_BINARY_DIR}/install/CppADCodeGen/include
        ${CMAKE_CURRENT_SOURCE_DIR}/gen
        ${CMAKE_BINARY_DIR}/install/CppAD/lib
        ${CMAKE_BINARY_DIR}/install/pinocchio/include
     )
endforeach()
