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

            # Split the line into parts by colon
            parts = line.split(":")

            # If there are not enough parts, skip this line
            if len(parts) < 3:
                continue

            # The event is the text after the second colon and before the next space
            event = parts[2].split()[0]

            # Update the count for this event
            event_counts[event] += 1

            # Update the total count of all events
            total_count += 1

# Get the input file name from the command-line arguments
input_filename = sys.argv[1]

# Call the function with the input file name
count_events(input_filename)
