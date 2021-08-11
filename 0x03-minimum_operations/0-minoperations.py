#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """return # of operations to copypaste 1 character to have n ammount"""
    if n < 1:
        return 0
    output = 0
    for i in range(2, n + 1):
        while n % i == 0:
            output += i
            n = n / i
    return output
