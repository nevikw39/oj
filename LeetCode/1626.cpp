#include "1626.hpp"

int main()
{
    vector<int> a0{1, 3, 5, 10, 15}, a1{1, 2, 3, 4, 5}, b0{4, 5, 6, 5}, b1{2, 1, 2, 1}, c0{1, 2, 3, 5}, c1{8, 9, 10, 1};
    Solution sln;
    cout << sln.bestTeamScore(a0, a1) << '\n'
         << sln.bestTeamScore(b0, c1) << '\n'
         << sln.bestTeamScore(c0, c1) << '\n';
    return 0;
}
