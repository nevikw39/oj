class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a = []
        b = []
        for i in version1.split('.'):
            a.append(int(i))
        for i in version2.split('.'):
            b.append(int(i))
        while a and not a[-1]:
            a.pop()
        while b and not b[-1]:
            b.pop()
        return (a > b) - (a < b)


if __name__ == "__main__":
    sln = Solution()
    print(sln.compareVersion("1.01", "1.001"))
    print(sln.compareVersion("1.0", "1.0.0"))
    print(sln.compareVersion("0.1", "1.1"))
