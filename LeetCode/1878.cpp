#include "1878.hpp"

int main()
{
    Solution sln;
    assert(sln.getBiggestThree({{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}}) == vector({20, 9, 8}));
    assert(sln.getBiggestThree({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) == vector({7}));
    return 0;
}
