#!/bin/bash

# Replace 'process_name1' and 'process_name2' with the names of your processes
process_name1="irq/157-nvme0q5"
process_name2="irq/172-nvme1q5"

# Initialize a variable to track success status
success=true

# Find the PID of the first process
pid1=$(pgrep -f $process_name1)

# Check if the PID was found
if [ -n "$pid1" ]; then
    # Set the CPU affinity of the process to CPU 0
    sudo taskset -p -c 0 $pid1 > /dev/null
else
    echo "Process $process_name1 not found."
    success=false
fi

# Find the PID of the second process
pid2=$(pgrep -f $process_name2)

# Check if the PID was found
if [ -n "$pid2" ]; then
    # Set the CPU affinity of the process to CPU 0
    sudo taskset -p -c 0 $pid2 > /dev/null
else
    echo "Process $process_name2 not found."
    success=false
fi

# Print a success message if no errors occurred
if $success; then
    echo "CPU affinity successfully changed."
fi
