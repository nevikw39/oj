#include "2044.hpp"

int main()
{
    vector<int> a = {3, 1}, b = {2, 2, 2}, c = {3, 1, 2, 5};
    Solution sln;
    cout << sln.countMaxOrSubsets(a) << '\n'
         << sln.countMaxOrSubsets(b) << '\n'
         << sln.countMaxOrSubsets(c) << '\n';
    return 0;
}
