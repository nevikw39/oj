import sys
for line in sys.stdin:
	if line == '0 0\n':
		break
	a, n = map(int, line.split())
	sys.stdout.write('%d\n' % a ** n)
sys.stdout.write('All Over. Exceeded 65536 lines!')
