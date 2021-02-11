import sys
for line in sys.stdin:
	if line == '0 0\n':
		print('All Over.')
		break
	a, b = map(int, line.split())
	print(a ** b)
