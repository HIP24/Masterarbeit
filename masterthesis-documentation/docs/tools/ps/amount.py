# Import the required module
import collections

# Define the file name
file_name = "ps.txt"

# Initialize a dictionary to store the counts
counts = collections.defaultdict(int)
group_counts = collections.defaultdict(int)

# Initialize a variable to store the total count
total_count = 0
total_group_count = 0

# Open the file and read line by line
with open(file_name, 'r') as file:
    for line in file:
        # Split the line into words
        words = line.split()
        
        # If the line has at least 4 words
        if len(words) >= 4:
            # The task name is the fourth word
            task_name = words[3]
            
            # Increment the count of this task
            counts[task_name] += 1
            
            # Group tasks
            group_name = task_name.split('/')[0]
            group_counts[group_name] += 1
            
            # Increment the total count
            total_count += 1

# Count the number of unique task groups
total_group_count = len(group_counts)

# Sort the tasks by count in descending order
sorted_counts = sorted(counts.items(), key=lambda item: item[1], reverse=True)
sorted_group_counts = sorted(group_counts.items(), key=lambda item: item[1], reverse=True)

# Open the output file and write the counts in a table format
with open("amount.md", 'w') as file:
    # Write the table header
    file.write(f"The total count of tasks when not grouped is {total_count}.\n")
    file.write("| Task | Count |\n")
    file.write("| --- | --- |\n")
    
    # Write the counts
    for task_name, count in sorted_counts:
        file.write(f"| {task_name} | {count} |\n")

# Open the group output file and write the counts in a table format
with open("amount_group.md", 'w') as file:
    # Write the table header
    file.write(f"The total count of tasks when grouped is {total_group_count}.\n")
    file.write("| Task Group | Count |\n")
    file.write("| --- | --- |\n")
    
    # Write the counts
    for group_name, count in sorted_group_counts:
        file.write(f"| {group_name} | {count} |\n")
