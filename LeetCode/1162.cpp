#include "1162.hpp"

int main()
{
    Solution sln;
    vector<vector<int>> a{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}, b{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << sln.maxDistance(a) << '\n'
         << sln.maxDistance(b) << '\n';
    return 0;
}
