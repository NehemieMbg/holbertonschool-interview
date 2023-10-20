#!/usr/bin/python3
"""
Module which returns the perimeter of an Island
"""


def island_perimeter(grid):
    """
    function to compute the perimeter
    of the island represented in grid where
    0 -> water ; 1 -> land
    """
    island = 0
    neighbor = 0

    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if grid[y][x] == 1:
                island += 1
                # neighbor to the right ?
                if x < len(grid[y]) - 1 and grid[y][x + 1] == 1:
                    neighbor += 1
                # neighbor to the bottom ?
                if y < len(grid) - 1 and grid[y + 1][x] == 1:
                    neighbor += 1
    # heck imagine only '1' cell found, bim times 4 - 2 * 0
    # Moreover => Each land cell '1' contributes to -> 4 units of perimeter
    # BUT => if it has adjacent land, it shares 2 units with that neighbor
    # hence => 4 * island - 2 * neighbor to adjust the shared perimeters cells
    return island * 4 - 2 * neighbor
