#include "1203.hpp"

int main()
{
    vector a{-1, 0, 0, -1};
    vector<vector<int>> aa{{}, {0}, {1, 3}, {2}};
    Solution sln;
    sln.sortItems(4, 1, a, aa);
    return 0;
}
