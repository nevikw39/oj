import re
import sys
l = 2147483647
str = ['first number too big','second number too big', 'result too big']
a = []
for line in sys.stdin:
	a.append(line)
	n = list(map(int, re.split('\+|-|\*|\/', line)))
	n.append(eval(line))
	for i in range(3):
		if n[i] > l:
			a.append(str[i])
for i in a:
	print(i)
