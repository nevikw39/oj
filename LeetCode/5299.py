import sys

class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        y = 0
        for i in range(len(s) - k + 1):
            tmp = int(s[i : i + k])
            print('\t', tmp, file=sys.stderr)
            if tmp and not num % tmp:
                y += 1
        return y

if __name__ == "__main__":
    sln = Solution()
    print(sln.divisorSubstrings(num = 240, k = 2))
    print(sln.divisorSubstrings(num = 430043, k = 2))
