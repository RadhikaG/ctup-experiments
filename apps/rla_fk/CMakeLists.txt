# Find all the script files in the scripts subdirectory
set(RLA_FK_SCRIPT_SOURCES
    scripts/ctup_fk_batched.cpp
    scripts/debug_fk_batched.cpp
    scripts/debug_fk.cpp
    scripts/eval_fk_batched.cpp
    scripts/eval_fk.cpp
    scripts/naive_fk_batched.cpp
    scripts/naive_fk.cpp
    scripts/pin_fk_codegen_vectorized_comp.cpp
    scripts/pin_fk_codegen.cpp
    scripts/pin_fk.cpp
)

# Compile each script as a separate executable
foreach(SCRIPT_SOURCE ${RLA_FK_SCRIPT_SOURCES})
    # Get the filename without the extension to use as the executable name
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)

    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})

    # Link the necessary libraries
    target_link_libraries(${SCRIPT_NAME} PUBLIC
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
        ${EIGEN3_INCLUDE_DIR}
        ${BLAZE_INCLUDE_DIR}
        ${CTUP_RUNTIME_INCLUDES}
    )

    # Add compile options
    target_compile_options(${SCRIPT_NAME} PRIVATE
        -O3 -g -DNDEBUG
        -ffast-math
        ${CFLAGS_PEDANTIC}
    )
endforeach()
