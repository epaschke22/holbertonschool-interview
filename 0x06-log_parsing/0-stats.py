#!/usr/bin/python3
import sys

count = 0
size = 0
statarr = ["200", "301", "400", "401", "403", "404", "405", "500"]
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
            print("File size: {}".format(size))
            for i in range(len(statarr)):
                if statdict[statarr[i]] > 0:
                    print("{}: {}".format(statarr[i], statdict[statarr[i]]))
            statdict = {"200": 0, "301": 0, "400": 0, "401": 0,
                        "403": 0, "404": 0, "405": 0, "500": 0}
    except KeyboardInterrupt:
        print("File size: {}".format(size))
        for i in range(len(statarr)):
            if statdict[statarr[i]] > 0:
                print("{}: {}".format(statarr[i], statdict[statarr[i]]))
        statdict = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
print("File size: {}".format(size))
for i in range(len(statarr)):
    if statdict[statarr[i]] > 0:
        print("{}: {}".format(statarr[i], statdict[statarr[i]]))
statdict = {"200": 0, "301": 0, "400": 0, "401": 0,
            "403": 0, "404": 0, "405": 0, "500": 0}
