import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the data
csv_path = 'generated_latencies/latencies.csv'
df = pd.read_csv(csv_path, sep='     ;     ', engine='python')

# Convert columns to numeric values
df['Hardware Salamander 4 (us)'] = df['Hardware Salamander 4 (us)'].str.replace(',', '.').astype(float)
df['Tuned Salamander 4 Virtualization (us)'] = df['Tuned Salamander 4 Virtualization (us)'].str.replace(',', '.').astype(float)
df['Untuned Salamander 4 Virtualization (us)'] = df['Untuned Salamander 4 Virtualization (us)'].str.replace(',', '.').astype(float)

# Plot RTOS Latencies
plt.figure(figsize=(10, 6))
plt.plot(df.index, df['Hardware Salamander 4 (us)'], '-', color='purple', label='Hardware Salamander 4')
plt.xlabel('Count')
plt.ylabel('Latency [µs]')
#plt.title('RTOS Latencies')
plt.xlim([0, 1000])
plt.ylim([0, 40])
#plt.legend()
plt.savefig("generated_latencies/rtos_latencies.png")
plt.close()

# Plot Tuned Virtualized Latencies
plt.figure(figsize=(10, 6))
plt.plot(df.index, df['Tuned Salamander 4 Virtualization (us)'], '-', color='red', label='Tuned Salamander 4 Virtualization')
plt.xlabel('Count')
plt.ylabel('Latency [µs]')
#plt.title('Tuned Virtualized Latencies')
plt.xlim([0, 1000])
plt.ylim([0, 40])
#plt.legend()
plt.savefig("generated_latencies/tuned_virt_latencies.png")
plt.close()

# Plot Untuned Virtualized Latencies
plt.figure(figsize=(10, 6))
plt.plot(df.index, df['Untuned Salamander 4 Virtualization (us)'], '-', color='blue', label='Untuned Salamander 4 Virtualization')
plt.xlabel('Count')
plt.ylabel('Latency [µs]')
#plt.title('Untuned Virtualized Latencies')
plt.xlim([0, 1000])
plt.ylim([0, 400])
#plt.legend()
plt.savefig("generated_latencies/untuned_virt_latencies.png")
plt.close()

# Plot Combined Latencies
plt.figure(figsize=(10, 6))
plt.plot(df.index, df['Untuned Salamander 4 Virtualization (us)'], '-', color='blue', label='Untuned Salamander 4 Virtualization')
plt.plot(df.index, df['Tuned Salamander 4 Virtualization (us)'], '-', color='red', label='Tuned Salamander 4 Virtualization')
plt.plot(df.index, df['Hardware Salamander 4 (us)'], '-', color='purple', label='Hardware Salamander 4')
plt.xlabel('Count')
plt.ylabel('Latency [µs]')
#plt.title('Combined Latencies')
plt.xlim([0, 1000])
plt.ylim([0, 400])
plt.legend(loc='upper right')
plt.savefig("generated_latencies/combined_latencies.png")
plt.close()

# Print a success message
print("The plots were successfully saved to the 'generated_latencies' folder.")
