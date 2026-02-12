n, t = map(int, input().split())
s = 0
for i in range(n):
  a, b = map(int, input().split())
  s += max(a - b * t, 0)
print(s)
