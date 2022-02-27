#include "6010.hpp"

int main()
{
    vector<int> a = {1, 2, 3}, b = {2}, c = {1};
    Solution sln;
    cout << sln.minimumTime(a, 5) << '\n'
         << sln.minimumTime(b, 1) << '\n'
         << sln.minimumTime(c, 4) << '\n';
    return 0;
}
