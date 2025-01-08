from typing import *


class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int: return sum(sum(word_i.startswith(word_j) and word_i.endswith(word_j) for word_j in words[:i]) for i, word_i in enumerate(words))


if __name__ == "__main__":
    sln = Solution()
    assert sln.countPrefixSuffixPairs(words = ["a","aba","ababa","aa"]) == 4
    assert sln.countPrefixSuffixPairs(words = ["pa","papa","ma","mama"]) == 2
    assert sln.countPrefixSuffixPairs(words = ["abab","ab"]) == 0
