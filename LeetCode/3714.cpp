#include "3714.hpp"

int main()
{
    Solution sln;
    assert(sln.longestBalanced("abbac") == 4);
    assert(sln.longestBalanced("aabcc") == 3);
    assert(sln.longestBalanced("aba") == 2);
    return 0;
}
