#!/usr/bin/python3
"""Lockboxes"""
import sys


def canUnlockAll(boxes):
    """boxes is a list of lists"""
    sys.setrecursionlimit(10000)
    if len(boxes) == 0 or boxes is None:
        return False
    openboxes = [False] * len(boxes)
    openboxes[0] = True
    recursion(boxes[0], boxes, openboxes)
    for box in openboxes:
        if box is False:
            return False
    return True


def recursion(boxindex, boxes, openboxes):
    for key in boxindex:
        if openboxes[key] is False and key < len(boxes):
            openboxes[key] = True
            recursion(boxes[key], boxes, openboxes)
