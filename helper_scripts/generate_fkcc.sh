#!/bin/bash

# Script to generate FKCC (Forward Kinematics with Collision Checking) headers for multiple robots

# Get the directory where this script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RLA experiments root is one level up from helper_scripts
RLA_EXP_ROOT="$(dirname "$SCRIPT_DIR")"

# Create output directory if it doesn't exist
mkdir -p "$RLA_EXP_ROOT/apps/rla_fkcc_early_exit/gen"

# Robot names
ROBOT_NAMES=("ur5" "panda" "fetch" "baxter")

# Corresponding URDF paths (coarse, fine, SRDF)
URDF_COARSE_PATHS=(
    "models/ur5/ur5_spherized_1.urdf"
    "models/panda/panda_spherized_1.urdf"
    "models/fetch/fetch_spherized_1.urdf"
    "models/baxter/baxter_spherized_1.urdf"
)

URDF_FINE_PATHS=(
    "models/ur5/ur5_spherized.urdf"
    "models/panda/panda_spherized.urdf"
    "models/fetch/fetch_spherized.urdf"
    "models/baxter/baxter_spherized.urdf"
)

SRDF_PATHS=(
    "models/ur5/ur5.srdf"
    "models/panda/panda.srdf"
    "models/fetch/fetch.srdf"
    "models/baxter/baxter.srdf"
)

# Generate headers for each robot
for i in "${!ROBOT_NAMES[@]}"; do
    robot="${ROBOT_NAMES[$i]}"
    urdf_coarse="${URDF_COARSE_PATHS[$i]}"
    urdf_fine="${URDF_FINE_PATHS[$i]}"
    srdf="${SRDF_PATHS[$i]}"
    output_path="$RLA_EXP_ROOT/apps/rla_fkcc_early_exit/gen/fkcc_${robot}_franken.h"

    echo "=== Generating FKCC header for ${robot} ==="
    echo "  URDF coarse: ${urdf_coarse}"
    echo "  URDF fine: ${urdf_fine}"
    echo "  SRDF: ${srdf}"
    echo "  Output: ${output_path}"
    echo

    "$RLA_EXP_ROOT/build/franken_batched_fkcc_early_exit" "$RLA_EXP_ROOT/${urdf_coarse}" "$RLA_EXP_ROOT/${urdf_fine}" "$RLA_EXP_ROOT/${srdf}" -r "${robot}" -o "${output_path}"

    if [ $? -ne 0 ]; then
        echo "  ✗ Failed to generate ${output_path}"
        exit 1
    fi

    echo "  ✓ Successfully generated ${output_path}"
    echo "  Applying regex fixes..."

    # Apply regex fixes to the generated header
    # Fix 1: Add early return after self_collision_link_vs_link calls
    sed -i -E 's/^([[:space:]]*)([[:alnum:]_]+)[[:space:]]*=[[:space:]]*ctup_runtime::self_collision_link_vs_link\((.*)\);/&\n\1if (\2)\n\1  return 0;/g' "${output_path}"

    # Fix 2: Add early return after link_vs_environment_collision calls
    sed -i -E 's/^([[:space:]]*)([[:alnum:]_]+)[[:space:]]*=[[:space:]]*ctup_runtime::link_vs_environment_collision\((.*)\);/&\n\1if (\2)\n\1  return 0;/g' "${output_path}"

    echo "  ✓ Applied regex fixes"
    echo
done

echo "All FKCC headers generated successfully!"
