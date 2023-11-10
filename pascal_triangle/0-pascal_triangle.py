#!/usr/bin/python3
"""
Module that embed the logic for Pascal triangle
"""


def pascal_triangle(n):
    """
    We assume n will always be an integer
    Returns a list of lists of integers
    representing the Pascal's triangle of 'n'
    """
    if n <= 0:
        return []

    pascal = [[1]]
    for i in range(1, n):
        # iterate over the desired number of rows
        # record the previous row for computations
        prev = pascal[-1]
        # new row always start with '1' Pascal said
        new = [1]
        # iterate over the 'length of row'
        for j in range(1, i):
            new.append(prev[j - 1] + prev[j])
        # finish the row with a '1'
        new.append(1)
        pascal.append(new)

    return pascal
