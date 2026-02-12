from collections import Counter
from itertools import accumulate

n, k = map(int, input().split())
a = tuple(map(int, input().split()))

ctr = Counter()
ctr[0] = 1
sum = 0

for i in accumulate(a):
    sum += ctr[i - k]
    ctr[i] += 1

print(sum)
