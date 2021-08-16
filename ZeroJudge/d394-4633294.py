from decimal import *
import sys
getcontext().prec = 10000000
for line in sys.stdin:
	r, n = map(Decimal, line.split())
	sys.stdout.write('{:f}'.format(r ** n).strip('0').rstrip('0').rstrip('.') + '\n')
