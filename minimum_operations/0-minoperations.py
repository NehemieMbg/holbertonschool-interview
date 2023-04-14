#!/usr/bin/python3

"""
    Given a number n, returns the fewest number of operations needed to result in exactly n H characters in the file.
    """


def minOperations(n):
    # Validate input
    if not isinstance(n, int) or n <= 0:
        return 0

    file_contents = ["H"]
    count = 0

    # Loop until the file contains n characters
    while len(file_contents) < n:
        # Paste the copied contents 2x if possible, else paste once
        if (n - len(file_contents)) % len(file_contents) == 0:
            count += 1
            file_contents.extend(file_contents)
        else:
            count += 2
            file_contents.extend(file_contents[: (n - len(file_contents))])

    return count
