#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """UTF-8 hasa lot of rules"""
    length = len(data)
    if length == 1:
        if data[0] < 128:
            return True
        else:
            return False
    checkahead = 0
    for char in data:
        if char > 256:
            char -= 256
        if checkahead > 0:
            if char < 128 or char >= 192:
                return False
            checkahead -= 1
            continue
        if char >= 128 and char < 192:
            return False
        if char >= 192 and char < 224:
            checkahead = 1
        if char >= 224 and char < 240:
            checkahead = 2
        if char >= 240 and char < 248:
            checkahead = 3
        if char >= 248:
            return False
    if checkahead > 0:
        return False
    return True
