import matplotlib.pyplot as plt
import sys  # Import the sys module
import os  # Import the os module

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
file_path = sys.argv[1]  # Get the file path from command line argument
total_lines = sum(1 for line in open(file_path))
total = total_lines

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
         'MSR_READ',
         'MSR_WRITE'
         ]

counts = []
for word in words:
    total_lines, word_lines = count_lines_with_word(file_path, word, total_lines)
    counts.append((word, word_lines))

counts.sort(key=lambda x: x[1], reverse=True)
words, word_counts = zip(*counts)

plt.figure(figsize=(10, 6))
bars = plt.bar(words, word_counts, color='blue')

for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 0.05, yval, ha='center', va='bottom')

plt.xlabel('Reasons')
plt.ylabel('Count')
plt.title(f'Exit Reason Count (Total exits: {total})')
plt.xticks(rotation=90, fontsize='small')
plt.subplots_adjust(bottom=0.4)
plt.ylim([0, max(word_counts)*1.2])

# Save the figure with the input file name (without extension) appended to 'kvm_exit_count_'
filename_without_extension = os.path.splitext(os.path.basename(file_path))[0]
plt.savefig(f'{filename_without_extension}.png', bbox_inches='tight')

