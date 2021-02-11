import sys
for line in sys.stdin:
    print("{} and {} sitting in the tree ".format(line.split(" ")[0], line.split(" ")[1].splitlines()[0]))
