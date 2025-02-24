#include "2467.hpp"

int main()
{
    vector<vector<int>> a0{{0, 1}, {1, 2}, {1, 3}, {3, 4}}, b0{{0, 1}};
    vector<int> a1{-2, 4, 2, -4, 6}, b1{-7280, 2350};
    Solution sln;
    assert(sln.mostProfitablePath(a0, 3, a1) == 6);
    assert(sln.mostProfitablePath(b0, 1, b1) == -7280);
    return 0;
}
