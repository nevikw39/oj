#!/opt/homebrew/bin/python3

from collections import Counter


class Solution:
    def reorganizeString(self, s: str) -> str:
        cnt = Counter(s)
        if cnt.most_common(1)[0][1] > len(s) + 1 >> 1:
            return ""
        lst = []
        for i, j in sorted(cnt.items(), key=lambda x: x[1]):
            lst.extend(i * j)
        lst[1::2], lst[::2] = lst[:len(s) >> 1], lst[len(s) >> 1:]
        return ''.join(lst)


if __name__ == "__main__":
    sln = Solution()
    print(sln.reorganizeString("aab"))
    print(sln.reorganizeString("aaab"))
