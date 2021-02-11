n = int(input())
o = '+-*/%'
for i in range(n):
	s = ''.join([x for x in input() if x.isdigit() or x in o]).replace('/', '//')
	try:
		print(eval(s))
	except:
		for j in o:
			s = s.replace(j + '0', j)
		print(eval(s))
