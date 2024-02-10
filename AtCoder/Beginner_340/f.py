#!/home/nevikw/miniconda3/bin/python

from typing import Tuple


def ext_gcd(a: int, b: int) -> Tuple[int, int, int]:
    if not a:
        return (b, 0, 1)
    else:
        gcd, x, y = ext_gcd(b % a, a)
        return (gcd, y - (b // a) * x, x)


if __name__ == "__main__":
    x, y = map(int, input().split())
    if not x:
        if abs(y) > 2: print("-1")
        else: print(2 // y, 0)
    elif not y:
        if abs(x) > 2: print("-1")
        else: print(0, 2 // x)
    else:
        gcd, a, b = ext_gcd(y, x)
        if 2 % gcd: print("-1")
        else:
            a *= 2 // gcd
            b *= -2 // gcd
            assert abs(x * b - y * a) == 2
            print(a, b)
