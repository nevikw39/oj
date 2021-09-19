#include "2011.hpp"

int main()
{
    vector<string> a = {"--X", "X++", "X++"}, b = {"++X", "++X", "X++"}, c = {"X++", "++X", "--X", "X--"};
    Solution sln;
    cout << sln.finalValueAfterOperations(a) << '\n'
         << sln.finalValueAfterOperations(b) << '\n'
         << sln.finalValueAfterOperations(c) << '\n';
    return 0;
}
