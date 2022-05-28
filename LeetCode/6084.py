from typing import *


class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        d = dict()
        for i, j in zip(messages, senders):
            if j in d:
                d[j] += len(i.split())
            else:
                d[j] = len(i.split())
        return max(d, key=lambda x: (d[x], x))


if __name__ == "__main__":
    sln = Solution()
    print(sln.largestWordCount(messages=["Hello userTwooo", "Hi userThree", "Wonderful day Alice",
                                         "Nice day userThree"], senders=["Alice", "userTwo", "userThree", "Alice"]))
    print(sln.largestWordCount(messages=[
          "How is leetcode for everyone", "Leetcode is useful for practice"], senders=["Bob", "Charlie"]))
