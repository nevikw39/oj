import sys

t = 1
for line in sys.stdin:
    n, f = map(int, line.split())
    if not n and not f:
        break
    s = 0
    for _ in range(n):
        s += int(input())
    print("Bill #{} costs {}: each friend should pay {}\n".format(t, s, s // f))
    t += 1
