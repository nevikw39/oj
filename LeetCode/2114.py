class Solution:
    def mostWordsFound(self, sentences) -> int:
        y = 0
        for sentence in sentences:
            y = max(y, len(sentence.split()))
        return y

if __name__ == "__main__":
    sln = Solution()
    print(sln.mostWordsFound(["alice and bob love leetcode", "i think so too", "this is great thanks very much"]))
    print(sln.mostWordsFound(["please wait", "continue to fight", "continue to win"]))
