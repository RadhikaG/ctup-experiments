# Add the FK intrin dispatcher static library subdirectory
add_subdirectory(rla_fk_intrin_dispatcher)

# Find all the script files in the scripts subdirectory
set(RLA_FK_INTRIN_SCRIPT_SOURCES
    scripts/debug_fk_intrin.cpp
)

# Compile each script as a separate executable
foreach(SCRIPT_SOURCE ${RLA_FK_INTRIN_SCRIPT_SOURCES})
    # Get the filename without the extension to use as the executable name
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)

    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})

    # Link the necessary libraries
    target_link_libraries(${SCRIPT_NAME} PUBLIC
        rla_fk_intrin_lib
        pinocchio::pinocchio
        argparse::argparse
        ${cppad_LIBRARIES}
        ${LLVM_MODULE_LIBS}
        ${Clang_LIBS}
    )

    # Add include directories
    target_include_directories(${SCRIPT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/apps
        ${CMAKE_BINARY_DIR}/install/CppADCodeGen/include
        ${EIGEN3_INCLUDE_DIR}
        ${CTUP_RUNTIME_INCLUDES}
        ${VAMP_DIR}/src/impl
    )

    # Add compile options (no -march=native or -mavx2 to avoid Pinocchio crashes)
    target_compile_options(${SCRIPT_NAME} PRIVATE
        -O3 -g -DNDEBUG
        -ffast-math
        -Wno-maybe-uninitialized
        ${CFLAGS_PEDANTIC}
    )
endforeach()
