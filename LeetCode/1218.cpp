#include "1218.hpp"

int main()
{
    vector<int> a{1, 2, 3, 4}, b{1, 3, 5, 7}, c{1, 5, 7, 8, 5, 3, 4, 2, 1};
    Solution sln;
    cout << sln.longestSubsequence(a, 1) << '\n'
         << sln.longestSubsequence(b, 1) << '\n'
         << sln.longestSubsequence(c, -2) << '\n';
    return 0;
}
