import sys
for line in sys.stdin:
    if line == '0':
        break
    sys.stdout.write('%d\n' % (not int(line) % 17))
