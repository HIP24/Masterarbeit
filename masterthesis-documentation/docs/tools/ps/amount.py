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

# Initialize variables to store the count of kernel and user tasks
kernel_count = 0
user_count = 0
group_kernel_count = 0
group_user_count = 0

# Open the file and read line by line
with open(file_name, 'r') as file:
    for line in file:
        # Split the line into words
        words = line.split()
        
        # If the line has at least 4 words
        if len(words) >= 4:
            # The task name is the fourth word
            task_name = words[3]
            
            # Determine if the task is a kernel task or a user task
            task_type = "Kernel" if task_name.startswith("k") else "User"
            
            # Increment the count of this task
            counts[(task_name, task_type)] += 1
            
            # Group tasks
            group_name = task_name.split('/')[0]
            group_counts[(group_name, task_type)] += 1
            
            # Increment the total count
            total_count += 1
            
            # Increment the count of kernel or user tasks
            if task_type == "Kernel":
                kernel_count += 1
                group_kernel_count += 1
            else:
                user_count += 1
                group_user_count += 1

# Count the number of unique task groups
total_group_count = len(group_counts)

# Sort the tasks by count in descending order
sorted_counts = sorted(counts.items(), key=lambda item: item[1], reverse=True)
sorted_group_counts = sorted(group_counts.items(), key=lambda item: item[1], reverse=True)

# Open the output file and write the counts in a table format
with open("amount.md", 'w') as file:
    # Write the table header
    file.write(f"Total tasks count (individual): {total_count}\n")

    # Write the count of kernel and user tasks
    file.write(f"\nKernel tasks: {kernel_count}\n")
    file.write(f"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;User tasks: {user_count}\n")

    file.write("| Task | Task Type | Count |\n")
    file.write("| --- | --- | --- |\n")

    # Write the counts
    for (task_name, task_type), count in sorted_counts:
        file.write(f"| {task_name} | {task_type} | {count} |\n")
    
# Open the group output file and write the counts in a table format
with open("amount_group.md", 'w') as file:
    # Write the table header
    file.write(f"Total tasks count (grouped): {total_group_count}\n")

    # Write the count of kernel and user tasks
    file.write(f"\nKernel tasks: {group_kernel_count}\n")
    file.write(f"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;User tasks: {user_count}\n")

    file.write("| Task Group | Task Type | Count |\n")
    file.write("| --- | --- | --- |\n")

    # Write the counts
    for (group_name, task_type), count in sorted_group_counts:
        file.write(f"| {group_name} | {task_type} | {count} |\n")