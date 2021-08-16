import sys
for line in sys.stdin:
	if "0 0" in line:
		break
	a, b = map(int, line.split())
	print("%d" % a ** b)
