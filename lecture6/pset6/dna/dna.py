import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = sys.argv[1]
    seq_file = sys.argv[2]

    people = get_people_dict(database)
    strs = get_strs(database)
    sequence = get_sequence(seq_file)

    compare_people = get_people_dict(database)
    for i, element in enumerate(compare_people):
        compare_people[i].pop("name")

    print(people)
    print(strs)
    print(sequence)
    
#     for i, element in enumerate(people):
#         print(people[i].pop(strs[0]))

    print()

    # TODO: Read DNA sequence file into a variable


    # TODO: Find longest match of each STR in DNA sequence

    print(longest_match(sequence, 'AGATC'))
    print(longest_match(sequence, 'AATG'))
    print(longest_match(sequence, 'TATC'))
    print()


    suspect = get_suspect_str(sequence, strs)
    print(people[1])
    print(suspect)
    print()
    print()
    print()
    print(suspect)
    print(compare_people[1])
    print(people)
    print()
    print()
#     for i, element in enumerate(strs):
#         suspect.update({strs[i]: str(longest_match(sequence, strs[i]))})
#         print(longest_match(sequence, strs[i]))
#     print()
#     print(suspect)
#     people[1].pop("name")
#     print(people[1])
#     if people[1] == suspect:
#         print("sim")
#     else:
#         print("não")






#     for i, element in enumerate(people):
#         if suspect == people[i]

    

    # TODO: Check database for matching profiles

    return

def get_suspect_str(sequence, strs):
    suspect = {}
    for i, element in enumerate(strs):
        suspect.update({strs[i]: str(longest_match(sequence, strs[i]))})
    return suspect

    # nesse aqui recebe por exemplo o arquivo e AATG e ai fala quantas vezes
    # aparece o AATG no "arquivo" de sequencia


def get_sequence(seq_file):
    with open(seq_file) as file:
        sequence = file.read()
    return sequence


def get_people_dict(filename):
    people = {}
    with open(filename) as file:
        reader = csv.DictReader(file)
        for counter, row in enumerate(reader):
            people.update({counter: row})
        return people


def get_strs(filename):
    with open(filename) as file:
        reader = csv.DictReader(file)
        STRs = dict(list(reader)[0])
        STRs = list(STRs.keys())
        STRs.remove('name')
    return STRs


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
