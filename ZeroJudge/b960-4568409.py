from decimal import *
getcontext().prec = 300000
a, b = map(Decimal, input().split())
print(a // b)
