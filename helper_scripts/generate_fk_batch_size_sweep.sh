#!/bin/bash

# Script to generate FK headers for batch size sweep (4, 8, 16, 32)

# Get the directory where this script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RLA experiments root is one level up from helper_scripts
RLA_EXP_ROOT="$(dirname "$SCRIPT_DIR")"

# Batch sizes to sweep
BATCH_SIZES=(4 8 16 32)

# Robot names (for -r parameter)
ROBOT_NAMES=("baxter" "hyq" "iiwa" "synth_12" "synth_12" "synth_12" "synth_12" "synth_12")

# Output file base names (for generated header filenames)
OUTPUT_NAMES=("baxter" "hyq" "iiwa" "serial_12dof" "dual_6dof" "triple_4dof" "quad_3dof" "tree_2_5_5")

# Corresponding URDF paths
URDF_PATHS=(
    "models/baxter/baxter_simple.urdf"
    "models/hyq/hyq_simple.urdf"
    "models/iiwa/iiwa_rbd_accel.urdf"
    "models/synth_12/serial_12dof.urdf"
    "models/synth_12/dual_6dof.urdf"
    "models/synth_12/triple_4dof.urdf"
    "models/synth_12/quad_3dof.urdf"
    "models/synth_12/tree_2_5_5.urdf"
)

# Generate headers for each batch size, then for each robot
for batch_size in "${BATCH_SIZES[@]}"; do
    echo "========================================="
    echo "Generating for batch size: ${batch_size}"
    echo "========================================="
    echo

    # Create output directory for this batch size
    output_dir="$RLA_EXP_ROOT/apps/rla_fk_batch_size_sweep/gen/f${batch_size}"
    mkdir -p "$output_dir"

    for i in "${!ROBOT_NAMES[@]}"; do
        robot="${ROBOT_NAMES[$i]}"
        output_name="${OUTPUT_NAMES[$i]}"
        urdf_path="${URDF_PATHS[$i]}"
        output_path="${output_dir}/fk_gen_${output_name}.h"

        echo "  [batch_size=${batch_size}] Generating ${output_name} (robot=${robot})..."
        echo "    URDF: ${urdf_path}"
        echo "    Output: ${output_path}"

        # Generate the FK header
        "$RLA_EXP_ROOT/build/rla_fk_batch_size_sweep" \
            "$RLA_EXP_ROOT/${urdf_path}" \
            -o "${output_path}" \
            -r "${robot}" \
            -b "${batch_size}"

        if [ $? -ne 0 ]; then
            echo "  ✗ Failed to generate ${output_path}"
            exit 1
        fi

        echo "  ✓ Successfully generated ${output_path}"
        echo
    done

    echo
done

echo "========================================="
echo "All FK batch size sweep headers generated successfully!"
echo "========================================="
