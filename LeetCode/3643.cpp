#include "3643.hpp"

int main()
{
    Solution sln;
    assert(sln.reverseSubmatrix({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 1, 0, 3) == vector<vector<int>>({{1, 2, 3, 4}, {13, 14, 15, 8}, {9, 10, 11, 12}, {5, 6, 7, 16}}));
    assert(sln.reverseSubmatrix({{3, 4, 2, 3}, {2, 3, 4, 2}}, 1, 0, 3) == vector<vector<int>>({{3, 4, 4, 2}, {2, 3, 2, 3}}));
    return 0;
}
