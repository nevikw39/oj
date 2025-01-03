#include "2270.hpp"

int main()
{
    vector<int> a{10, 4, -8, 7}, b{2, 3, 1, 0};
    Solution sln;
    assert(sln.waysToSplitArray(a) == 2);
    assert(sln.waysToSplitArray(b) == 2);
    return 0;
}
