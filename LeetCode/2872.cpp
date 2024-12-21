#include "2872.hpp"

int main()
{
    vector<vector<int>> a0{{0, 2}, {1, 2}, {1, 3}, {2, 4}}, b0{{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}}, c0{}, d0{{1,2}, {2,0}};
    vector<int> a1{1, 8, 1, 4, 4}, b1{3, 0, 6, 1, 5, 2, 1}, c1{0}, d1{0,2,2};
    Solution sln;
    assert(sln.maxKDivisibleComponents(5, a0, a1, 6) == 2);
    assert(sln.maxKDivisibleComponents(7, b0, b1, 3) == 3);
    assert(sln.maxKDivisibleComponents(1, c0, c1, 1) == 1);
    assert(sln.maxKDivisibleComponents(3, d0, d1, 4) == 2);
    return 0;
}
