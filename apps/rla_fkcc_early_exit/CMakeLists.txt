# Add the pin_compat static library subdirectory
add_subdirectory(pin_compat)

# Find all the script files in the scripts subdirectory
set(RLA_FKCC_SCRIPT_SOURCES
    scripts/debug_fkcc.cpp
    scripts/eval_fkcc_comp.cc
    scripts/eval_rrtc_comp.cc
    #scripts/eval_fkcc.cpp
)

# Compile each script as a separate executable
foreach(SCRIPT_SOURCE ${RLA_FKCC_SCRIPT_SOURCES})
    # Get the filename without the extension to use as the executable name
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)

    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})

    # Link the necessary libraries
    target_link_libraries(${SCRIPT_NAME} PUBLIC
        pin_fkcc
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
        ${VAMP_DIR}/src/impl
    )

    # Scripts using VAMP planning need nigh (nearest neighbor library)
    if(${SCRIPT_NAME} IN_LIST VAMP_SCRIPTS)
        if(EXISTS "${VAMP_DIR}/build/_deps/nigh-src")
            target_include_directories(${SCRIPT_NAME} PUBLIC
                ${VAMP_DIR}/build/_deps/nigh-src/src
            )
        endif()
        # Enable Pinocchio backend support for VAMP planning scripts
        target_compile_definitions(${SCRIPT_NAME} PRIVATE CTUP_EXP_BUILD_VAMP_PIN_COMP=1)
    endif()

    # Add compile options
    target_compile_options(${SCRIPT_NAME} PRIVATE
        -O3 -g -DNDEBUG
        -ffast-math
    )

    # Scripts using VAMP need AVX2 support and should skip pedantic warnings
    set(VAMP_SCRIPTS eval_fkcc_comp eval_rrtc_comp)
    if(${SCRIPT_NAME} IN_LIST VAMP_SCRIPTS)
        target_compile_options(${SCRIPT_NAME} PRIVATE -march=native -mavx2)
    else()
        target_compile_options(${SCRIPT_NAME} PRIVATE ${CFLAGS_PEDANTIC})
    endif()
endforeach()
