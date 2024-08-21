def remove_duplicates(file_path):
    # Open the file in read mode and read all lines
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Reverse the lines to keep the last occurrence and remove previous duplicates
    lines.reverse()

    # Remove duplicate lines
    unique_lines = list(dict.fromkeys(lines))

    # Reverse the lines back to original order
    unique_lines.reverse()

    # Open the file in write mode and write the unique lines
    with open(file_path, 'w') as file:
        file.writelines(unique_lines)

# Call the function with the path to your file
remove_duplicates('.bash_history')

# Print a success message
print("Duplicates in .bash_history removed.")

