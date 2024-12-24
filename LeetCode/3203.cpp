#include "3203.hpp"

int main()
{
    vector<vector<int>> a1{{0, 1}, {0, 2}, {0, 3}}, a2{{0, 1}}, b1{{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}}, b2{{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
    Solution sln;
    assert(sln.minimumDiameterAfterMerge(a1, a2) == 3);
    assert(sln.minimumDiameterAfterMerge(b1, b2) == 5);
    return 0;
}
