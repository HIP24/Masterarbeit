import sys
from prettytable import PrettyTable

def parse_file(filename):
    kvm_exits = {}
    total_exits = 0
    with open(filename, 'r') as file:
        lines = file.readlines()
        for line in lines[2:]:  # Skip the first two lines
            parts = line.split()
            exit_reason = parts[2]
            count = int(parts[3])
            total_exits += count
            kvm_exits[exit_reason] = kvm_exits.get(exit_reason, 0) + count
    return kvm_exits, total_exits

def compare_files(file1, file2):
    kvm_exits1, total_exits1 = parse_file(file1)
    kvm_exits2, total_exits2 = parse_file(file2)

    all_exits = set(list(kvm_exits1.keys()) + list(kvm_exits2.keys()))

    unique_exits = []
    common_exits = []

    for exit_reason in sorted(all_exits):
        count1 = kvm_exits1.get(exit_reason, 0)
        count2 = kvm_exits2.get(exit_reason, 0)

        if count1 > 0 and count2 == 0:
            unique_exits.append([exit_reason, f"{count1} vs 0", file1, "Only in " + file1])
        elif count1 == 0 and count2 > 0:
            unique_exits.append([exit_reason, f"0 vs {count2}", file2, "Only in " + file2])
        else:
            if count1 > count2:
                common_exits.append([exit_reason, f"{count1} vs {count2}", file1, count1 - count2])
            elif count1 < count2:
                common_exits.append([exit_reason, f"{count1} vs {count2}", file2, count2 - count1])
            else:
                common_exits.append([exit_reason, f"{count1} vs {count2}", "Both", "Same"])

    table = PrettyTable()
    table.field_names = ["Exit Reason", f"Count ({file1} vs {file2})", "File", "Difference"]

    # Sort unique exits by file name in the order specified
    unique_exits.sort(key=lambda x: (file2 == x[2], x[0]))

    for row in unique_exits + common_exits:
        table.add_row(row)

    print(table)
    print(f"\nTotal exits in {file1}: {total_exits1}")
    print(f"Total exits in {file2}: {total_exits2}")

# Example usage:
if len(sys.argv) != 3:
    print("Usage: python script.py <file1> <file2>")
else:
    compare_files(sys.argv[1], sys.argv[2])
