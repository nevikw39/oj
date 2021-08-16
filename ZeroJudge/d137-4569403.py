import sys
for line in sys.stdin:
	print('%.3f' % abs(complex(line.replace('i', 'j').replace('+j', '+1j').replace('-j', '-1j'))))
