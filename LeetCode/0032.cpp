#include "0032.hpp"

int main()
{
    Solution sln;
    cout << sln.longestValidParentheses("(()") << '\n'
         << sln.longestValidParentheses(")()())") << '\n'
         << sln.longestValidParentheses("") << '\n';
    return 0;
}
