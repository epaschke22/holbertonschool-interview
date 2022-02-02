#!/usr/bin/python3
""" Making change """


def makeChange(coins, total):
    """coins: list of value of the coins, total: value to calculate"""
    if total <= 0:
        return 0
    matrix = [[0 for m in range(total + 1)] for m in range(len(coins) + 1)]
    for i in range(total + 1):
        matrix[0][i] = i

    for coin in range(1, len(coins) + 1):
        for row in range(1, total + 1):
            if coins[coin - 1] == row:
                matrix[coin][row] = 1
            elif coins[coin - 1] > row:
                matrix[coin][row] = matrix[coin - 1][row]
            else:
                matrix[coin][row] = min(matrix[coin - 1][row], 1 +
                                        matrix[coin][row - coins[coin - 1]])
    return matrix[-1][-1]
