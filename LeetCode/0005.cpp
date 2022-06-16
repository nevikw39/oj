#include "0005.hpp"

int main()
{
    Solution sln;
    cout << sln.longestPalindrome("babad") << '\n'
         << sln.longestPalindrome("cbbd") << '\n'
         << sln.longestPalindrome("a") << '\n'
         << sln.longestPalindrome("ac") << '\n';
    return 0;
}
