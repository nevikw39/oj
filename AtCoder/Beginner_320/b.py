s = input()
l = len(s)
r = 0
for i in range(l):
    for j in range(l - i):
        ss = s[i:i + j + 1]
        if ss == ss[::-1]:
            r = max(r, j + 1)
print(r)
