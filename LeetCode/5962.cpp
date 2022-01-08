#include "5962.hpp"

int main()
{
    vector<string> a = {"lc", "cl", "gg"}, b = {"ab", "ty", "yt", "lc", "cl", "ab"}, c = {"cc", "ll", "xx"}, d = {"dd", "aa", "bb", "dd", "aa", "dd", "bb", "dd", "aa", "cc", "bb", "cc", "dd", "cc"};
    Solution sln;
    cout << sln.longestPalindrome(a) << '\n'
         << sln.longestPalindrome(b) << '\n'
         << sln.longestPalindrome(c) << '\n'
         << sln.longestPalindrome(d) << '\n';
    return 0;
}
