n = int(input())
s = input()
if not 'o' in s or not '-' in s:
    print("-1")
else:
    print(max(map(len, s.split('-'))))
