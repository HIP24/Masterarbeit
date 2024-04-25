import os
import sys
import matplotlib.pyplot as plt
from collections import defaultdict
import matplotlib.ticker as ticker

def count_tasks(input_filename):
    # Initialize a dictionary to store the counts
    task_counts = defaultdict(int)

    # Initialize a dictionary to store the PIDs
    task_pids = {}

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
            
            # Extract the PID from the task and store it
            pid = task.split("-")[-1] if "-" in task else "N/A"
            task_pids[task] = pid

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
        f.write("| Task | PID | Count |\n")
        f.write("| --- | --- | --- |\n")

        # Write the counts and PIDs to the output file
        for task, count in sorted_tasks:
            # Extract the task name without the PID
            task_name = task.rsplit("-", 1)[0] if "-" in task else task

            # Escape < and > with a backslash
            escaped_task_name = task_name.replace("<", "\\<").replace(">", "\\>")

            pid = task_pids[task]
            f.write(f"| {escaped_task_name} | {pid} | {count:,} |\n".replace(",", "."))
        
    # Plotting
    tasks, counts = zip(*sorted_tasks)  # Unpack the sorted tasks and counts
    plt.figure(figsize=(15, 7))  # Adjust the figure size to better fit the horizontal plot
    bars = plt.barh(tasks, counts, color='blue')  # Use barh instead of bar for a horizontal plot
    
    # Labeling the bars with their counts
    max_count = max(counts)
    for bar in bars:
        xval = bar.get_width()
        plt.text(xval + (0.01 * max_count), bar.get_y() + bar.get_height()/2, f"{xval:,}".replace(",", "."), va='center')
    
    plt.ylabel('Tasks')
    plt.xlabel('Count')
    plt.title(f'Task Count (Total tasks: {total_count:,})'.replace(",", "."))
    plt.yticks(fontsize='small')  # Adjust font size for readability

    # Adjust left margin
    plt.subplots_adjust(left=0.4)

    # Set x axis length
    plt.xlim([0, max(counts)*1.2])  # Increase the x-axis limit to accommodate the moved text

    # Format x-axis labels with a period every third digit from the right
    plt.gca().xaxis.set_major_formatter(ticker.FuncFormatter(lambda x, pos: f'{x:,.0f}'.replace(",", ".")))

    # Set y axis limits to range of data
    plt.ylim([-0.5, len(tasks)-0.5])  # Adjust the ylim parameters

    # Save the figure
    plt.savefig(f'results_{base_filename}.png', bbox_inches='tight')
    # Save to /img folder
    #plt.savefig(f'../../../../../../img/results_{base_filename}.png', bbox_inches='tight')

# Get the input file name from the command-line arguments
input_filename = sys.argv[1]

# Call the function with the input file name
count_tasks(input_filename)
