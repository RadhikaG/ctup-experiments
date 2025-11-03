#!/bin/bash

# Script to generate self-collision signed distance gradient headers for multiple robots

# Get the directory where this script is located
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
# RLA experiments root is one level up from helper_scripts
RLA_EXP_ROOT="$(dirname "$SCRIPT_DIR")"

# Create output directory if it doesn't exist
mkdir -p "$RLA_EXP_ROOT/apps/rla_grad_self_collision/gen"

# Robot configurations
declare -A ROBOT_URDF=(
    ["panda"]="models/panda"
    ["ur5"]="models/ur5"
)

declare -A ROBOT_SRDF=(
    ["panda"]="models/panda/panda.srdf"
    ["ur5"]="models/ur5/ur5.srdf"
)

# Fidelities for each robot
PANDA_FIDELITIES=("spherized" "spherized_1")
UR5_FIDELITIES=("spherized" "spherized_1")

# Generate headers for Panda
for fidelity in "${PANDA_FIDELITIES[@]}"; do
    robot="panda"
    config_name="${robot}_${fidelity}"
    urdf_path="$RLA_EXP_ROOT/${ROBOT_URDF[$robot]}/${config_name}.urdf"
    srdf_path="$RLA_EXP_ROOT/${ROBOT_SRDF[$robot]}"
    output_path="$RLA_EXP_ROOT/apps/rla_grad_self_collision/gen/${config_name}.h"

    echo "=== Generating SD gradient header for ${config_name} ==="
    echo "  URDF: ${urdf_path}"
    echo "  SRDF: ${srdf_path}"
    echo "  Output: ${output_path}"
    echo

    # Check if input files exist
    if [ ! -f "${urdf_path}" ]; then
        echo "  ✗ URDF file not found: ${urdf_path}"
        echo "  Skipping ${config_name}"
        echo
        continue
    fi

    if [ ! -f "${srdf_path}" ]; then
        echo "  ✗ SRDF file not found: ${srdf_path}"
        echo "  Skipping ${config_name}"
        echo
        continue
    fi

    # Generate the header using batched_grad_self_collision
    "$RLA_EXP_ROOT/build/batched_grad_self_collision" "${urdf_path}" "${srdf_path}" -o "${output_path}" -r "${robot}" -f "${fidelity}"

    if [ $? -ne 0 ]; then
        echo "  ✗ Failed to generate ${output_path}"
        exit 1
    fi

    echo "  ✓ Successfully generated ${output_path}"
    echo
done

# Generate headers for UR5
for fidelity in "${UR5_FIDELITIES[@]}"; do
    robot="ur5"
    config_name="${robot}_${fidelity}"
    urdf_path="$RLA_EXP_ROOT/${ROBOT_URDF[$robot]}/${config_name}.urdf"
    srdf_path="$RLA_EXP_ROOT/${ROBOT_SRDF[$robot]}"
    output_path="$RLA_EXP_ROOT/apps/rla_grad_self_collision/gen/${config_name}.h"

    echo "=== Generating SD gradient header for ${config_name} ==="
    echo "  URDF: ${urdf_path}"
    echo "  SRDF: ${srdf_path}"
    echo "  Output: ${output_path}"
    echo

    # Check if input files exist
    if [ ! -f "${urdf_path}" ]; then
        echo "  ✗ URDF file not found: ${urdf_path}"
        echo "  Skipping ${config_name}"
        echo
        continue
    fi

    if [ ! -f "${srdf_path}" ]; then
        echo "  ✗ SRDF file not found: ${srdf_path}"
        echo "  Skipping ${config_name}"
        echo
        continue
    fi

    # Generate the header using batched_grad_self_collision
    "$RLA_EXP_ROOT/build/batched_grad_self_collision" "${urdf_path}" "${srdf_path}" -o "${output_path}" -r "${robot}" -f "${fidelity}"

    if [ $? -ne 0 ]; then
        echo "  ✗ Failed to generate ${output_path}"
        exit 1
    fi

    echo "  ✓ Successfully generated ${output_path}"
    echo
done

echo "All SD gradient headers generated successfully!"
