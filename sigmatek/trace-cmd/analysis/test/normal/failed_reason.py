import sys
import re
from collections import defaultdict, Counter

def count_events(file_name, search_string):
    with open(file_name, 'r') as f:
        lines = f.readlines()

    # Regular expression pattern for the expected line format
    pattern = re.compile(r'.*\[(\d+)\].*:\s+(\S+):.*' + re.escape(search_string) + r'.*')

    # Extract CPU numbers and event names from lines that contain the search string
    events = [(pattern.match(line).group(1), pattern.match(line).group(2)) for line in lines if search_string in line and pattern.match(line)]

    # Group events by CPU number and count the occurrences of each event
    event_counts = defaultdict(Counter)
    for cpu, event in events:
        event_counts[cpu][event] += 1

    total_count = sum(sum(counter.values()) for counter in event_counts.values())
    print(f'Search string: {search_string}, Total Count: {total_count}\n')
    for cpu, counter in sorted(event_counts.items()):
        print(f'[{cpu}]')
        for event, count in counter.items():
            print(f'Event: {event.rstrip(":")}, Count: {count}')

# Call the function with your file path and search string
count_events('host_guest_merged.txt', 'FAILED')
