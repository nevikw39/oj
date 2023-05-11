#include "1035.hpp"

int main()
{
    vector a0{1, 4, 2}, a1{1, 2, 4}, b0{2, 5, 1, 2, 5}, b1{10, 5, 2, 1, 5, 2}, c0{1, 3, 7, 1, 7, 5}, c1{1, 9, 2, 5, 1}, d0{2, 1}, d1{1, 2, 1, 3, 3, 2};
    Solution sln;
    cout << sln.maxUncrossedLines(a0, a1) << '\n'
         << sln.maxUncrossedLines(b0, b1) << '\n'
         << sln.maxUncrossedLines(c0, c1) << '\n'
         << sln.maxUncrossedLines(d0, d1) << '\n';
    return 0;
}
