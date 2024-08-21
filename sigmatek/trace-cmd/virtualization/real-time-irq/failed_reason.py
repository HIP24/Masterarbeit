import sys
import re
from collections import Counter

def count_events(file_name, search_string):
    with open(file_name, 'r') as f:
        lines = f.readlines()

    # Regular expression pattern for the expected line format
    pattern = re.compile(r'.*:\s+(\S+):.*' + re.escape(search_string) + r'.*')

    # Extract event names from lines that contain the search string
    events = [pattern.match(line).group(1) for line in lines if search_string in line and pattern.match(line)]

    # Count the occurrences of each event
    event_counts = Counter(events)
    total_count = sum(event_counts.values())
    print(f'Search string: {search_string}, Total Count: {total_count}\n')
    for event, count in event_counts.items():
        print(f'Event: {event.rstrip(":")}, Count: {count}')

# Call the function with your file path and search string
count_events('host_guest_merged.txt', '[FAILED TO PARSE]')
