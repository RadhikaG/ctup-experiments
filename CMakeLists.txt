cmake_minimum_required(VERSION 3.15)
project(ctup-experiments)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally, you can specify the build type (Release, Debug, etc.)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(LLVM ${LLVM_VERSION})
find_package(Clang ${LLVM_VERSION})

# ExternalProject is used to build and manage the dependencies
include(ExternalProject)

# Build CppAD
ExternalProject_Add(CppAD
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/CppAD
    BINARY_DIR ${CMAKE_BINARY_DIR}/CppAD
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install/CppAD -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    INSTALL_DIR ${CMAKE_BINARY_DIR}/install/CppAD
)

include_directories(${CMAKE_BINARY_DIR}/install/CppAD/include)
link_directories(${CMAKE_BINARY_DIR}/install/CppAD/lib)

# Build CppADCodeGen, depends on CppAD
ExternalProject_Add(CppADCodeGen
    DEPENDS CppAD
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/CppADCodeGen
    BINARY_DIR ${CMAKE_BINARY_DIR}/CppADCodeGen
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install/CppADCodeGen -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    INSTALL_DIR ${CMAKE_BINARY_DIR}/install/CppADCodeGen
)

include_directories(${CMAKE_BINARY_DIR}/install/CppADCodeGen/include)

# Build hpp-fcl
ExternalProject_Add(hpp-fcl
    DEPENDS CppAD
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/hpp-fcl
    BINARY_DIR ${CMAKE_BINARY_DIR}/hpp-fcl
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install/hpp-fcl -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DBUILD_PYTHON_INTERFACE=OFF
    INSTALL_DIR ${CMAKE_BINARY_DIR}/install/hpp-fcl
)

include_directories(${CMAKE_BINARY_DIR}/install/hpp-fcl/include)
link_directories(${CMAKE_BINARY_DIR}/install/hpp-fcl/lib)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}
    ${CMAKE_BINARY_DIR}/install/CppAD
    ${CMAKE_BINARY_DIR}/install/CppADCodeGen
    ${CMAKE_BINARY_DIR}/install/hpp-fcl
)
# this is a bad hack for passing multiple non-standard install dirs to ExternalProject_Add
# https://stackoverflow.com/questions/45414507/pass-a-list-of-prefix-paths-to-externalproject-add-in-cmake-args
string(REPLACE ";" "|" CMAKE_PREFIX_PATH_ALT_SEP "${CMAKE_PREFIX_PATH}")

# Build pinocchio, depends on CppAD, CppADCodeGen
ExternalProject_Add(pinocchio
    DEPENDS CppAD CppADCodeGen hpp-fcl
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/deps/pinocchio
    BINARY_DIR ${CMAKE_BINARY_DIR}/pinocchio
    # bad hack continued
    LIST_SEPARATOR |
    # no python interface, support HPP FCL and codegen
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install/pinocchio -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH_ALT_SEP} -DBUILD_PYTHON_INTERFACE=OFF -DBUILD_WITH_COLLISION_SUPPORT=ON -DBUILD_WITH_CODEGEN_SUPPORT=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    INSTALL_DIR ${CMAKE_BINARY_DIR}/install/pinocchio
)

include_directories(${CMAKE_BINARY_DIR}/install/pinocchio/include)
link_directories(${CMAKE_BINARY_DIR}/install/pinocchio/lib)

find_package(pinocchio
    PATHS ${CMAKE_BINARY_DIR}/install/pinocchio
    NO_DEFAULT_PATH
)

set(PINOCCHIO_MODEL_DIR ${CMAKE_SOURCE_DIR}/deps/pinocchio/models)
add_compile_definitions(PINOCCHIO_MODEL_DIR="${PINOCCHIO_MODEL_DIR}")

# for CppADCodeGen JIT
if (LLVM_FOUND)
    add_compile_definitions(LLVM_VERSION_MAJOR=${LLVM_VERSION_MAJOR}
                            LLVM_VERSION_MINOR=${LLVM_VERSION_MINOR})
    include_directories(${LLVM_INCLUDE_DIRS})
    include_directories(${Clang_INCLUDE_DIRS})
    link_directories(${LLVM_LIBRARY_DIRS})
    link_directories(${Clang_LIBRARY_DIRS})
endif()

include_directories(${CMAKE_SOURCE_DIR}/gen)

# for individual script executables

set(SCRIPT_SOURCES
    scripts/gen_fk.cpp
    scripts/pin_fk.cpp
    scripts/pin_fk_codegen.cpp
    scripts/pin_rnea_codegen.cpp
)

foreach(SCRIPT_SOURCE ${SCRIPT_SOURCES})
    # get filename without extension
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)
    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})
    target_link_libraries(${SCRIPT_NAME} PUBLIC pinocchio::pinocchio)
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${LLVM_MODULE_LIBS})
    target_link_libraries(${SCRIPT_NAME} PUBLIC ${Clang_LIBS})
endforeach()
