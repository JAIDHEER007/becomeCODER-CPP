import sys
import os

sys.path.append(os.path.join(sys.path[0], ".."))

from isUglyNumber import isUgly

def nthUglyNumber(n: int) -> int:
    count, i = n, 1

    while count != 0:
        if isUgly(i):
            count -= 1
        i += 1
    
    return (i - 1)

if __name__ == '__main__':
    n = int(input())

    print("nth Ugly Number is", nthUglyNumber(n))