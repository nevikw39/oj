#include "2101.hpp"

int main()
{
    vector<vector<int>> a = {{2, 1, 3}, {6, 1, 4}}, b = {{1, 1, 5}, {10, 10, 5}}, c = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}}, d = {{1, 1, 100000}, {100000, 100000, 1}};
    Solution sln;
    cout << sln.maximumDetonation(a) << '\n'
         << sln.maximumDetonation(b) << '\n'
         << sln.maximumDetonation(c) << '\n'
         << sln.maximumDetonation(d) << '\n';
    return 0;
}
