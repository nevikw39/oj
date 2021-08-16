import sys
for line in sys.stdin:
	print(bin(int(line))[2:])
