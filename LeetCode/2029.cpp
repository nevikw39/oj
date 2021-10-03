#include "2029.hpp"

int main()
{
    vector<int> a = {2, 1}, b = {2}, c = {5, 1, 2, 4, 3}, d = {3, 3}, e = {20, 3, 20, 17, 2, 12, 15, 17, 4}, f = {2, 3, 1};
    Solution sln;
    cout << sln.stoneGameIX(a) << '\n'
         << sln.stoneGameIX(b) << '\n'
         << sln.stoneGameIX(c) << '\n'
         << sln.stoneGameIX(d) << '\n'
         << sln.stoneGameIX(e) << '\n'
         << sln.stoneGameIX(f) << '\n';
    return 0;
}
