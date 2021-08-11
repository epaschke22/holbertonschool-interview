#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """return # of operations to copypaste 1 character to have n ammount"""
    output = 0
    i = 2
    while n > 1:
        while n % i == 0:
            output += i
            n /= i
        i += 1
    return output
