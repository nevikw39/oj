#include "0087.hpp"

int main()
{
    Solution sln;
    cout << sln.isScramble("great", "rgeat") << '\n'
         << sln.isScramble("abcde", "caebd") << '\n'
         << sln.isScramble("a", "a") << '\n';
    return 0;
}
