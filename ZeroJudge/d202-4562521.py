from decimal import *
import sys
getcontext().prec = 10000
for line in sys.stdin:
    a, b = map(Decimal, line.split())
    print("{:.200f}".format(a + b))
