import os
import sys
import json

def compare_files(file1, file2):
    # Get the base names of the files
    file1_basename = os.path.basename(file1)
    file2_basename = os.path.basename(file2)

    # Create the output file name
    output_file = f"{file1_basename}_VS_{file2_basename}.json"

    # Read the lines from the first file
    with open(file1, 'r') as f1:
        lines1 = set(line.strip() for line in f1)

    # Read the lines from the second file
    with open(file2, 'r') as f2:
        lines2 = set(line.strip() for line in f2)

    # Find the lines common to both files
    common_lines = list(lines1 & lines2)

    # Find the lines only in the first file
    lines_only_in_file1 = list(lines1 - lines2)

    # Find the lines only in the second file
    lines_only_in_file2 = list(lines2 - lines1)

    # Prepare the results in a dictionary
    results = {
        "total common lines": len(common_lines),
        f"both in {file1_basename} and {file2_basename}": common_lines,
        f"count only in {file1_basename}": len(lines_only_in_file1),
        f"only in {file1_basename}": lines_only_in_file1,
        f"count only in {file2_basename}": len(lines_only_in_file2),
        f"only in {file2_basename}": lines_only_in_file2
    }

    # Write the results to the output file in JSON format
    with open(output_file, 'w') as out:
        json.dump(results, out, indent=4)

    print(f"Comparison results have been written to {output_file}")

if __name__ == "__main__":
    # Check if the script received the correct number of arguments
    if len(sys.argv) != 3:
        print("Usage: python script.py <file1> <file2>")
        sys.exit(1)

    # Call the function with the file names passed as command-line arguments
    compare_files(sys.argv[1], sys.argv[2])
