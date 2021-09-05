#include "5863.hpp"

int main()
{
    vector<int> a = {1, 2, 3, 6}, b = {3, 3, 6, 4, 5}, c = {1, 1, 1, 3, 5}, d = {9, 6, 8, 23, 39, 23};
    Solution sln;
    cout << sln.countQuadruplets(a) << '\n'
         << sln.countQuadruplets(b) << '\n'
         << sln.countQuadruplets(c) << '\n'
         << sln.countQuadruplets(d) << '\n';
    return 0;
}
