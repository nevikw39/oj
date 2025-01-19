#include "0407.hpp"

int main()
{
    vector<vector<int>> a{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}}, b{{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}}, c{{9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9}, {9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 9}, {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9}, {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}}, d{{1}};
    Solution sln;
    assert(sln.trapRainWater(a) == 4);
    assert(sln.trapRainWater(b) == 10);
    assert(sln.trapRainWater(c) == 215);
    assert(sln.trapRainWater(d) == 0);
    return 0;
}
