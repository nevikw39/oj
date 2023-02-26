#include "1011.hpp"

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b{3, 2, 2, 4, 1, 4}, c{1, 2, 3, 1, 1};
    Solution sln;
    cout << sln.shipWithinDays(a, 5) << '\n'
         << sln.shipWithinDays(b, 3) << '\n'
         << sln.shipWithinDays(c, 4) << '\n';
    return 0;
}
