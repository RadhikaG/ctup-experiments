#!/bin/bash

# Script to generate spatial Jacobian headers for multiple robots

# Get the directory where this script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RLA experiments root is one level up from helper_scripts
RLA_EXP_ROOT="$(dirname "$SCRIPT_DIR")"

# Create output directories if they don't exist
mkdir -p "$RLA_EXP_ROOT/apps/rla_spatial_jacobian/gen/scalar"
mkdir -p "$RLA_EXP_ROOT/apps/rla_spatial_jacobian/gen/batched"

# Robot names
ROBOT_NAMES=("panda" "iiwa" "hyq" "baxter")

# Corresponding URDF paths
URDF_PATHS=(
    "models/panda/panda.urdf"
    "models/iiwa/iiwa_rbd_accel.urdf"
    "models/hyq/hyq_simple.urdf"
    "models/baxter/baxter_simple.urdf"
)

# Generator names and output directories
GENERATORS=("scalar_spatial_jacobian" "batched_spatial_jacobian")
OUTPUT_DIRS=("scalar" "batched")

# Generate headers for each robot with each generator
for i in "${!ROBOT_NAMES[@]}"; do
    robot="${ROBOT_NAMES[$i]}"
    urdf_path="${URDF_PATHS[$i]}"

    echo "=== Generating spatial Jacobian headers for ${robot} ==="
    echo "  URDF: ${urdf_path}"
    echo

    for j in "${!GENERATORS[@]}"; do
        generator="${GENERATORS[$j]}"
        output_dir="${OUTPUT_DIRS[$j]}"
        output_path="$RLA_EXP_ROOT/apps/rla_spatial_jacobian/gen/${output_dir}/jac_gen_${robot}.h"

        echo "  [${generator}] Generating ${output_path}..."

        "$RLA_EXP_ROOT/build/${generator}" "$RLA_EXP_ROOT/${urdf_path}" -o "${output_path}" -r "${robot}"

        if [ $? -ne 0 ]; then
            echo "  ✗ Failed to generate ${output_path}"
            exit 1
        fi

        echo "  ✓ Successfully generated ${output_path}"
    done

    echo
done

echo "All spatial Jacobian headers generated successfully!"
