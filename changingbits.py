#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'changeBits' function below.
#
# The function accepts following parameters:
#  1. STRING a
#  2. STRING b
#  3. STRING_ARRAY queries
#

def changeBits(a, b, queries):
 
    a, b = int(a, 2), int(b, 2)

    for q in queries:
        q = q.rstrip().split()
        i = int(q[1])
        if q[0] == 'set_a':
            if q[2] == '1':
                a |= 1<<i
            else:
                a &= ~(1<<i)
        elif q[0] == 'set_b':
            if q[2] == '1':
                b |= 1<<i
            else:
                b &= ~(1<<i)
        else:
            c = a + b
            if not c & (1<<i):
                print('0', end="")
            else:
                print('1', end="")

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()

    ab_size = int(first_multiple_input[0])

    queries_size = int(first_multiple_input[1])

    a = input()

    b = input()

    queries = []

    for _ in range(queries_size):
        queries_item = input()
        queries.append(queries_item)

    changeBits(a, b, queries)
