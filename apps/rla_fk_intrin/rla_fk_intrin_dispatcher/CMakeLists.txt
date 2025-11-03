# Static library for FK intrinsic implementations
# This library is compiled with -march=native for SIMD support
# and provides a safe ABI boundary for scripts

# Create a static library containing all FK implementations
add_library(rla_fk_intrin_lib STATIC
    fk_impl.cpp
    robot_traits.h
    fk_dispatcher.h
)

# Include directories
target_include_directories(rla_fk_intrin_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/apps
    ${EIGEN3_INCLUDE_DIR}
    ${VAMP_DIR}/src/impl
)

# Compile with -march=native for SIMD optimizations
# This creates the ABI boundary that prevents segfaults when linking with Pinocchio
target_compile_options(rla_fk_intrin_lib PRIVATE
    -march=native
    -mavx2
    -O3
    -g
    -DNDEBUG
    -ffast-math
    -Wno-ignored-attributes
)

# Link dependencies
target_link_libraries(rla_fk_intrin_lib PUBLIC
    Eigen3::Eigen
)
