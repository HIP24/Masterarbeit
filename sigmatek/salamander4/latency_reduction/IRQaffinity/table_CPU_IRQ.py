import os
import pandas as pd
from tabulate import tabulate

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

# Create a DataFrame to store the table
df = pd.DataFrame(index=sorted(irqs.keys(), key=int), columns=range(num_cpus))

# Fill the DataFrame with 'x' where a CPU is assigned to an IRQ
for irq, cpus in irqs.items():
    for cpu in cpus:
        df.loc[irq, cpu] = 'x'

# Replace NaN values with empty strings
df.fillna('', inplace=True)

# Print the table in pipe format
print(tabulate(df, headers='keys', tablefmt='pipe', showindex=True))

# Convert the DataFrame to a markdown table
markdown_table = df.to_markdown()

# Write the markdown table to a file
with open('table_CPU_IRQ.md', 'w') as f:
    f.write(markdown_table)

