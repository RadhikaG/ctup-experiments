#!/bin/bash

# Script to generate RNEA headers for multiple robots

# Get the directory where this script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RLA experiments root is one level up from helper_scripts
RLA_EXP_ROOT="$(dirname "$SCRIPT_DIR")"

# Create output directory if it doesn't exist
mkdir -p "$RLA_EXP_ROOT/apps/rla_rnea/gen"

# Robot names
ROBOT_NAMES=("baxter" "hyq" "iiwa")

# Corresponding URDF paths
URDF_PATHS=(
    "models/baxter/baxter_simple.urdf"
    "models/hyq/hyq_simple.urdf"
    "models/iiwa/iiwa_rbd_accel.urdf"
)

# Generate headers for each robot
for i in "${!ROBOT_NAMES[@]}"; do
    robot="${ROBOT_NAMES[$i]}"
    urdf_path="${URDF_PATHS[$i]}"
    output_path="$RLA_EXP_ROOT/apps/rla_rnea/gen/rnea_gen_${robot}.h"

    echo "Generating RNEA header for ${robot}..."
    echo "  URDF: ${urdf_path}"
    echo "  Output: ${output_path}"

    "$RLA_EXP_ROOT/build/scalar_rla_rnea" "$RLA_EXP_ROOT/${urdf_path}" -o "${output_path}" -r "${robot}"

    if [ $? -ne 0 ]; then
        echo "  ✗ Failed to generate ${output_path}"
        exit 1
    fi

    echo "  ✓ Successfully generated ${output_path}"
    echo
done

echo "All RNEA headers generated successfully!"
