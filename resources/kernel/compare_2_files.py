def compare_files(file1, file2, output_file):
    # Read the lines from the first file
    with open(file1, 'r') as f1:
        lines1 = set(line.strip() for line in f1)

    # Read the lines from the second file
    with open(file2, 'r') as f2:
        lines2 = set(line.strip() for line in f2)

    # Find the lines common to both files
    common_lines = lines1 & lines2

    # Find the lines only in the first file
    lines_only_in_file1 = lines1 - lines2

    # Find the lines only in the second file
    lines_only_in_file2 = lines2 - lines1

    # Write the results to the output file
    with open(output_file, 'w') as out:
        out.write("Lines both files have in common:\n")
        for line in common_lines:
            out.write(line + "\n")

        out.write("\n" + "#"*90 + "\n" + "#"*90 + "\n" + "#"*90 + "\n")
        out.write("Lines only " + file1 + " has:\n")
        for line in lines_only_in_file1:
            out.write(line + "\n")

        out.write("\n" + "#"*90 + "\n" + "#"*90 + "\n" + "#"*90 + "\n")
        out.write("Lines only " + file2 + " has:\n")
        for line in lines_only_in_file2:
            out.write(line + "\n")

    print(f"Comparison results have been written to {output_file}")

# Call the function with the file names
compare_files("6.5.0", "6.8.0", "output_comparison.txt")
