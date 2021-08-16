import sys
for line in sys.stdin:
	if line == '\n':
		continue
	b, p, m = map(int, line.split())
	sys.stdout.write(str(pow(b, p, m)) + '\n')
