#include "1235.hpp"

int main()
{
    vector<int> a0{1, 2, 3, 3}, a1{3, 4, 5, 6}, a2{50, 10, 40, 70}, b0{1, 2, 3, 4, 6}, b1{3, 5, 10, 6, 9}, b2{20, 20, 100, 70, 60}, c0{1, 1, 1}, c1{2, 3, 4}, c2{5, 6, 4};
    Solution sln;
    cout << sln.jobScheduling(a0, a1, a2) << '\n'
         << sln.jobScheduling(b0, b1, b2) << '\n'
         << sln.jobScheduling(c0, c1, c2) << '\n';
    return 0;
}
