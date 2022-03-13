#include "0020.hpp"

int main()
{
    Solution sln;
    cout << sln.isValid("()") << '\n'
         << sln.isValid("()[]{}") << '\n'
         << sln.isValid("(]") << '\n';
    return 0;
}
