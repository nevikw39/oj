#include "1930.hpp"

int main()
{
    string a("aabca"), b("adc"), c("bbcbaba");
    Solution sln;
    assert(sln.countPalindromicSubsequence(a) == 3);
    assert(sln.countPalindromicSubsequence(b) == 0);
    assert(sln.countPalindromicSubsequence(c) == 4);
    return 0;
}
