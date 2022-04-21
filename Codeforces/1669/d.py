def solve():
    n = int(input())
    s = input()
    for i in s.split('W'):
        if i and (i == 'R' * len(i) or i == 'B' * len(i)):
            print("no")
            return
    print("yes")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
