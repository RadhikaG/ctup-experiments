# Static library for spatial Jacobian implementations
# This library is compiled with -march=native for SIMD support (batched Jacobian)
# and provides a safe ABI boundary for scripts using Pinocchio

# Create a static library containing all spatial Jacobian implementations
add_library(rla_spatial_jac_lib STATIC
    jac_impl.cpp
    robot_traits.h
    jac_dispatcher.h
)

# Include directories
target_include_directories(rla_spatial_jac_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/apps
    ${EIGEN3_INCLUDE_DIR}
    ${BLAZE_INCLUDE_DIR}
    ${CTUP_RUNTIME_INCLUDES}
)

# Compile with -march=native for SIMD optimizations (needed for batched Jacobian)
# This creates the ABI boundary that prevents segfaults when linking with Pinocchio
target_compile_options(rla_spatial_jac_lib PRIVATE
    -march=native
    -O3
    -g
    -DNDEBUG
    -ffast-math
)

# Link dependencies
target_link_libraries(rla_spatial_jac_lib PUBLIC
    Eigen3::Eigen
)
