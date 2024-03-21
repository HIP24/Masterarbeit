# The words to search for
search_words = ['trac', 
                'trace',
                'tracing',
                'ftrace',
                'kvm',
                'guest' ]

#search_words = ['clock', 'sync']

# The words to exclude
exclude_words = ['#',
                 'track',
                 'tracking']
#exclude_words = ['#']

# Open the input file and read the lines
with open('config-6.5.0-21-generic', 'r') as f:
    lines = f.readlines()

# Filter the lines that contain any of the search words and do not contain any of the exclude words
filtered_lines = [line for line in lines if any(word in line.lower() for word in search_words) and not any(word in line.lower() for word in exclude_words)]

# Open the output file and write the filtered lines
with open('output.txt', 'w') as f:
    f.writelines(filtered_lines)
