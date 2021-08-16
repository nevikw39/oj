import sys
import datetime
for line in sys.stdin:
    y0, m0, d0 = map(int, line.split())
    y1, m1, d1 = map(int, input().split())
    d0 = datetime.date(y0, m0, d0)
    d1 = datetime.date( y1, m1, d1)
    print(abs((d1 - d0).days))
