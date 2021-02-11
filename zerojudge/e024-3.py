from sys import stdin, stdout
try:
    bytes_stdin, bytes_stdout = stdin.buffer, stdout.buffer
except AttributeError:
    bytes_stdin, bytes_stdout = stdin, stdout
for line in bytes_stdin:
	line = line.decode()
	if "0 0" in line:
		break
	a, b = map(int, line.split())
	bytes_stdout.write(str(a ** b).encode() + b'\n')
