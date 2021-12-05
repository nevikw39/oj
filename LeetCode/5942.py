import itertools

class Solution:
    def findEvenNumbers(self, digits):
        s = set()
        for i in itertools.permutations(digits, 3):
            if i[0] and not i[-1] & 1:
                s.add(i)
        lst = [int(''.join([str(j) for j in i])) for i in s]
        lst.sort()
        return lst


if __name__ == "__main__":
    sln = Solution()
    print(sln.findEvenNumbers([2, 1, 3, 0]))
    print(sln.findEvenNumbers([2, 2, 8, 8, 2]))
    print(sln.findEvenNumbers([3, 7, 5]))
    print(sln.findEvenNumbers([0, 2, 0, 0]))
    print(sln.findEvenNumbers([0, 0, 0]))
