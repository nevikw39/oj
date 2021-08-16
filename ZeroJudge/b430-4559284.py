import sys
for line in sys.stdin:
	a, b, n = map(int, line.split())
	print(a * b % n)
