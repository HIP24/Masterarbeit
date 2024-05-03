import os
import sys
import matplotlib.pyplot as plt
from collections import defaultdict
import matplotlib.ticker as ticker

def count_events(input_filename):
    # Initialize a dictionary to store the counts
    event_counts = defaultdict(int)

    # Initialize a variable to store the total count of all events
    total_count = 0

    with open(input_filename, 'r') as f:
        for line in f:
            # Skip lines that start with "cpus=1" or "cpus=20" or "000:" or "010:"
            if line.startswith("cpus=1") or line.startswith("cpus=20") or line.startswith("000:") or line.startswith("010:"):
                continue

            # Find the position of ': ' (colon followed by space)
            start_pos = line.find(': ')

            # If ': ' is found
            if start_pos != -1:
                # Find the position of the next colon after ': '
                end_pos = line.find(':', start_pos + 2)

                # If the next colon is found
                if end_pos != -1:
                    # The event is the text between ': ' and the next colon
                    event = line[start_pos + 2:end_pos]

                    # Update the count for this event
                    event_counts[event] += 1

                    # Update the total count of all events
                    total_count += 1


    # Sort the events by count in descending order
    sorted_events = sorted(event_counts.items(), key=lambda x: x[1], reverse=True)

    # Remove the .txt extension from the input filename
    base_filename = os.path.splitext(input_filename)[0]

    # Use f-string to include the base_filename in the output filename
    with open(f'events_{base_filename}.md', 'w') as f:
        # Write the total count of all events to the output file
        f.write(f"Total count of all events: {total_count:,}\n\n".replace(",", ".")) 

        # Write the table headers
        f.write("| Event | Count |\n")
        f.write("| --- | --- |\n")

        # Write the counts to the output file
        for event, count in sorted_events:
            f.write(f"| {event} | {count:,} |\n".replace(",", "."))
        
    # Plotting
    events, counts = zip(*sorted_events)  # Unpack the sorted events and counts
    plt.figure(figsize=(35, 30))  # Adjust the figure size to better fit the horizontal plot
    bars = plt.barh(events, counts, color='blue')  # Use barh instead of bar for a horizontal plot
    
    # Labeling the bars with their counts
    max_count = max(counts)
    for bar in bars:
        xval = bar.get_width()
        plt.text(xval + (0.01 * max_count), bar.get_y() + bar.get_height()/2, f"{xval:,}".replace(",", "."), va='center')
    
    plt.ylabel('Events')
    plt.xlabel('Count')
    plt.title(f'Event Count (Total events: {total_count:,})'.replace(",", "."))
    plt.yticks(fontsize='small')  # Adjust font size for readability

    # Adjust left margin
    plt.subplots_adjust(left=0.4)

    # Set x axis length
    plt.xlim([0, max(counts)*1.2])  # Increase the x-axis limit to accommodate the moved text

    # Format x-axis labels with a period every third digit from the right
    plt.gca().xaxis.set_major_formatter(ticker.FuncFormatter(lambda x, pos: f'{x:,.0f}'.replace(",", ".")))

    # Set y axis limits to range of data
    plt.ylim([-0.5, len(events)-0.5])  # Adjust the ylim parameters

    # Save the figure
    plt.savefig(f'events_{base_filename}.png', bbox_inches='tight')

# Get the input file name from the command-line arguments
input_filename = sys.argv[1]

# Call the function with the input file name
count_events(input_filename)
