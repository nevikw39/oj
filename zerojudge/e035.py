from decimal import *
import sys
getcontext().prec = 1000000000
for line in sys.stdin:
	if "0 0" in line:
		break
	a, b = line.split()
	print(Decimal(a) ** Decimal(b))
