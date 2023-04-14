#!/usr/bin/python3

"""
    Given a number n, returns the fewest number of operations needed to result in exactly n H characters in the file.
    """


def minOperations(n):
    """
    Given a number n, returns the fewest number of operations needed to result in exactly n H characters in the file.
    """
    if n <= 0:
        return 0

    count = 0
    i = 2

    while n > 1:
        if n % i == 0:
            # If i is a factor of n, divide n by i and add i to the count
            n //= i
            count += i
        else:
            # If i is not a factor of n, increment i
            i += 1

    return count


# def minOperations(n):
#     # Validate input
#     if not isinstance(n, int) or n <= 0:
#         return 0

#     file_contents = ["H"]
#     count = 0

#     # Loop until the file contains n characters
#     while len(file_contents) < n:
#         # Paste the copied contents 2x if possible, else paste once
#         if (n - len(file_contents)) % len(file_contents) == 0:
#             count += 1
#             file_contents.extend(file_contents)
#         else:
#             count += 2
#             file_contents.extend(file_contents[: (n - len(file_contents))])

#     return count
