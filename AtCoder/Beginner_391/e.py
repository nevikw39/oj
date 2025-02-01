from functools import cache


def main():

    @cache
    def f(n: int, a: str, c: str) -> int:
        if n == 1:
            return max(2 - a.count(c), 0)
        t = sorted(
            (
                f(n - 1, a[: 3 ** (n - 1)], c),
                f(n - 1, a[3 ** (n - 1) : 2 * 3 ** (n - 1)], c),
                f(n - 1, a[2 * 3 ** (n - 1) :], c),
            )
        )
        if t.count(0) == 2:
            return 0
        return t[0] + t[1]

    n = int(input())
    a = input()
    print(max(f(n, a, '0'), f(n, a, '1')))


if __name__ == "__main__":
    main()
