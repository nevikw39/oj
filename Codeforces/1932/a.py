def solve():
    n = int(input())
    s = input()
    print(s.split("**")[0].count('@'))


if __name__ == "__main__":
    for _ in range(t := int(input())):
        solve()
