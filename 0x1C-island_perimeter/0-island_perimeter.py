#!/usr/bin/python3
"""ilsand perimeter counting"""


def island_perimeter(grid):
    """counts +4 for each 1 found, -1 for each adjacent 1"""
    perimeter = 0
    for y in range(0, len(grid)):
        for x in range(0, len(grid[y])):
            if grid[y][x] == 1:
                perimeter += 4
                if x != len(grid[y]) - 1:
                    if grid[y][x + 1] == 1:
                        perimeter -= 1
                if x != 0:
                    if grid[y][x - 1] == 1:
                        perimeter -= 1
                if y != len(grid) - 1:
                    if grid[y + 1][x] == 1:
                        perimeter -= 1
                if y != 0:
                    if grid[y - 1][x] == 1:
                        perimeter -= 1
    return perimeter
