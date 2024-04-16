import os
import sys
import matplotlib.pyplot as plt
from collections import defaultdict
import matplotlib.ticker as ticker

def count_tasks(input_filename):
    # Initialize a dictionary to store the counts
    task_counts = defaultdict(int)

    # Initialize a variable to store the total count of all events
    total_count = 0

    with open(input_filename, 'r') as f:
        for line in f:
            # Skip lines that start with "cpus=1" or "cpus=20" or "000:" or "010:"
            if line.startswith("cpus=1") or line.startswith("cpus=20") or line.startswith("000:") or line.startswith("010:"):
                continue

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

    # Remove the .txt extension from the input filename
    base_filename = os.path.splitext(input_filename)[0]

    # Use f-string to include the base_filename in the output filename
    with open(f'results_{base_filename}.md', 'w') as f:
        # Write the total count of all events to the output file
        f.write(f"Total count of all events: {total_count:,}\n\n".replace(",", ".")) 

        # Write the table headers
        f.write("| Task | Count |\n")
        f.write("| --- | --- |\n")

        # Write the counts to the output file
        for task, count in sorted_tasks:
            # Escape < and > with a backslash
            task = task.replace("<", "\\<").replace(">", "\\>")
            f.write(f"| {task} | {count:,} |\n".replace(",", "."))

    # Plotting
    tasks, counts = zip(*sorted_tasks)  # Unpack the sorted tasks and counts
    plt.figure(figsize=(20, 15))
    bars = plt.bar(tasks, counts, color='blue')

    # Labeling the bars with their counts
    for bar in bars:
        yval = bar.get_height()
        plt.text(bar.get_x() + bar.get_width()/2, yval + 0.05, f"{yval:,}".replace(",", "."), ha='center', va='bottom')

    plt.xlabel('Tasks')
    plt.ylabel('Count')
    plt.title(f'Task Count (Total tasks: {total_count:,})'.replace(",", "."))
    plt.xticks(rotation=90, fontsize='small')

    # Adjust bottom margin
    plt.subplots_adjust(bottom=0.4)

    # Set y axis length
    plt.ylim([0, max(counts)*1.2])

    # Format y-axis labels with a period every third digit from the right
    plt.gca().yaxis.set_major_formatter(ticker.FuncFormatter(lambda x, pos: f'{x:,.0f}'.replace(",", ".")))

    # Save the figure
    plt.savefig(f'results_{base_filename}.png', bbox_inches='tight')

# Get the input file name from the command-line arguments
input_filename = sys.argv[1]

# Call the function with the input file name
count_tasks(input_filename)
