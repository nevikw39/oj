#include "1976.hpp"

int main()
{
    vector<vector<int>> a = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}}, b = {{1, 0, 10}};
    Solution sln;
    cout << sln.countPaths(7, a) << '\n'
         << sln.countPaths(2, b) << '\n';
    return 0;
}
