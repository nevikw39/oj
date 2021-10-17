class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        x = -1
        for i in s.split():
            if i.isdigit():
                y = int(i)
                if y <= x:
                    return False
                x = y
        return True

if __name__ == "__main__":
    sln = Solution()
    print(sln.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles"))
    print(sln.areNumbersAscending("hello world 5 x 5"))
    print(sln.areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"))
    print(sln.areNumbersAscending("4 5 11 26"))
