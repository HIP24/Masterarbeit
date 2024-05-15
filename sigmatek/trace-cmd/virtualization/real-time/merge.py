import sys
import re

def merge_files(file_a, file_b, output_file):
    with open(file_a, 'r') as fa, open(file_b, 'r') as fb:
        lines_a = fa.readlines()
        lines_b = fb.readlines()

    # Regular expression pattern for the expected line format
    pattern = re.compile(r'.*\[\d+\]\s+(\d+\.\d+):.*')

    # Filter out lines that do not match the expected format
    lines_a = [line for line in lines_a if pattern.match(line)]
    lines_b = [line for line in lines_b if pattern.match(line)]

    # Extract timestamps and sort lines from both files
    lines = sorted(lines_a + lines_b, key=lambda line: float(pattern.match(line).group(1)))

    with open(output_file, 'w') as fo:
        for line in lines:
            fo.write(line)

# Call the function with your file paths
merge_files('host_report.txt', 'guest_report.txt', 'host_guest_merged.txt')
