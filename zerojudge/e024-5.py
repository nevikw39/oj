import sys
for line in sys.stdin:
	if "0 0" in line:
		break
	a, b = map(int, line.split())
	sum = a ** (b // 2)
	sum *= sum * (a if b % 2 else 1)
	print(sum)
