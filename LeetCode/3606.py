from collections import defaultdict
from re import fullmatch
from typing import List


class Solution:
    dct = defaultdict(int, electronics=1, grocery=2, pharmacy=3, restaurant=4)
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        return list(i[0] for i in filter(lambda x: fullmatch(r"[a-zA-Z0-9_]+", x[0]) and x[1] and x[2], sorted(zip(code, map(lambda x: Solution.dct[x], businessLine), isActive), key=lambda x: (x[1], x[0]))))


if __name__ == "__main__":
    sln = Solution()
    assert sln.validateCoupons(["SAVE20", "", "PHARMA5", "SAVE@20"], ["restaurant", "grocery", "pharmacy", "restaurant"], [True, True, True, True]) == ["PHARMA5", "SAVE20"]
    assert sln.validateCoupons(["GROCERY15", "ELECTRONICS_50", "DISCOUNT10"], ["grocery", "electronics", "invalid"], [False, True, True]) == ["ELECTRONICS_50"]
    assert sln.validateCoupons(["1OFw", "0MvB"], ["electronics", "pharmacy"], [True, True]) == ["1OFw", "0MvB"]
