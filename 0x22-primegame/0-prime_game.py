#!/usr/bin/python3
"""Prime Game"""


def isprime(n):
    """determines if a number is prime"""
    if n <= 1:
        return False
    for i in range(2,n):
        if n % i == 0:
            return False
    return True


def roundWinner(n):
    """determines the winner of the round"""
    turn = 0
    set = []
    for i in range(1, n + 1):
        set.append(i)
    i = 2
    while len(set) > 1:
        if (isprime(i)):
            for num in set:
                if num % i == 0:
                    set.remove(num)
            turn += 1
        i += 1
    if turn % 2 == 0:
        return 1
    return -1


def isWinner(x, nums):
    """Maria and Ben take turns choosing prime numbers"""
    winner = 0
    for i in range(x):
        winner += roundWinner(nums[i])
    if winner >= 0:
        return "Ben"
    return "Maria"