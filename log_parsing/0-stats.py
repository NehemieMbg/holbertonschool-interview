#!/usr/bin/python3
"""
Module that reads stdin and computes metrics
if stdin matches the pattern
"""


import sys


total_size = 0
counter = 0
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count_status = {'200': 0, '301': 0,
                '400': 0, '401': 0,
                '403': 0, '404': 0,
                '405': 0, '500': 0}

try:
    for lines in sys.stdin:
        line = lines.split(" ")

        if len(line) > 2:
            size = line[-1]
            code = line[-2]
            if code in count_status:
                count_status[code] += 1
            total_size += int(size)
            counter += 1

            if counter == 10:
                print("File size: {:d}".format(total_size))
                for k, v in sorted(count_status.items()):
                    if v != 0:
                        print("{:s}: {:d}".format(k, v))
                counter -= 10

except Exception:
    pass
finally:
    print("File size: {:d}".format(total_size))
    for k, v in sorted(count_status.items()):
        if v != 0:
            print("{:s}: {:d}".format(k, v))
