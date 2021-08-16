from decimal import *
from sys import stdin
getcontext().prec = MAX_PREC
z = Decimal('0')
for line in stdin:
	if line == '\n':
		continue
	a = Decimal(line)
	b = Decimal(input())
	print((a * b).quantize(z))
