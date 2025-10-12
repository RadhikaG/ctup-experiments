# Static library for FK implementations
# This library is compiled with -march=native for SIMD support (batched FK)
# and provides a safe ABI boundary for scripts using Pinocchio

# Create a static library containing all FK implementations
add_library(rla_fk_lib STATIC
    fk_impl.cpp
    robot_traits.h
    fk_dispatcher.h
)

# Include directories
target_include_directories(rla_fk_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/apps
    ${EIGEN3_INCLUDE_DIR}
    ${BLAZE_INCLUDE_DIR}
)

# Compile with -march=native for SIMD optimizations (needed for batched FK)
# This creates the ABI boundary that prevents segfaults when linking with Pinocchio
target_compile_options(rla_fk_lib PRIVATE
    -march=native
    -O3
    -g
    -DNDEBUG
    -ffast-math
)

# Link dependencies
target_link_libraries(rla_fk_lib PUBLIC
    Eigen3::Eigen
)
