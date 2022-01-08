from typing import *

if not "ListNode" in dir():
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next


class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        lst = list()
        while head:
            lst.append(head.val)
            head = head.next
        n = len(lst)
        r = 0
        for i in range(n >> 1):
            r = max(r, lst[i] + lst[n - 1 - i])
        return r


if __name__ == "__main__":
    a = ListNode(5, ListNode(4, ListNode(2, ListNode(1))))
    b = ListNode(4, ListNode(2, ListNode(2, ListNode(3))))
    c = ListNode(1, ListNode(100000))
    sln = Solution()
    print(sln.pairSum(a))
    print(sln.pairSum(b))
    print(sln.pairSum(c))
