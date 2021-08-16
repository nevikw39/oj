import sys
for line in sys.stdin:
    lst = []
    for i in range(int(line)):
        lst.append(int(sys.stdin.readline()))
    lst.sort()
    for i in lst:
        sys.stdout.write('%d\n' % i)
