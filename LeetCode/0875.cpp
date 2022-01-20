#include "0875.hpp"

int main()
{
    vector<int> a = {3, 6, 7, 11}, b = {30, 11, 23, 4, 20}, c = {30, 11, 23, 4, 20};
    Solution sln;
    cout << sln.minEatingSpeed(a, 8) << '\n'
         << sln.minEatingSpeed(b, 5) << '\n'
         << sln.minEatingSpeed(c, 6) << '\n';
    return 0;
}
