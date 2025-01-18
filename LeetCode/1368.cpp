#include "1368.hpp"

int main()
{
    vector<vector<int>> a{{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}}, b{{1, 1, 3}, {3, 2, 2}, {1, 1, 4}}, c{{1, 2}, {4, 3}}, d{{2, 2, 2}, {2, 2, 2}};
    Solution sln;
    assert(sln.minCost(a) == 3);
    assert(sln.minCost(b) == 0);
    assert(sln.minCost(c) == 1);
    return 0;
}
