#!/usr/bin/python3

import sys
from collections import Counter

n = int(sys.stdin.readline())
a = tuple(map(int, (sys.stdin.readline() for _ in range(n))))
cnt = Counter(a)

r = 0

for i in range(n):
    r += cnt[a[i] * a[i]]
    for j in range(i):
        r += cnt[a[i] * a[j]] << 1

print(r)
