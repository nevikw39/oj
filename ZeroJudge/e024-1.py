import sys
for line in sys.stdin:
	a, b = map(int, line.split())
	if not a and not b:
		break
	print(a ** b)
