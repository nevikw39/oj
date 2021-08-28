#include "1981.hpp"

int main()
{
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, b = {{1}, {2}, {3}}, c = {{1, 2, 9, 8, 7}};
    Solution sln;
    cout << sln.minimizeTheDifference(a, 13) << '\n'
         << sln.minimizeTheDifference(b, 100) << '\n'
         << sln.minimizeTheDifference(c, 6) << '\n';
    return 0;
}
