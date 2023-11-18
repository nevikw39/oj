n, q = map(int, input().split())
c = list({int(i)} for i in input().split())
for _ in range(q):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if len(c[a]) > len(c[b]): # heuristic union!!
        c[a], c[b] = c[b], c[a]
    c[b].update(c[a])
    c[a].clear()
    print(len(c[b]))
