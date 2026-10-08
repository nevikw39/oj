#include "1021.hpp"

int main()
{
    Solution sln;
    assert(sln.removeOuterParentheses("(()())(())") == "()()()");
    assert(sln.removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
    assert(sln.removeOuterParentheses("()()") == "");
    return 0;
}
