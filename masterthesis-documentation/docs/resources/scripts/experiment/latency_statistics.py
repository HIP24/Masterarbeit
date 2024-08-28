import pandas as pd
import numpy as np

# Load the data
csv_path = 'generated_latencies/latencies.csv'
df = pd.read_csv(csv_path, sep='     ;     ', engine='python')

# Convert columns to numeric values
df['Hardware Salamander 4 (ms)'] = df['Hardware Salamander 4 (ms)'].str.replace(',', '.').astype(float)
df['Tuned Salamander 4 Virtualization (ms)'] = df['Tuned Salamander 4 Virtualization (ms)'].str.replace(',', '.').astype(float)
df['Untuned Salamander 4 Virtualization (ms)'] = df['Untuned Salamander 4 Virtualization (ms)'].str.replace(',', '.').astype(float)

# Calculate statistics
def calculate_statistics(latencies):
    return {
        'Samples': len(latencies),
        'Lat Min (ms)': f"{np.min(latencies):.3f}".replace('.', ','),
        'Lat Avg (ms)': f"{np.mean(latencies):.3f}".replace('.', ','),
        'Lat Max (ms)': f"{np.max(latencies):.3f}".replace('.', ','),
        'Std Dev (ms)': f"{np.std(latencies):.3f}".replace('.', ',')
    }

rtos_stats = calculate_statistics(df['Hardware Salamander 4 (ms)'])
tuned_virt_stats = calculate_statistics(df['Tuned Salamander 4 Virtualization (ms)'])
untuned_virt_stats = calculate_statistics(df['Untuned Salamander 4 Virtualization (ms)'])

# Create a DataFrame for the statistics
stats_df = pd.DataFrame([rtos_stats, tuned_virt_stats, untuned_virt_stats], 
                        index=['Hardware Salamander', 'Tuned Salamander 4 Virtualization', 'Untuned Salamander 4 Virtualization'])

# Save the statistics to a CSV file with semicolon separator
stats_csv_path = 'generated_latencies/statistics.csv'
stats_df.to_csv(stats_csv_path, sep=';')

# Manually add spaces around the semicolon
with open(stats_csv_path, 'r') as file:
    content = file.read()

content = content.replace(';', '     ;     ')

with open(stats_csv_path, 'w') as file:
    file.write(content)

# Print a success message
print("The statistics were successfully saved to 'statistics.csv'.")
