#include "2684.hpp"

int main()
{
    vector<vector<int>> a{{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}}, b{{3, 2, 4}, {2, 1, 9}, {1, 1, 7}}, c{{}};
    Solution sln;
    assert(sln.maxMoves(a) == 3);
    assert(sln.maxMoves(b) == 0);
    return 0;
}
