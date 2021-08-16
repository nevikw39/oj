import sys
for line in sys.stdin:
	if "0 0" in line:
		break
	a, b = line.split()
	print(pow(int(a), int(b)))
