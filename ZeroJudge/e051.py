import sys
for line in sys.stdin:
    print(line[0] + '_' * (len(line) - 3) + line[-2])
