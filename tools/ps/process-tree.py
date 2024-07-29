import psutil

def print_process_tree(pid):
    # Create a list to store the process information
    processes = []

    def helper(pid):
        try:
            process = psutil.Process(pid)
            # Add process information to the list
            processes.append([process.pid, process.name(), process.ppid()])
            children = process.children()
            for child in children:
                helper(child.pid)
        except psutil.NoSuchProcess:
            pass

    helper(pid)

    # Sort the processes by PID
    processes.sort(key=lambda x: x[0])

    # Write the table to a .md file
    with open("process-tree.md", "w") as f:
        f.write("| PID | Process Name | PPID |\n")
        f.write("| --- | --- | --- |\n")
        for process in processes:
            f.write(f"| {process[0]} | {process[1]} | {process[2]} |\n")

# Start with the root process
print_process_tree(1)

# Print a success message
print("The process tree is successfully saved to process_tree.md file.")

