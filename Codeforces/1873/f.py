#!/opt/homebrew/bin/python3

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    h = list(map(int, input().split()))
    ans = 0
    l = 0

    def f(r: int):
        nonlocal ans
        lst = a[l: r]
        cnt = 0
        sum = 0
        for i, e in enumerate(lst):
            if sum + e <= k:
                sum += e
                cnt += 1
                ans = max(ans, cnt)
            elif sum:
                sum = sum - lst[i - cnt] + e

    for r in range(1, n):
        if h[r - 1] % h[r]:
            f(r)
            l = r
    f(n)
    print(ans)


if __name__ == "__main__":
    for _ in range(t := int(input())):
        solve()
