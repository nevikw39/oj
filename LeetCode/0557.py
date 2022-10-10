class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(i[::-1] for i in s.split())


if __name__ == "__main__":
    sln = Solution()
    print(sln.reverseWords("Let's take LeetCode contest"))
    print(sln.reverseWords("God Ding"))
