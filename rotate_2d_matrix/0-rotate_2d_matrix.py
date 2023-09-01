#!/usr/bin/python3

"""
Module that rotate a matrix 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
    rotate your matrix and be clockwise
    """
    n = len(matrix)
    matrix.reverse()
    matrix[:] = [list(row) for row in zip(*matrix)]
