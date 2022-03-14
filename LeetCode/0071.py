class Solution:
    def simplifyPath(self, path: str) -> str:
        lst = []
        for i in path.split('/'):
            if i == "..":
                if lst:
                    lst.pop()
            elif i and i != '.':
                lst.append(i)
        return '/' + '/'.join(lst)


if __name__ == "__main__":
    sln = Solution()
    print(sln.simplifyPath("/home/"))
    print(sln.simplifyPath("/../"))
    print(sln.simplifyPath("/home//foo/"))
