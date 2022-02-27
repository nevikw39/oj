#include "6008.hpp"

int main()
{
    vector<string> a = {"pay", "attention", "practice", "attend"}, b = {"leetcode", "win", "loops", "success"};
    Solution sln;
    cout << sln.prefixCount(a, "at") << '\n'
         << sln.prefixCount(b, "code") << '\n';
    return 0;
}
