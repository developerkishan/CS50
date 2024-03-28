import csv
import sys


def main():

    # TODO: Check for command-line usage
    if(len(sys.argv)==3):
        file_name_csv_file = sys.argv[1]
        file_name_text_file = sys.argv[2]
    else:
        print("Invalid arguments")
        sys.exit()

    # TODO: Read database file into a variable

    rows = []
    with open(file_name_csv_file) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
            print(row)





    # TODO: Read DNA sequence file into a variable
    dna_sequence= ""
    with open(file_name_text_file) as file:
        dna_sequence = file.read()
        print(dna_sequence)

    # TODO: Find longest match of each STR in DNA sequence


    strs = {
        "AGATC" : 0,
        "AATG" : 0,
        "TATC" : 0,
    }
    for str in strs:
        strs[str]=longest_match(dna_sequence,str)
    for row in rows:
        counter= 0
        for str in strs:
            if(int(strs[str]) == int(row[str])):
                counter+=1
        if(counter==3):
            print(row["name"])
            return
    print("No Match")
    return


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

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
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

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
