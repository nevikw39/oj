import sys
from functools import cache


dct = dict()


def isdec(x: int) -> bool: return len(s := str(x)) == s.count('0') + s.count('1')

@cache
def candec(x: int) -> bool:
    if isdec(x):
        return True
    for i in range(2, int(x ** .5) + 1):
        if not x % i:
            if candec(i) and candec(x // i):
                return True
    return False

def solve():
    n = int(sys.stdin.readline())
    sys.stdout.write("yes\n" if candec(n) else "no\n")


if __name__ == "__main__":
    for _ in range(t := int(sys.stdin.readline())):
        solve()
