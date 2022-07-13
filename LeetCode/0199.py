from typing import *

if not "TreeNode" in dir():
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right


class Solution:
    def dfs(self, r, d=0):
        if not r:
            return
        if len(self.y) == d:
            self.y.append(r.val)
        self.dfs(r.right, d + 1)
        self.dfs(r.left, d + 1)

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.y = []
        self.dfs(root)
        return self.y


if __name__ == "__main__":
    sln = Solution()
