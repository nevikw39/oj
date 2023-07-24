#!/usr/bin/python3

from sys import stdin, stdout, stderr
from decimal import Decimal


def solve():
    n, k = map(Decimal, stdin.readline().split())
    a, b, c = Decimal(0), Decimal(0), -k
    for i in list(map(Decimal, stdin.readline().split())):
        a += 4
        b += 4 * i
        c += i * i
    # stderr.write(f"{b ** 2 - 4 * a * c}\n")
    stdout.write(f"{(-b + (b ** 2 - 4 * a * c).sqrt()) / (2 * a)}\n")


if __name__ == "__main__":
    for _ in range(int(stdin.readline())):
        solve()
