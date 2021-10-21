#!/usr/bin/python3
"""NQueens"""
from sys import argv


def isSafe(board, row, col):
    """checks if queen is safe from other queens"""
    for i in range(row):
        if board[i][col] == 1:
            return False
    (i, j) = (row, col)
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j - 1
    (i, j) = (row, col)
    while i >= 0 and j < len(board):
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j + 1
    return True


def printSolution(board):
    """prints out solution"""
    result = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 1:
                result.append([i, j])
    print(result)


def nQueen(board, row):
    """recersive backtracking"""
    if row == len(board):
        printSolution(board)
        return
    for i in range(len(board)):
        if isSafe(board, row, i):
            board[row][i] = 1
            nQueen(board, row + 1)
            board[row][i] = 0


n = int(argv[1])
board = [[0 for x in range(n)] for y in range(n)]
nQueen(board, 0)
