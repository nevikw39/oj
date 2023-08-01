from typing import *
from itertools import combinations as C

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return C(range(1, n + 1), k)

if __name__ == "__main__":
    sln = Solution()
    print(sln.combine(4, 2))
    print(sln.combine(1, 1))
