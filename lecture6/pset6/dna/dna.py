import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # take argv from user prompt
    database = sys.argv[1]
    seq_file = sys.argv[2]

    # Read database file into a variable
    people = get_people_dict(database)
    strs = get_strs(database)

    compare_people = get_people_dict(database)
    for i, _ in enumerate(compare_people):
        compare_people[i].pop("name")

    # Read DNA sequence file into a variable
    sequence = get_sequence(seq_file)

    # Find longest match of each STR in DNA sequence
    suspect = get_suspect_str(sequence, strs)

    # Check database for matching profiles
    if check_suspect(suspect, compare_people):
        print(f"{people[suspect_index]['name']}")
    else:
        print("No match")


def check_suspect(suspect, compare_people):
    for i, _ in enumerate(compare_people):
        if suspect == compare_people[i]:
            global suspect_index
            suspect_index = i
#             print(f"é o home {people[i]['name']}")
            return True
    return False


def get_suspect_str(sequence, strs):
    suspect = {}
    for i, _ in enumerate(strs):
        suspect.update({strs[i]: str(longest_match(sequence, strs[i]))})
    return suspect

    # nesse aqui recebe por exemplo o arquivo e AATG e ai fala quantas vezes
    # aparece o AATG no "arquivo" de sequencia


def get_sequence(seq_file):
    with open(seq_file, 'r', encoding='utf-8') as file:
        sequence = file.read()
    return sequence


def get_people_dict(filename):
    people = {}
    with open(filename, 'r', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for counter, row in enumerate(reader):
            people.update({counter: row})
        return people


def get_strs(filename):
    with open(filename, 'r', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        strs = dict(list(reader)[0])
        strs = list(strs.keys())
        strs.remove('name')
    return strs


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence # noqa: E501
        # If a match, move substring to next potential match in sequence # noqa: E501
        # Continue moving substring and checking for matches until out of consecutive matches # noqa: E501
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found # noqa: E501
    return longest_run


main()
