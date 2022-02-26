#include "0847.hpp"

int main()
{
    vector<vector<int>> a = {{1, 2, 3}, {0}, {0}, {0}}, b = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    Solution sln;
    cout << sln.shortestPathLength(a) << '\n'
         << sln.shortestPathLength(b) << '\n';
    return 0;
}
