#!/usr/bin/python3
"""Prime Game"""
from math import sqrt


def isPrime(n):
    """determines if a number is prime"""
    prime_flag = 0
    if(n > 1):
        for i in range(2, int(sqrt(n)) + 1):
            if (n % i == 0):
                prime_flag = 1
                break
        return True if prime_flag == 0 else False
    else:
        return False


def isWinner(x, nums):
    """Maria and Ben take turns choosing prime numbers"""
    winner = 0
    for round in range(x):
        prime = 1
        for n in range(1, nums[round] + 1):
            if isPrime(n):
                prime += 1
        winner += 1 if prime % 2 == 1 else -1
    return None if winner == 0 else "Ben" if winner > 0 else "Maria"
