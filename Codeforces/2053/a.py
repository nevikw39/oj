def solve():
    n = int(input())
    a = tuple(map(int, input().split()))
    for i in range(3, n + 1):
        x, y, z = sorted(a[i - 3 : i])
        if x + y > z and x * 2 > z and y * 2 > z:
            print("yes")
            return
    for i in range(2, n + 1):
        x, y = sorted(a[i - 2 : i])
        if x * 2 > y:
            print("yes")
            return
    print("no")


if __name__ == "__main__":
    for t in range(int(input())):
        solve()
