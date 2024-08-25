import os
import numpy as np
import pandas as pd

# Create the folder
folder_name = 'generated_latencies'
os.makedirs(folder_name, exist_ok=True)

# Generate latencies
np.random.seed(42)  # for reproducibility

def generate_rtos_latencies(size=1000):
    return np.random.uniform(10, 13, size).round(1)

def generate_tuned_virt_latencies(size=1000):
    return np.random.uniform(10, 20, size).round(1)

def generate_untuned_virt_latencies(size=1000):
    # Generate most values between 10 and 100
    base = np.random.exponential(scale=20, size=size) + 10
    # Add some outliers
    outliers = np.random.uniform(100, 400, size=int(size * 0.05))
    base[:len(outliers)] = outliers
    np.random.shuffle(base)
    return np.clip(base, 10, 400).round(1)

# Generate latencies
rtos_latencies = generate_rtos_latencies()
tuned_virt_latencies = generate_tuned_virt_latencies()
untuned_virt_latencies = generate_untuned_virt_latencies()

# Convert to strings and replace dots with commas
rtos_latencies = [str(latency).replace('.', ',') for latency in rtos_latencies]
tuned_virt_latencies = [str(latency).replace('.', ',') for latency in tuned_virt_latencies]
untuned_virt_latencies = [str(latency).replace('.', ',') for latency in untuned_virt_latencies]

# Create a DataFrame
data = {
    'Hardware Salamander 4 (us)': rtos_latencies,
    'Tuned Salamander 4 Virtualization (us)': tuned_virt_latencies,
    'Untuned Salamander 4 Virtualization (us)': untuned_virt_latencies
}
df = pd.DataFrame(data)

# Save to a single CSV file with semicolon separator
csv_path = os.path.join(folder_name, 'latencies.csv')
df.to_csv(csv_path, index=False, sep=';')

# Manually add spaces around the semicolon
with open(csv_path, 'r') as file:
    content = file.read()

content = content.replace(';', '     ;     ')

with open(csv_path, 'w') as file:
    file.write(content)

# Print a success message
print("The latency values were successfully saved to 'latencies.csv'.")
