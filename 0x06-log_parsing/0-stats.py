#!/usr/bin/python3
import sys


def printvalues(stats, size):
    statarr = ["200", "301", "400", "401", "403", "404", "405", "500"]
    print("File size: {}".format(size))
    for i in range(len(statarr)):
        if stats[statarr[i]] > 0:
            print("{}: {}".format(statarr[i], stats[statarr[i]]))

count = 0
size = 0
statdict = {"200": 0, "301": 0, "400": 0, "401": 0,
            "403": 0, "404": 0, "405": 0, "500": 0}
for line in sys.stdin:
    try:
        count += 1
        linesplit = line.split()
        size += int(linesplit[8])
        status = linesplit[7]
        statdict[status] += 1
        if count == 10:
            count = 0
            printvalues(statdict, size)
    except KeyboardInterrupt:
        printvalues(statdict, size)
printvalues(statdict, size)
