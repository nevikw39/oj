#!/usr/bin/python3


class Solution:
    def addSpaces(self, s: str, spaces) -> str:
        lst = list()
        for i in range(len(spaces)):
            lst.append(s[spaces[i - 1] if i else 0: spaces[i]])
        lst.append(s[spaces[- 1]:])
        return ' '.join(lst)


if __name__ == "__main__":
    sln = Solution()
    print(sln.addSpaces("LeetcodeHelpsMeLearn", [8, 13, 15]))
    print(sln.addSpaces("icodeinpython", [1, 5, 7, 9]))
    print(sln.addSpaces("spacing", [0, 1, 2, 3, 4, 5, 6]))
