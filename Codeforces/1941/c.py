import sys


def solve():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline()
    sys.stdout.write(str(s.count("map") + s.count("pie") - s.count("mapie")) + '\n')


if __name__ == "__main__":
    for _ in range(t := int(sys.stdin.readline())):
        solve()
