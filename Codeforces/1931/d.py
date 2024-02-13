#!/home/nevikw/miniconda3/bin/python3

from random import getrandbits
from collections import defaultdict


class Int(int):
    RANDOM = getrandbits(64)

    def __init__(self, x):
        int.__init__(x)

    def __hash__(self):
        return super(Int, self).__hash__() ^ Int.RANDOM


def solve():
    n, x, y = map(Int, input().split())
    r = 0
    s = defaultdict(set)
    for i, e in enumerate(map(Int, input().split())):
        r += len(s[(-e % x, e % y)])
        s[(e % x, e % y)].add(i)
    print(r)


if __name__ == "__main__":
    for _ in range(t := int(input())):
        solve()
