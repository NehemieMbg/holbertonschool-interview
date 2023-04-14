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
        # Copy the current file contents
        file_contents_copy = file_contents.copy()

        # Paste the copied contents 2x if possible, else paste once
        if len(file_contents) + 2 <= n:
            count += 3
            file_contents.extend(file_contents_copy)
            file_contents.extend(file_contents_copy)
        else:
            count += 2
            file_contents.extend(file_contents_copy)

    return count
