from typing import *


if "ListNode" not in dir():
    class ListNode:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1, n2 = 0, 0
        while l1:
            n1 = n1 * 10 + l1.val
            l1 = l1.next
        while l2:
            n2 = n2 * 10 + l2.val
            l2 = l2.next
        dummy = ListNode(-1)
        cur = dummy
        for i in str(n1 + n2):
            cur.next = ListNode(int(i))
            cur = cur.next
        return dummy.next
