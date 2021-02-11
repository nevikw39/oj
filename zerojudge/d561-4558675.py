from decimal import *
import sys
z = Decimal("0.00")
for line in sys.stdin:
	print(Decimal(line).quantize(z) if not "-0.0" in line else "0.00")
