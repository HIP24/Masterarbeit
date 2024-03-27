import matplotlib.pyplot as plt

def count_lines_with_word(file_path, word, total_lines):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    count = 0
    for line in lines:
        if word in line:
            count += 1

    total_lines -= count
    return total_lines, count

# Usage
file_path = 'kvm_exit_default_log.txt'  # replace with your file path
total_lines = sum(1 for line in open(file_path))
print(f"Total exits: {total_lines}.")

words = ['APIC_WRITE', 
         'HLT', 
         'EPT_MISCONFIG',
         'PREEMPTION_TIMER',
         'EXTERNAL_INTERRUPT', 
         'IO_INSTRUCTION',
         'EOI_INDUCED',
         'EPT_VIOLATION',
         'PAUSE_INSTRUCTION',
         'CPUID',   
         'MSR_READ'
         ]  # replace with the words you want to search for

counts = []
for word in words:
    total_lines, word_lines = count_lines_with_word(file_path, word, total_lines)
    print(f"'{word}': {word_lines} times")
    counts.append((word, word_lines))

# Sort words and counts by count in descending order
counts.sort(key=lambda x: x[1], reverse=True)
words, word_counts = zip(*counts)  # unzip the sorted pairs

# Set the figure size
plt.figure(figsize=(10, 6))

# Plotting
bars = plt.bar(words, word_counts, color='blue')  # Added color='blue'

# Labeling the bars with their counts
for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 0.05, yval, ha='center', va='bottom')

plt.xlabel('Reasons')
plt.ylabel('Count')
plt.title('Exit Reason Count')
plt.xticks(rotation=90, fontsize='small')  # Adjust font size for readability

# Adjust bottom margin
plt.subplots_adjust(bottom=0.4)  # Increase the bottom margin

# Set x and y axis lengths
#plt.xlim([0, len(words)])  # Set x-axis length
plt.ylim([0, max(word_counts)*1.2])  # Set y-axis length

# Save the figure
plt.savefig('../../../../../../../img/kvm_exits_default.png', bbox_inches='tight')
plt.savefig('kvm_exits_default.png', bbox_inches='tight')

# Print a success message
print("The plot was successfully saved to kvm_exits_default.png")
