#include "2057.hpp"

int main()
{
    vector<int> a = {0, 1, 2}, b = {4, 3, 2, 1}, c = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, d = {2, 1, 3, 5, 2};
    Solution sln;
    cout << sln.smallestEqual(a) << '\n'
         << sln.smallestEqual(b) << '\n'
         << sln.smallestEqual(c) << '\n'
         << sln.smallestEqual(d) << '\n';
    return 0;
}
