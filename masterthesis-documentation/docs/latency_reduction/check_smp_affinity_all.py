import os

# Get the number of CPUs
num_cpus = os.cpu_count()

# Initialize a list to store the IRQs for each CPU
irqs_per_cpu = [[] for _ in range(num_cpus)]

# Iterate over each CPU
for cpu in range(num_cpus):
    # Iterate over each IRQ
    for irq in os.listdir('/proc/irq'):
        # Check if the smp_affinity file exists for this IRQ
        if os.path.isfile(f'/proc/irq/{irq}/smp_affinity'):
            # Read the current smp_affinity
            with open(f'/proc/irq/{irq}/smp_affinity', 'r') as f:
                affinity = f.read().strip()
            # Check if the bit for the current CPU is set
            if ((int(affinity, 16) & (1 << cpu)) != 0):
                # Add the IRQ to the list for this CPU
                irqs_per_cpu[cpu].append(int(irq))

# Function to summarize a list of IRQs
def summarize_irqs(irqs):
    # Sort the IRQs
    irqs.sort()
    # Initialize the start and end of the current range
    start = end = irqs[0]
    # Initialize the list of ranges
    ranges = []
    # Iterate over the rest of the IRQs
    for irq in irqs[1:]:
        # If this IRQ is one more than the end of the current range
        if irq == end + 1:
            # Extend the current range
            end = irq
        else:
            # Add the current range to the list
            if start == end:
                ranges.append(start)
            else:
                ranges.append(f"{start}-{end}")
            # Start a new range
            start = end = irq
    # Add the last range to the list
    if start == end:
        ranges.append(start)
    else:
        ranges.append(f"{start}-{end}")
    # Return the list of ranges
    return ','.join(map(str, ranges))

# Open the log file
with open("irq_affinity.log", "w") as f:
    # Print the IRQs for each CPU
    for cpu in range(num_cpus):
        # Write the output to the log file
        f.write(f'CPU {cpu}: [{summarize_irqs(irqs_per_cpu[cpu])}] -> total of {len(irqs_per_cpu[cpu])} IRQs\n')

# Print a success message
print("The IRQs for each CPU have been successfully written to irq_affinity.log")

