#!/usr/bin/python3

from collections import defaultdict
from sys import stdin, stdout, stderr


def solve():
    h, v, p, n = defaultdict(lambda: 0), defaultdict(lambda: 0), defaultdict(lambda: 0), defaultdict(lambda: 0)
    for _ in range(int(stdin.readline())):
        x, y = map(int, stdin.readline().split())
        h[x] += 1
        v[y] += 1
        p[x + y] += 1
        n[x - y] += 1
    r = 0
    for i in h.values():
        r += i * (i - 1)
    for i in v.values():
        r += i * (i - 1)
    for i in p.values():
        r += i * (i - 1)
    for i in n.values():
        r += i * (i - 1)
    stdout.write(f"{r}\n")

if __name__ == "__main__":
    for _ in range(int(stdin.readline())):
        solve()
