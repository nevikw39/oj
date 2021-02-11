from decimal import *
import sys
getcontext().prec = 4180
lst = [Decimal('0'), Decimal('1')]
for i in range(2, 20001):
	lst.append(lst[-1] + lst[-2])
for line in sys.stdin:
	print(lst[int(line)])
