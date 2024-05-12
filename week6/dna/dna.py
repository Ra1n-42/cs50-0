import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py [database file] [sequence file]")
        return

    # Read database file into a variable
    DATABASE = []
    with open(sys.argv[1], newline='') as csvfile:
        database = csv.DictReader(csvfile)
        for row in database:
            DATABASE.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for key in DATABASE[0].keys():
        if key != 'name':
            str_counts[key] = longest_match(sequence, key)

    # Check database for matching profiles
    match_found = False
    for person in DATABASE:
        match = True
        for key, value in person.items():
            if key != 'name' and int(value) != str_counts[key]:
                match = False
                break
        if match:
            print(f"Match found: {person['name']}")
            match_found = True

    if not match_found:
        print("No match found")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
