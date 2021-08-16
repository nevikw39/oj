from sys import stdin, stdout
try:
    bytes_stdin, bytes_stdout = stdin.buffer, stdout.buffer
except AttributeError:
    bytes_stdin, bytes
for line in bytes_stdin:
	line = line.decode()
	if "0 0" in line:
		break
	a, b = map(int, line.split())
	sum = a ** (b // 2)
	sum *= sum * (a if b % 2 else 1)
	bytes_stdout.write(str(sum).encode() + b'\n')
