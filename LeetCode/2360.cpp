#include "2360.hpp"

int main()
{
    vector<int> a{3, 3, 4, 2, 3}, b{2, -1, 3, 1};
    Solution sln;
    cout << sln.longestCycle(a) << '\n'
         << sln.longestCycle(b) << '\n';
    return 0;
}
