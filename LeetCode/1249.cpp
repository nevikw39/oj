#include "1249.hpp"

int main()
{
    Solution sln;
    cout << sln.minRemoveToMakeValid("lee(t(c)o)de)") << '\n'
         << sln.minRemoveToMakeValid("a)b(c)d") << '\n'
         << sln.minRemoveToMakeValid("))((") << '\n';
    return 0;
}
