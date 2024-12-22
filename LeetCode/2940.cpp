#include "2940.hpp"

int main()
{
    vector<int> a0{6, 4, 8, 5, 2, 7}, a{2, 5, -1, 5, 2}, b0{5, 3, 8, 2, 6, 1, 4, 6}, b{7, 6, -1, 4, 6};
    vector<vector<int>> a1{{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}}, b1{{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
    Solution sln;
    assert(sln.leftmostBuildingQueries(a0, a1) == a);
    assert(sln.leftmostBuildingQueries(b0, b1) == b);
    return 0;
}
