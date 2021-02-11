from decimal import *
import sys
for line in sys.stdin:
	if line == '\n':
		continue
	b, p, m = map(Decimal, line.split())
	sys.stdout.write(str(pow(b, p, m)) + '\n')
