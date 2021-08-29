class Solution(object):
    def kthLargestNumber(self, nums, k):
        """
        :type nums: List[str]
        :type k: int
        :rtype: str
        """
        nums = sorted([int(i) for i in nums])
        return str(nums[len(nums) - k])


if __name__ == "__main__":
    sln = Solution()
    print(sln.kthLargestNumber(["3", "6", "7", "10"], 4))
    print(sln.kthLargestNumber(["2", "21", "12", "1"], 3))
    print(sln.kthLargestNumber(["0", "0"], 2))
