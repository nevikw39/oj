import sys
for line in sys.stdin:
	print(eval(line.replace('/', '//')))
