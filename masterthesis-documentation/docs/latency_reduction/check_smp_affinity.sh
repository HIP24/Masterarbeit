#!/bin/bash
# Get the CPU number from the command-line argument
CPU=$1
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
# Print the sorted IRQ numbers on the same line, separated by ", "
IFS=','; echo "CPU $CPU: ${sorted[*]}"
