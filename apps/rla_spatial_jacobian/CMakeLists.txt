# Add the spatial Jacobian dispatcher static library subdirectory
add_subdirectory(rla_spatial_jac_dispatcher)

# Find all the script files in the scripts subdirectory
set(RLA_SPATIAL_JACOBIAN_SCRIPT_SOURCES
    scripts/debug_jac.cpp
    scripts/debug_batched_jac.cpp
    scripts/scratch_jac.cpp
    scripts/eval_jac.cpp
    scripts/eval_batched_jac.cpp
)

# Compile each script as a separate executable
foreach(SCRIPT_SOURCE ${RLA_SPATIAL_JACOBIAN_SCRIPT_SOURCES})
    # Get the filename without the extension to use as the executable name
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)

    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})

    # Link the necessary libraries
    target_link_libraries(${SCRIPT_NAME} PUBLIC
        rla_spatial_jac_lib
        pinocchio::pinocchio
        argparse::argparse
        ${cppad_LIBRARIES}
        ${LLVM_MODULE_LIBS}
        ${Clang_LIBS}
    )

    # Add include directories
    # These variables are inherited from the parent scope (the root CMakeLists.txt)
    target_include_directories(${SCRIPT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/apps
        ${CMAKE_BINARY_DIR}/install/CppADCodeGen/include
        ${BLAZE_INCLUDE_DIR}
        ${EIGEN3_INCLUDE_DIR}
        ${CTUP_RUNTIME_INCLUDES}
    )

    # Add compile options
    target_compile_options(${SCRIPT_NAME} PRIVATE
        -O3 -g -DNDEBUG
        -ffast-math
        ${CFLAGS_PEDANTIC}
    )
endforeach()
