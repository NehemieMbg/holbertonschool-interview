#!/usr/bin/python3
"""
Module that computes units of water retained
"""


def rain(walls):
    if not len(walls):
        return 0
    left, right = 0, len(walls) - 1
    lmax, rmax = walls[left], walls[right]
    water = 0
    while left < right:
        lmax = max(lmax, walls[left])
        rmax = max(rmax, walls[right])
        if lmax < rmax:
            water += lmax - walls[left]
            left += 1
        else:
            water += rmax - walls[right]
            right -= 1
    return water


if __name__ == "__main__":
    walls = [0, 4, 0, 0, 3, 0, 0, 5]
    print(rain(walls))
