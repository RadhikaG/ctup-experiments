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

set(PINOCCHIO_MODEL_DIR ${CMAKE_SOURCE_DIR}/deps/pinocchio/models)
add_compile_definitions(PINOCCHIO_MODEL_DIR="${PINOCCHIO_MODEL_DIR}")

set(SCRIPT_SOURCES
    scripts/gen_fk.cpp
    scripts/pin_fk.cpp
    scripts/pin_fk_codegen.cpp
    scripts/pin_rnea_codegen.cpp
)

add_compile_definitions(LLVM_VERSION_MAJOR=${LLVM_VERSION_MAJOR}
                            LLVM_VERSION_MINOR=${LLVM_VERSION_MINOR})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${Clang_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
link_directories(${Clang_LIBRARY_DIRS})

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
  
