class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word == word.capitalize() or word == word.upper() or word == word.lower()


if __name__ == "__main__":
    sln = Solution()
    print(sln.detectCapitalUse("USA"))
    print(sln.detectCapitalUse("FlaG"))
