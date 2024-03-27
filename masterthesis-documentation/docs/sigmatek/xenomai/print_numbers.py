# Open the file in write mode
with open("print_numbers.txt", "w") as file:
    # Write numbers from 1 to 600
    for number in range(1, 601):
        file.write(str(number) + "\n")

# Print a success message
print("The numbers from 1 to 600 are successfully saved to numbers.txt file.")

