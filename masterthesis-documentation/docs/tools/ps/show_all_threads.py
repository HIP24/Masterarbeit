import pandas as pd
import re

# Read the data from the file
with open('show_all_threads.txt', 'r') as f:
    data = f.readlines()

# Extract the COMMAND column
commands = [line.split()[3] for line in data[1:]]

# Count the occurrences of each command
command_counts = pd.Series(commands).value_counts().reset_index()

# Rename the columns
command_counts.columns = ['COMMAND', 'COUNT']

# Sort the data
command_counts.sort_values(by='COUNT', ascending=False, inplace=True)

# Output the data in markdown table format
markdown_table = command_counts.to_markdown(index=False)

# Write the total number of threads and the markdown table to a new .md file
with open('show_all_threads.md', 'w') as f:
    f.write("Total number of ungrouped threads: " + str(len(commands)) + "\n\n")
    f.write(markdown_table)

# Group similar commands
grouped_commands = [re.sub(r'\d+$', '', command) for command in commands]

# Count the occurrences of each grouped command
grouped_command_counts = pd.Series(grouped_commands).value_counts().reset_index()

# Rename the columns
grouped_command_counts.columns = ['COMMAND', 'COUNT']

# Sort the data
grouped_command_counts.sort_values(by='COUNT', ascending=False, inplace=True)

# Output the data in markdown table format
grouped_markdown_table = grouped_command_counts.to_markdown(index=False)

# Write the total number of unique groups and the markdown table to a new .md file
with open('show_all_threads_grouped.md', 'w') as f:
    f.write("Total number of grouped threads: " + str(grouped_command_counts.shape[0]) + "\n\n")
    f.write(grouped_markdown_table)

# Print a success message
print("Count of all threads is successfully saved to show_all_threads_generated.")
