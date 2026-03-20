#include "3567.hpp"

int main()
{
    Solution sln;
    assert(sln.minAbsDiff({{1, 8}, {3, -2}}, 2) == vector<vector<int>>({{2}}));
    assert(sln.minAbsDiff({{3, -1}}, 1) == vector<vector<int>>({{0}}));
    assert(sln.minAbsDiff({{1, -2, 3}, {2, 3, 5}}, 2) == vector<vector<int>>({{1, 2}}));
    return 0;
}
