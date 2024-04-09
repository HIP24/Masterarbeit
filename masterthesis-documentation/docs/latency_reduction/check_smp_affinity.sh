#!/bin/bash
# Check if a command-line argument is provided
if [ -z "$1" ]; then
    echo "Please provide a CPU number as a command-line argument."
    exit 1
fi
# Get the CPU number from the command-line argument
CPU=$1
# Check if the CPU exists
if [ $CPU -ge $(nproc) ]; then
    echo "CPU $CPU does not exist."
    exit 1
fi
# Initialize an empty array to store the IRQ numbers
IRQs=()
for IRQ in /proc/irq/*; do
    if [ -f "$IRQ/smp_affinity" ]; then
        # Read the current smp_affinity
        AFFINITY=$(cat "$IRQ/smp_affinity")
        # Check if the bit for the current CPU is set
        if (( (0x$AFFINITY & (1 << CPU)) != 0 )); then
            # Add the IRQ number to the array
            IRQs+=("${IRQ#/proc/irq/}")
        fi
    fi
done
# Sort the array
IFS=$'\n' sorted=($(sort -n <<<"${IRQs[*]}"))
# Print the CPU number
echo "CPU $CPU IRQ affinity:"
# Print the sorted IRQ numbers on separate lines
for irq in "${sorted[@]}"; do
    echo "$irq"
done
