#include "3651.hpp"

int main()
{
    Solution sln;
    assert(sln.minCost({{1, 3, 3}, {2, 5, 4}, {4, 3, 5}}, 2) == 7);
    assert(sln.minCost({{1, 2}, {2, 3}, {3, 4}}, 1) == 9);
    return 0;
}
