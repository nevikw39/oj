class Solution:
    def isSameAfterReversals(self, num: int) -> bool:
        return str(num).lstrip('0') == str(num)[::-1].lstrip('0')[::-1]


if __name__ == "__main__":
    sln = Solution()
    print(sln.isSameAfterReversals(526))
    print(sln.isSameAfterReversals(1800))
    print(sln.isSameAfterReversals(0))
    print(sln.isSameAfterReversals(2021))
    print(sln.isSameAfterReversals(12300))
