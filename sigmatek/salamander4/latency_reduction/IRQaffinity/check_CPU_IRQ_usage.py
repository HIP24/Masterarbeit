import os

# Get the number of CPUs
num_cpus = os.cpu_count()

# Initialize a dictionary to store the CPUs for each IRQ
irqs = {}

# Iterate over each IRQ
for irq in os.listdir('/proc/irq'):
    # Check if the smp_affinity file exists for this IRQ
    if os.path.isfile(f'/proc/irq/{irq}/smp_affinity'):
        # Read the current smp_affinity
        with open(f'/proc/irq/{irq}/smp_affinity', 'r') as f:
            affinity = int(f.read().strip(), 16)
        # Initialize an empty list to store the CPUs for this IRQ
        cpus = []
        # Iterate over each CPU
        for cpu in range(num_cpus):
            # Check if the bit for the current CPU is set
            if ((affinity & (1 << cpu)) != 0):
                # Add the CPU to the list for this IRQ
                cpus.append(cpu)
        # Sort the list of CPUs
        cpus.sort()
        # Add the list of CPUs to the dictionary for this IRQ
        irqs[irq] = cpus

# Open the log file
with open("check_CPU_IRQ_usage.log", "w") as f:
    # Print the CPUs for each IRQ
    for irq, cpus in sorted(irqs.items(), key=lambda x: int(x[0])):
        # Write the output to the log file
        f.write(f'IRQ {irq}: [{",".join(map(str, cpus))}] -> total of {len(cpus)} CPUs\n')

# Print a success message
print("The CPUs for each IRQ have been successfully written to check_CPU_IRQ_usage.log")
