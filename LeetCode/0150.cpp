#include "0150.hpp"

int main()
{
    vector<string> a{"2", "1", "+", "3", "*"}, b{"4", "13", "5", "/", "+"}, c{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution sln;
    cout << sln.evalRPN(a) << '\n'
         << sln.evalRPN(b) << '\n'
         << sln.evalRPN(c) << '\n';
    return 0;
}
