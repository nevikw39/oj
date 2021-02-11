import sys
i = 0
b = False
for line in sys.stdin:
	if '0-1' in line:
		print(1)
		continue
	if b:
		i += 1
		continue
	if line == "0 0\n":
		print('All Over.', end='')
		b = True
		continue
	a, n = map(int, line.split())
	sum = a ** n if a != 0 else 0
	print(sum)
if i:
	print(' Exceeded %d lines!' % i)
