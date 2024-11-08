#include "1829.hpp"

int main()
{
    vector<int> a{0, 1, 1, 3}, b{2, 3, 4, 7}, c{0, 1, 2, 2, 5, 7};
    Solution sln;
    assert(sln.getMaximumXor(a, 2) == vector<int>({0, 3, 2, 3}));
    assert(sln.getMaximumXor(b, 3) == vector<int>({5, 2, 6, 5}));
    assert(sln.getMaximumXor(c, 3) == vector<int>({4, 3, 6, 4, 6, 7}));
    return 0;
}
