from collections import defaultdict

def count_properties(filename):
    # Initialize dictionaries to store the counts
    task_counts = defaultdict(int)
    cpu_counts = defaultdict(int)
    timestamp_counts = defaultdict(int)
    exit_reason_counts = defaultdict(int)

    with open(filename, 'r') as f:
        for line in f:
            # Split the line into words
            words = line.split()

            # Skip lines that don't have enough words
            if len(words) < 4:
                continue

            # Update the counts
            task_counts[words[0]] += 1
            cpu_counts[words[1]] += 1
            timestamp_counts[words[2]] += 1
            exit_reason_counts[words[3]] += 1

    # Print the counts
    print("Task counts:", dict(task_counts))
    print("CPU counts:", dict(cpu_counts))
    print("Timestamp counts:", dict(timestamp_counts))
    print("Exit reason counts:", dict(exit_reason_counts))

# Call the function with the name of your file
count_properties('guest_report.txt')

