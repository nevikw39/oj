#include "2966.hpp"

int main()
{
    vector<int> a{1, 3, 4, 8, 7, 9, 3, 5, 1}, b{1, 3, 3, 2, 7, 3}, c{4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11};
    Solution sln;
    assert(sln.divideArray(a, 2) == vector<vector<int>>({{1, 1, 3}, {3, 4, 5}, {7, 8, 9}}));
    assert(sln.divideArray(b, 3) == vector<vector<int>>());
    assert(sln.divideArray(c, 14) == vector<vector<int>>({{2, 2, 2}, {4, 5, 5}, {5, 5, 7}, {7, 8, 8}, {9, 9, 10}, {11, 12, 12}}));
    return 0;
}
