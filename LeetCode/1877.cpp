#include "1877.hpp"

int main()
{
    Solution sln;
    assert(sln.minCost(4, {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}}) == 5);
    assert(sln.minCost(4, {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}}) == 3);
    return 0;
}
