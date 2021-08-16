import sys
for line in sys.stdin:
    for name in line.split(" "):
        print(name.title().splitlines()[0])
