#include "2658.hpp"

int main()
{
    vector<vector<int>> a{{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}}, b{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};
    Solution sln;
    assert(sln.findMaxFish(a) == 7);
    assert(sln.findMaxFish(b) == 1);
    return 0;
}
