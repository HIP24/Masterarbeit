#!/bin/bash

# Check if a command-line argument is provided
if [ -z "$1" ]; then
    echo "Please provide a CPU number as a command-line argument."
    exit 1
fi

# Get the CPU number from the command-line argument
CPU=$1

# Define the mask values
declare -A mask_values
mask_values=( [0]="ffe" [1]="ffd" [2]="ffb" [3]="ff7" [4]="fef" [5]="fdf" [6]="fbf" [7]="f7f" [8]="eff" [9]="dff" [10]="bff" [11]="7ff" [12]="fff" [13]="7ff")

# Run the check_smp_affinity.sh script and get the IRQs
IRQs=$(./check_smp_affinity.sh $CPU | grep -o '[0-9]\+')

# Initialize an empty array to store the IRQs that could not be removed
failed_IRQs=()
# Initialize an empty array to store the IRQs that were successfully removed
succeeded_IRQs=()

# Loop over the IRQs
for IRQ in $IRQs; do
    # Try to change the smp_affinity
    echo ${mask_values[$CPU]} | sudo tee /proc/irq/$IRQ/smp_affinity > /dev/null 2>&1
    # If the command failed, add the IRQ to the failed_IRQs array
    if [ $? -ne 0 ]; then
        failed_IRQs+=($IRQ)
    else
        succeeded_IRQs+=($IRQ)
    fi
done

# Check if there were any failed IRQs
if [ ${#failed_IRQs[@]} -ne 0 ]; then
    echo "IRQs ${failed_IRQs[@]} could not be removed from CPU $CPU."
fi

# Check if there were any successful IRQs
if [ ${#succeeded_IRQs[@]} -ne 0 ]; then
    # Remove the first entry from the succeeded_IRQs array
    succeeded_IRQs=("${succeeded_IRQs[@]:1}")
    echo "IRQs ${succeeded_IRQs[@]} were removed from CPU $CPU."
fi
