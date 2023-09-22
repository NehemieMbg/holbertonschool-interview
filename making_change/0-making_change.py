#!/usr/bin/python3
"""
Module to determine the fewest number of coins needed to meet a given amount
"""

import sys


def makeChange(coins, total):
    """
    coins: a list of the values of coins we got
    we suppose it infinite mwahaha so rich boy
    total: the total to reach dude
    """
    # hassle
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    coins.sort()

    for i in range(1, total + 1):
        for c in range(len(coins)):
            if i - coins[c] >= 0:
                result = dp[i - coins[c]]
                if result != sys.maxsize:
                    dp[i] = min(dp[i], result + 1)
    return dp[total] if dp[total] != float('inf') else -1
