#include "0941.hpp"

int main()
{
    vector<int> a = {2, 1}, b = {3, 5, 5}, c = {0, 3, 2, 1}, d = {0, 2, 3, 4, 5, 2, 1, 0}, e = {0, 2, 3, 3, 5, 2, 1, 0};
    Solution sln;
    cout << sln.validMountainArray(a) << '\n'
         << sln.validMountainArray(b) << '\n'
         << sln.validMountainArray(c) << '\n'
         << sln.validMountainArray(d) << '\n'
         << sln.validMountainArray(e) << '\n';
    return 0;
}
