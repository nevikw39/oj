#include "3531.hpp"

int main()
{
    vector<vector<int>> a{{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}}, b{{1, 1}, {1, 2}, {2, 1}, {2, 2}}, c{{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
    Solution sln;
    assert(sln.countCoveredBuildings(3, a) == 1);
    assert(sln.countCoveredBuildings(3, b) == 0);
    assert(sln.countCoveredBuildings(5, c) == 1);
    return 0;
}
