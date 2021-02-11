from datetime import date, datetime, time
s = datetime.combine(date.min, time(7, 30))
e = datetime.combine(date.min, time(17, 00))
h, m = map(int, input().split())
t = datetime.combine(date.min, time(h, m))
if s <= t < e:
	print("At School")
else:
	print("Off School")
