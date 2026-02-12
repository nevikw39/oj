import heapq


n, m = map(int, input().split())
lr = tuple(sorted(tuple(map(lambda x: int(x) - 1, input().split())) for i in range(m)))

itr = iter(lr)
l, r = next(itr, (None, None))
pq = []
cnt = 0

for i in range(n):
    while l is not None and l <= i:
        heapq.heappush(pq, r)
        l, r = next(itr, (None, None))
    while pq and pq[0] < i:
        heapq.heappop(pq)
    if pq:
        heapq.heappop(pq)
        cnt += 1

print("Yes" if cnt == m else "No")
