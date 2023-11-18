from itertools import groupby


input()
dct = dict()
for key, group in groupby(input()):
    l = len(list(group))
    if key in dct:
        dct[key] = max(dct[key], l)
    else:
        dct[key] = l
print(sum(dct.values()))
