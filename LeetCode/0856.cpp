#include "0856.hpp"

int main()
{
    Solution sln;
    cout << sln.scoreOfParentheses("()") << '\n'
         << sln.scoreOfParentheses("(())") << '\n'
         << sln.scoreOfParentheses("()()") << '\n';
    return 0;
}
