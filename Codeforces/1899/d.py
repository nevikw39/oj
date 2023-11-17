from math import log2
from random import getrandbits


class Int(int):
    RANDOM = getrandbits(64)
    def __init__(self, x):
        int.__init__(x)
    def __hash__(self):
        return super(Int, self).__hash__() ^ Int.RANDOM

def solve():
    n = input()
    a = list(map(Int, input().split()))
    d = dict()
    dd = dict()
    for i in a:
        x = log2(i)
        if x.is_integer():
            if Int(x) in d:
                d[Int(x)] += 1
            else:
                d[Int(x)] = 1
        if i in dd:
            dd[i] += 1
        else:
            dd[i] = 1
    r = 0
    for i in d:
        for j in d:
            if i != j and (2 ** i) * (2 ** (2 ** j)) == (2 ** j) * (2 ** (2 ** i)):
                r += d[i] * d[j]
    for i in dd.values():
        r += i * (i - 1)
    print(r // 2)


for _ in range(Int(input())):
    solve()
