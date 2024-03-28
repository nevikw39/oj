import sys


def is_nearly_equal(lhs: str, rhs: str) -> bool:
    flag = False
    for i, j in zip(lhs, rhs):
        if i != j:
            if flag:
                return False
            flag = True
    return True


def solve():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline()
    for i in range(1, 1 + n):
        if not n % i and (is_nearly_equal(s, s[:i] * (n // i)) or is_nearly_equal(s, s[i:i<<1] * (n // i))):
            sys.stdout.write(f"{i}\n")
            return


if __name__ == "__main__":
    for _ in range(t := int(sys.stdin.readline())):
        solve()
