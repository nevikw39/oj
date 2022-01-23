#include "2151.hpp"

int main()
{
    vector<vector<int>> a = {{2, 1, 2}, {1, 2, 2}, {2, 0, 2}}, b = {{2, 0}, {0, 2}}, c = {{2, 0, 2, 2, 0}, {2, 2, 2, 1, 2}, {2, 2, 2, 1, 2}, {1, 2, 0, 2, 2}, {1, 0, 2, 1, 2}}, d = {{2, 2, 2, 2, 2, 2}, {2, 2, 2, 1, 1, 2}, {2, 2, 2, 2, 2, 2}, {0, 1, 0, 2, 1, 2}, {0, 1, 2, 1, 2, 0}, {0, 0, 1, 0, 2, 2}}, e = {{2, 2, 2, 2}, {1, 2, 1, 0}, {0, 2, 2, 2}, {0, 0, 0, 2}};
    Solution sln;
    cout << sln.maximumGood(a) << '\n'
         << sln.maximumGood(b) << '\n'
         << sln.maximumGood(c) << '\n'
         << sln.maximumGood(d) << '\n'
         << sln.maximumGood(e) << '\n';
    return 0;
}
