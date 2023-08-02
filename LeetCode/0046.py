from typing import *
from itertools import permutations as P


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return P(nums)


if __name__ == "__main__":
    sln = Solution()
    print(sln.permute([1, 2, 3]))
    print(sln.permute([0, 1]))
    print(sln.permute([1]))
