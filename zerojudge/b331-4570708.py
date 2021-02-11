import sys
sys.setrecursionlimit(1000000)
for line in sys.stdin:
	print(str(eval(line))[-4:])
