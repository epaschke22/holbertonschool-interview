#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """return # of operations to copypaste 1 character to have n ammount"""
    output = 0
    for i in range(2, n):
        while n % i == 0:
            output += i
            n = n / i
    return output
