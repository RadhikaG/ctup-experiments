# Static library for Pinocchio-compatible FKCC implementations
# This library is compiled with optimized flags and provides an ABI boundary
# for scripts using both VAMP and Pinocchio

# Create a static library
add_library(pin_fkcc STATIC
    pin_collision.cpp
    pin_collision.h
    pin_shapes.h
)

# Include directories
target_include_directories(pin_fkcc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/apps
    ${EIGEN3_INCLUDE_DIR}
    ${BLAZE_INCLUDE_DIR}
    ${VAMP_DIR}/src/impl
)

# Find pdqsort from VAMP build (needed by VAMP collision headers)
if(EXISTS "${VAMP_DIR}/build/_deps/pdqsort-src")
    target_include_directories(pin_fkcc PUBLIC
        ${VAMP_DIR}/build/_deps/pdqsort-src
    )
endif()

# Compile with optimization flags
target_compile_options(pin_fkcc PRIVATE
    -O3
    -g
    -DNDEBUG
    -ffast-math
)

# Pass models directory as compile definition
target_compile_definitions(pin_fkcc PRIVATE
    CTUP_MODELS_DIR="${CMAKE_SOURCE_DIR}/models"
)

# Link dependencies
target_link_libraries(pin_fkcc PUBLIC
    pinocchio::pinocchio
    coal::coal
    Eigen3::Eigen
)
