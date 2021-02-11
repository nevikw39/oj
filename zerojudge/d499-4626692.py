from decimal import *
getcontext().prec = 10000
a, n = map(Decimal, input().split())
print(a ** n)
