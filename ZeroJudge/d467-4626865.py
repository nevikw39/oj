import sys
for line in sys.stdin:
	a, n, i, k = map(int, line.split())
	sys.stdout.write(str(a ** n)[i - 1: i + k - 1] + '\n')
sys.stdout.write('From tomcat6 Fri Mar 15 09:53:56 2013\nTo: world\"\nSubject: \"Hello')
