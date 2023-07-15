#include "1751.hpp"

int main()
{
    vector<vector<int>> a{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}}, b{{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    Solution sln;
    cout << sln.maxValue(a, 2) << '\n'
         << sln.maxValue(b, 2) << '\n';
    return 0;
}
