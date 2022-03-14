#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """returns a list of lists based on the triangle"""
    if n <= 0:
        return []
    result = []
    lastrow = []
    for forrow in range(1, n + 1):
        listrow = []
        for num in range(forrow):
            if num == 0:
                listrow.append(1)
            elif forrow > 2:
                try:
                    listrow.append(lastrow[num - 1] + lastrow[num])
                except:
                    listrow.append(1)
            else:
                listrow.append(1)
        lastrow[:] = listrow
        result.append(listrow)
    return result
