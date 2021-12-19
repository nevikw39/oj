#include "5958.hpp"

int main()
{
    vector<int> a = {3, 2, 1, 4}, b = {8, 6, 7, 7}, c = {1};
    Solution sln;
    cout << sln.getDescentPeriods(a) << '\n'
         << sln.getDescentPeriods(b) << '\n'
         << sln.getDescentPeriods(c) << '\n';
    return 0;
}
