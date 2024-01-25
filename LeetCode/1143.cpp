#include "1143.hpp"

int main()
{
    Solution sln;
    cout << sln.longestCommonSubsequence("abcde", "ace") << '\n'
         << sln.longestCommonSubsequence("abcde", "abc") << '\n'
         << sln.longestCommonSubsequence("abc", "def") << '\n';
    return 0;
}
