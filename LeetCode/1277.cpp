#include "1277.hpp"

int main()
{
    vector<vector<int>> a{{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}}, b{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    Solution sln;
    assert(sln.countSquares(a) == 15);
    assert(sln.countSquares(b) == 7);
    return 0;
}
