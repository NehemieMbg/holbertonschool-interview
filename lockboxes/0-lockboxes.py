#!/usr/bin/python3

"""
    Check if boxes can be opened with previous opened boxes
"""
def canUnlockAll(boxes):

    keys = [0]
    boxesOpened = {0: True}

    while keys:
        boxIndex = keys.pop()
        for key in boxes[boxIndex]:
            if key < len(boxes) and not boxesOpened.get(key):
                boxesOpened[key] = True
                keys.append(key)

    return len(boxesOpened) == len(boxes)
