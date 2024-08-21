#!/bin/bash
# Check if an argument was provided
if [ -z "$1" ]; then
    echo "Please provide an IRQ number as a command-line argument."
    exit 1
fi

# Get the IRQ number from the command-line argument
IRQ=$1
# Get the number of CPUs
num_cpus=$(getconf _NPROCESSORS_CONF)
# Initialize an empty array to store the CPU numbers
CPUs=()

# Check if the smp_affinity file exists for this IRQ
if [ -f "/proc/irq/$IRQ/smp_affinity" ]; then
    # Read the current smp_affinity
    AFFINITY=$(cat "/proc/irq/$IRQ/smp_affinity")
    # Iterate over each CPU
    for ((cpu=0; cpu<num_cpus; cpu++)); do
        # Check if the bit for the current CPU is set
        if (( (0x$AFFINITY & (1 << cpu)) != 0 )); then
            # Add the CPU number to the array
            CPUs+=("$cpu")
        fi
    done
    # Sort the array
    IFS=$'\n' sorted=($(sort -n <<<"${CPUs[*]}"))
    # Print the IRQ number
    echo "IRQ $IRQ is being used by CPU:"
    # Print the sorted CPU numbers on separate lines
    for cpu in "${sorted[@]}"; do
        echo "$cpu"
    done
else
    echo "IRQ $IRQ does not exist or does not have an smp_affinity file."
fi