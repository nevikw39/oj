#include "5910.hpp"

int main()
{
    Solution sln;
    cout << sln.checkAlmostEquivalent("aaaa", "bccb") << '\n'
         << sln.checkAlmostEquivalent("abcdeef", "abaaacc") << '\n'
         << sln.checkAlmostEquivalent("cccddabba", "babababab") << '\n';
    return 0;
}
