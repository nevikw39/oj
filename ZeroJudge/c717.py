import sys
for line in sys.stdin:
	line = line.replace('\n', '')
	print(line + ' ' + line)
