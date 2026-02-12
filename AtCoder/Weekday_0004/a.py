n, s, t = map(int, input().split())
a = sum(map(int, input().split()))
print("Yes" if a <= (t - s) * 60 else "No")
