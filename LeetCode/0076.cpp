#include "0076.hpp"

int main()
{
    Solution sln;
    cout << sln.minWindow("ADOBECODEBANC", "ABC") << '\n'
         << sln.minWindow("a", "a") << '\n'
         << sln.minWindow("a", "aa") << '\n'
         << sln.minWindow("ab", "a") << '\n'
         << sln.minWindow("ab", "b") << '\n';
    return 0;
}
