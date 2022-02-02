#!/usr/bin/python3
""" Making change """


def makeChange(coins, total):
    """coins: list of value of the coins, total: value to calculate"""
    if total <= 0:
        return 0
    if total in coins:
        return 1
    coinAmount = 0
    currentCoin = 0
    coins = reversed(sorted(coins))

    for coin in coins:
        while currentCoin + coin <= total:
            coinAmount += 1
            currentCoin += coin
    if currentCoin != total:
        return -1
    return coinAmount
