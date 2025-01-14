#include "2657.hpp"

int main()
{
    vector<int> a0{1, 3, 2, 4}, a1{3, 1, 2, 4}, b0{2, 3, 1}, b1{3, 1, 2};
    Solution sln;
    assert(sln.findThePrefixCommonArray(a0, a1) == (vector{0, 2, 3, 4}));
    assert(sln.findThePrefixCommonArray(b0, b1) == (vector{3, 1, 2}));
    return 0;
}
