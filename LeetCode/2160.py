class Solution:
    def minimumSum(self, num: int) -> int:
        s = sorted(str(num))
        return int(s[0] + s[2]) + int(s[1] + s[3])

if __name__ == "__main__":
    sln = Solution()
    print(sln.minimumSum(2932))
    print(sln.minimumSum(4009))
