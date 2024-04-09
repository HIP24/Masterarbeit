import sys
from collections import defaultdict

def count_tasks(input_filename):
    # Initialize a dictionary to store the counts
    task_counts = defaultdict(int)

    # Initialize a variable to store the total count of all events
    total_count = 0

    with open(input_filename, 'r') as f:
        for line in f:
            # Split the line into words
            words = line.split()

            # Skip lines that don't have enough words
            if len(words) < 1:
                continue

            # The task is the first word in the line
            task = words[0]

            # Update the count for this task
            task_counts[task] += 1

            # Update the total count of all events
            total_count += 1

    # Sort the tasks by count in descending order
    sorted_tasks = sorted(task_counts.items(), key=lambda x: x[1], reverse=True)

    # Use f-string to include the input_filename in the output filename
    with open(f'results_{input_filename}', 'w') as f:
        # Write the total count of all events to the output file
        f.write(f"Total count of all events: {total_count}\n") 

        # Write the counts to the output file
        for task, count in sorted_tasks:
            f.write(f"{task}: {count}\n")

# Get the input file name from the command-line arguments
input_filename = sys.argv[1]

# Call the function with the input file name
count_tasks(input_filename)
