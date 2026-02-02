#include "3010.hpp"

int main()
{
    vector a{1, 2, 3, 12}, b{5, 4, 3}, c{10, 3, 1, 1};
    Solution sln;
    assert(sln.minimumCost(a) == 6);
    assert(sln.minimumCost(b) == 12);
    assert(sln.minimumCost(c) == 12);
    return 0;
}
