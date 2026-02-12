n = int(input())
h = (0,) + tuple(map(int, input().split()))
print(max(h) - min(h) << 1)
