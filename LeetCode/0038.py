from itertools import groupby


class Solution:
    def countAndSay(self, n: int) -> str:
        y = '1'
        for _ in range(1, n):
            y = ''.join(f"{len(tuple(g))}{k}" for k, g in groupby(y))
        return y


if __name__ == "__main__":
    sln = Solution()
    assert sln.countAndSay(4) == "1211"
    assert sln.countAndSay(1) == '1'
