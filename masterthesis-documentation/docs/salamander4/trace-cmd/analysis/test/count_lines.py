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
file_path = 'kvm_exit_log.txt'  # replace with your file path
total_lines = sum(1 for line in open(file_path))
print(f"Total lines: {total_lines}.")

words = ['APIC_WRITE', 
         'EXTERNAL_INTERRUPT', 
         'HLT', 
         'EPT_MISCONFIG',
         'PREEMPTION_TIMER',
         'PAUSE_INSTRUCTION',
         'EPT_VIOLATION',
         'IO_INSTRUCTION',
         'EOI_INDUCED',
         'MSR_READ',
         'CPUID'    
         ]  # replace with the words you want to search for

word_counts = []
for word in words:
    total_lines, word_lines = count_lines_with_word(file_path, word, total_lines)
    print(f"The word '{word}' appears in {word_lines} lines.")
    print(f"Remaining lines: {total_lines}.")
    word_counts.append(word_lines)

# Set the figure size
plt.figure(figsize=(10, 6))

# Plotting
bars = plt.bar(words, word_counts)

# Labeling the bars with their counts
for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 0.05, yval, ha='center', va='bottom')

plt.xlabel('Reasons')
plt.ylabel('Count')
plt.title('Word Counts in File')
plt.xticks(rotation=90, fontsize='small')  # Adjust font size for readability

# Adjust bottom margin
plt.subplots_adjust(bottom=0.4)  # Increase the bottom margin

# Set x and y axis lengths
#plt.xlim([0, len(words)])  # Set x-axis length
plt.ylim([0, max(word_counts)*1.2])  # Set y-axis length

plt.show()

