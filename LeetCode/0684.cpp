#include "0684.hpp"

int main()
{
    vector<vector<int>> a{{1, 2}, {1, 3}, {2, 3}}, b{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    Solution sln;
    assert(sln.findRedundantConnection(a) == (vector<int>{2, 3}));
    assert(sln.findRedundantConnection(b) == (vector<int>{1, 4}));
    return 0;
}
