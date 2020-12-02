from csv import reader, DictReader
from sys import argv

# Check the length of argv
if len(argv) < 3:
    print("There was an error!: Usage - dna.py sequence.txt database.csv")
    exit()

# Open sequence file
with open(argv[2]) as dna_file:
    dna_reader = reader(dna_file)
    # Iterate rows
    for row in dna_reader:
        dna_list = row

# Data Stuctures
dna = dna_list[0]
sequences = {}

# Extract from CSV file and add to the dna list
with open(argv[1]) as persons_file:
    persons = reader(persons_file)
    for row in persons:
        dna_seq = row
        dna_seq.pop(0)
        break

for item in dna_seq:
    sequences[item] = 1

# Count STRs
for key in sequences:
    l = len(key)
    max = 0 
    tmp = 0
    for i in range(len(dna)):
        # End loop
        while tmp > 0:
            tmp -= 1
            continue

        # if seq and key are equal begin count
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                tmp += 1
                i += l

            # Compare to the last longest seq 
            if tmp > max:
                max = tmp
    # Store in dictionary
    sequences[key] += max

# Open database
with open(argv[1], newline='') as persons_file:
    persons = DictReader(persons_file)
    for person in persons:
        result = 0
        
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                result += 1
        if result == len(sequences):
            print(person['name'])
            exit()

    print("No match")