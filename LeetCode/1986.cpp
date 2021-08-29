#include "1986.hpp"

int main()
{
    vector<int> a = {1, 2, 3}, b = {3, 1, 3, 1, 1}, c = {1, 2, 3, 4, 5}, d = {7, 4, 3, 8, 10}, e = {2, 3, 3, 4, 4, 4, 5, 6, 7, 10};
    Solution sln;
    cout << sln.minSessions(a, 3) << '\n'
         << sln.minSessions(b, 8) << '\n'
         << sln.minSessions(c, 15) << '\n'
         << sln.minSessions(d, 12) << '\n'
         << sln.minSessions(e, 12) << '\n';
    return 0;
}
