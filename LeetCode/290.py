class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        lst = s.split()
        if len(pattern) != len(lst):
            return False
        d1 = dict()
        d2 = dict()
        for k, v in zip(pattern, lst):
            if k in d1 and d1[k] != v or v in d2 and d2[v] != k:
                return False
            else:
                d1[k] = v
                d2[v] = k
        return True

if __name__ == "__main__":
    sln = Solution()
    print(sln.wordPattern("abba", "dog cat cat dog"))
    print(sln.wordPattern("abba", "dog cat cat fish"))
    print(sln.wordPattern("aaaa", "dog cat cat dog"))
    print(sln.wordPattern("abba", "dog dog dog dog"))
    print(sln.wordPattern("aaa", "aa aa aa aa"))
