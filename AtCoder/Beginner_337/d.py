from typing import List


h, w, k = map(int, input().split())
s = tuple(input() for _ in range(h))
r = float("inf")


def f(x: List[str]):
    global r
    for i in x:
        if len(i) >= k:
            cnt = i[:k].count('.')
            r = min(r, cnt)
            for j in range(k, len(i)):
                cnt += (i[j] == '.') - (i[j - k] == '.')
                r = min(r, cnt)


for i in s:
    f(i.split('x'))
for i in tuple(''.join(i) for i in zip(*s)):
    f(i.split('x'))

if r != float("inf"):
    print(r)
else:
    print("-1")
