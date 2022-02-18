#include "0402.hpp"

int main()
{
    Solution sln;
    cout << sln.removeKdigits("1432219", 3) << '\n'
         << sln.removeKdigits("10200", 1) << '\n'
         << sln.removeKdigits("10", 2) << '\n';
    return 0;
}
