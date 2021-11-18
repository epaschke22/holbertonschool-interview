#!/usr/bin/python3
"""Rain"""


def rain(walls):
    """Returns how much water is filled in a cross section of walls when it rains"""
    n = len(walls)
    if n == 0 or walls is None:
        return 0
    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    water = 0
    for i in range(0, n):
        water += min(left[i], right[i]) - walls[i]
    return water
