from decimal import *
from sys import stdin
for line in stdin:
	n = Decimal(line)
	p = Decimal(input())
	print((p ** (1 / n)).quantize(0))
