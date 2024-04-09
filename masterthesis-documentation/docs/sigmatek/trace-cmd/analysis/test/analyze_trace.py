from collections import defaultdict

def count_tasks(filename):
    # Initialize a dictionary to store the counts
    task_counts = defaultdict(int)

    # Initialize a variable to store the total count of all events
    total_count = 0

    with open(filename, 'r') as f:
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

    # Print the counts
    for task, count in task_counts.items():
        print(f"{task}: {count}")

    # Print the total count of all events
    print(f"Total count of all events: {total_count}")

# Call the function with the name of your file
count_tasks('guest_report.txt')

