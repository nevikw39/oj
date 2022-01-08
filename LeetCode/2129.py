class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return ' '.join([i.capitalize() if len(i) > 2 else i.lower() for i in title.split()])

if __name__ == "__main__":
    sln = Solution()
    print(sln.capitalizeTitle("capiTalIze tHe titLe"))
    print(sln.capitalizeTitle("First leTTeR of EACH Word"))
    print(sln.capitalizeTitle("i lOve leetcode"))
