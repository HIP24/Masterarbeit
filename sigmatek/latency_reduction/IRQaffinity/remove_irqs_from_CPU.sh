#!/bin/bash

# Check if a command-line argument is provided
if [ -z "$1" ]; then
    echo "Please provide a CPU number as a command-line argument."
    exit 1
fi

# Get the CPU number from the command-line argument
CPU=$1

# Run the check_smp_affinity.sh script and get the IRQs
IRQs=$(./check_smp_affinity.sh $CPU | grep -o '[0-9]\+')

# Initialize an empty array to store the IRQs that could not be removed
failed_IRQs=()

# Loop over the IRQs
for IRQ in $IRQs; do
    # Try to change the smp_affinity
    echo 1fff | sudo tee /proc/irq/$IRQ/smp_affinity > /dev/null 2>&1
    # If the command failed, add the IRQ to the failed_IRQs array
    if [ $? -ne 0 ]; then
        failed_IRQs+=($IRQ)
    fi
done

# Check if there were any failed IRQs
if [ ${#failed_IRQs[@]} -ne 0 ]; then
    echo "IRQs ${failed_IRQs[@]} could not be removed from CPU $CPU."
fi
