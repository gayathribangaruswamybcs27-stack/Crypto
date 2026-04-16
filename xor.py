#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'xorKey' function below.
#
# The function is expected to return a LONG_INTEGER_ARRAY.
# The function accepts following parameters:
#  1. LONG_INTEGER_ARRAY x
#  2. 2D_LONG_INTEGER_ARRAY queries
#

def xorKey(x, queries):

    # Write your code here
    lst=[]
    for j in queries:
        a,l,r=j
        y=filter(lambda i:l<=i and i<=r,x)
        res=set([a^k for k in y])     
        lst.append(max(res))     
    return lst
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        q = int(first_multiple_input[1])

        x = list(map(int, input().rstrip().split()))

        queries = []

        for _ in range(q):
            queries.append(list(map(int, input().rstrip().split())))

        result = xorKey(x, queries)

        fptr.write('\n'.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
