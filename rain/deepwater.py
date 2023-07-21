#!/usr/bin/python3

"""
Using a stack method
"""


def rain(walls):
    """
    walls : a list of non-negative integers
    Return: Integer indicating total amount of rainwater
    trapped by the slices of walls
    """
    stack = []
    water = 0
    n = len(walls)

    for i in range(n):
        while stack and walls[i] > walls[stack[-1]]:
            top = stack.pop()
            if stack:
                left = walls[stack[-1]]
                right = walls[i]
                water += (min(right, left) - walls[top]) * (i - stack[-1] - 1)
        stack.append(i)

    return water
