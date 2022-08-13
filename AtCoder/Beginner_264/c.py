import itertools

h1, w1 = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h1)]
h2, w2 = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(h2)]
for r in itertools.combinations(range(h1), h2):
    for c in itertools.combinations(range(w1), w2):
        if [[a[i][j] for j in c] for i in r] == b:
            print("Yes")
            exit()
print("No")
