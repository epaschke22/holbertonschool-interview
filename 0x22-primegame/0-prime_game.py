#!/usr/bin/python3
"""Prime Game"""


def roundWinner(n):
    """determines the winner of the round"""
    turn = 0
    for i in range(1, n + 1):
        if i in [1, 2, 3] or i % 6 == 1 or i % 6 == 5:
            turn += 1
    return 1 if turn % 2 == 1 else -1


def isWinner(x, nums):
    """Maria and Ben take turns choosing prime numbers"""
    winner = 0
    for i in range(x):
        winner += roundWinner(nums[i])
    return None if winner == 0 else "Ben" if winner > 0 else "Maria"
