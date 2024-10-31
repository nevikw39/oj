#include "2463.hpp"

int main()
{
    vector<int> a0{0, 4, 6}, b0{1, -1};
    vector<vector<int>> a1{{2, 2}, {6, 2}}, b1{{-2, 1}, {2, 1}};
    Solution sln;
    assert(sln.minimumTotalDistance(a0, a1) == 4);
    assert(sln.minimumTotalDistance(b0, b1) == 2);
    return 0;
}
