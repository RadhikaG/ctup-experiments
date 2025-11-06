#!/bin/bash

# Script to generate FK headers for CT/TT study

# Get the directory where this script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RLA experiments root is one level up from helper_scripts
RLA_EXP_ROOT="$(dirname "$SCRIPT_DIR")"

# Robot names
ROBOTS=("iiwa" "hyq" "baxter")

# Corresponding URDF paths
declare -A URDF_PATHS
URDF_PATHS["iiwa"]="models/iiwa/iiwa_rbd_accel.urdf"
URDF_PATHS["hyq"]="models/hyq/hyq_simple.urdf"
URDF_PATHS["baxter"]="models/baxter/baxter_simple.urdf"

# Create output directory
output_dir="$RLA_EXP_ROOT/apps/rla_fk_ct_tt_study/gen"
mkdir -p "$output_dir"

# Generate headers for each robot (all 3 variants in one file)
for robot in "${ROBOTS[@]}"; do
    urdf_path="${URDF_PATHS[$robot]}"
    output_path="${output_dir}/fk_gen_${robot}.h"

    echo "========================================="
    echo "Generating ${robot} (all variants)"
    echo "========================================="
    echo "  URDF: ${urdf_path}"
    echo "  Output: ${output_path}"
    echo ""

    # Generate the FK header with all 3 variants
    "$RLA_EXP_ROOT/build/batched_rla_fk_ct_tt_study_batched" \
        "$RLA_EXP_ROOT/${urdf_path}" \
        -o "${output_path}" \
        -r "${robot}"

    if [ $? -ne 0 ]; then
        echo ""
        echo "  ✗ Failed to generate ${output_path}"
        exit 1
    fi

    echo ""
    echo "  ✓ Successfully generated ${output_path}"
    echo ""
done

echo "========================================="
echo "All FK CT/TT study headers generated successfully!"
echo "========================================="
