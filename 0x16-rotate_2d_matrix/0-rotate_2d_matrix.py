#!/usr/bin/python3
"""rotates a matrix in-place 90 degrees"""

def rotate_2d_matrix(matrix):
    flipped = list(zip(*matrix[::-1]))
    for tup in range(len(flipped)):
        for num in range(len(flipped[tup])):
            matrix[tup][num] = flipped[tup][num]
