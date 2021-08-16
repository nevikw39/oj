import sys
i = int(input())
while i:
	a, b = map(int, input().split())
	print(a - b)
	i -= 1
