from typing import *
from collections import defaultdict

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        dd = defaultdict(list)
        for i in paths:
            lst = i.split(' ')
            for j in lst[1:]:
                name, content = j.split('(')
                dd[content].append(lst[0] + '/' + name)
        return [i for _, i in dd.items() if len(i) > 1]

if __name__ == "__main__":
    sln = Solution()
    print(sln.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]))
    print(sln.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]))
