# Find all the script files in the scripts subdirectory
set(RLA_FK_CT_TT_STUDY_SCRIPT_SOURCES
    scripts/eval_ct_tt_study.cpp
)

# Compile each script as a separate executable
foreach(SCRIPT_SOURCE ${RLA_FK_CT_TT_STUDY_SCRIPT_SOURCES})
    # Get the filename without the extension to use as the executable name
    get_filename_component(SCRIPT_NAME ${SCRIPT_SOURCE} NAME_WE)

    add_executable(${SCRIPT_NAME} ${SCRIPT_SOURCE})

    # Link the necessary libraries
    target_link_libraries(${SCRIPT_NAME} PUBLIC
        argparse::argparse
    )

    # Add include directories
    target_include_directories(${SCRIPT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/apps
        ${EIGEN3_INCLUDE_DIR}
        ${BLAZE_INCLUDE_DIR}
    )

    # Add compile options
    target_compile_options(${SCRIPT_NAME} PRIVATE
        -march=native
        -mavx2
        -O3 -g -DNDEBUG
        -ffast-math
        -Wno-maybe-uninitialized
        ${CFLAGS_PEDANTIC}
    )
endforeach()
