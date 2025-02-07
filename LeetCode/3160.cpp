#include "3160.hpp"

int main()
{
    vector<vector<int>> a{{1, 4}, {2, 5}, {1, 3}, {3, 4}}, b{{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    Solution sln;
    assert(sln.queryResults(4, a) == (vector<int>{1, 2, 2, 3}));
    assert(sln.queryResults(4, b) == (vector<int>{1, 2, 2, 3, 4}));
    return 0;
}
