from itertools import combinations_with_replacement as H


repunits = [int('1' * i) for i in range(1, 15)]
trios = sorted(list(sum(i) for i in H(repunits, 3)))

n = int(input())
print(trios[n - 1])
