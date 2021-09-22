#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """a character in UTF-8 can be 1 to 4 bytes long"""
    for char in data:
        if char > 255:
            return False
    return True
