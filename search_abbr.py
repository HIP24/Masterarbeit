import re

# Pfad zu deinem .tex-Dokument
file_path = 'Masterarbeit_Robotik_Pamuk.tex'

# Regex-Muster zum Suchen von Wörtern in Klammern
pattern = r'\(\b\w+\b\)'

# Set zum Speichern der gefundenen Wörter (Sets speichern nur eindeutige Elemente)
words_in_brackets = set()

# Datei öffnen und durchsuchen
with open(file_path, 'r', encoding='utf-8') as file:
    for line in file:
        matches = re.findall(pattern, line)
        words_in_brackets.update(matches)

# Gefundene Wörter untereinander aufschreiben
with open('found_abbr.txt', 'w', encoding='utf-8') as output_file:
    for word in sorted(words_in_brackets):
        output_file.write(word + '\n')

print("Words in brackets saved to 'found_abbr.txt' gespeichert.")
