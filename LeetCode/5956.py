#!/usr/bin/python3

class Solution:
    def firstPalindrome(self, words) -> str:
        for i in words:
            if i == i[::-1]:
                return i
        return ""


if __name__ == "__main__":
    sln = Solution()
    print(sln.firstPalindrome(["abc", "car", "ada", "racecar", "cool"]))
    print(sln.firstPalindrome(["notapalindrome", "racecar"]))
    print(sln.firstPalindrome(["def", "ghi"]))
