import re

def process_bib_file(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    with open(output_file, 'w') as file:
        entry_type = None
        for line in lines:
            if line.startswith('@'):
                entry_type = line.split('{')[0].strip()
            if entry_type != '@misc' and 'urldate' in line:
                continue
            file.write(line)

input_file = '../literature/Literature.bib'
output_file = '../literature/Literature.bib'
process_bib_file(input_file, output_file)
