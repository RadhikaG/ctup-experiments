#!/bin/bash

# Script to generate FK headers for multiple robots using different generators

# Create output directories if they don't exist
mkdir -p apps/rla_fk/gen/scalar
mkdir -p apps/rla_fk/gen/eigenmatrix
mkdir -p apps/rla_fk/gen/batched

# Robot names
ROBOT_NAMES=("baxter" "hyq" "iiwa")

# Corresponding URDF paths
URDF_PATHS=(
    "models/baxter/baxter_simple.urdf"
    "models/hyq/hyq_simple.urdf"
    "models/iiwa/iiwa_rbd_accel.urdf"
)

# Generator names and output directories
GENERATORS=("scalar_rla_fk" "eigenmatrix_fk" "batched_rla_fk")
OUTPUT_DIRS=("scalar" "eigenmatrix" "batched")

# Generate headers for each robot with each generator
for i in "${!ROBOT_NAMES[@]}"; do
    robot="${ROBOT_NAMES[$i]}"
    urdf_path="${URDF_PATHS[$i]}"

    echo "=== Generating FK headers for ${robot} ==="
    echo "  URDF: ${urdf_path}"
    echo

    for j in "${!GENERATORS[@]}"; do
        generator="${GENERATORS[$j]}"
        output_dir="${OUTPUT_DIRS[$j]}"
        output_path="apps/rla_fk/gen/${output_dir}/fk_gen_${robot}.h"

        echo "  [${generator}] Generating ${output_path}..."

        # All generators now require --robot parameter
        ./build/${generator} "${urdf_path}" -o "${output_path}" -r "${robot}"

        if [ $? -ne 0 ]; then
            echo "  ✗ Failed to generate ${output_path}"
            exit 1
        fi

        echo "  ✓ Successfully generated ${output_path}"
    done

    echo
done

echo "All FK headers generated successfully!"
