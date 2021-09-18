#include "5859.hpp"

int main()
{
    vector<int> a = {1, 2, 2, 1}, b = {1, 3}, c = {3, 2, 1, 5, 4};
    Solution sln;
    cout << sln.countKDifference(a, 1) << '\n'
         << sln.countKDifference(b, 3) << '\n'
         << sln.countKDifference(c, 2) << '\n';
    return 0;
}
