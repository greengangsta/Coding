import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    fact = []
    fact.append(1)
    fact.append(1)
    for i in range(2,n+1):
        fact.append(i*fact[i-1])
    print(fact[n])

if __name__ == '__main__':
    n = int(input())

    extraLongFactorials(n)
