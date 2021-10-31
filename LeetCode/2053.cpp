#include "2053.hpp"

int main()
{
    vector<string> a = {"d", "b", "c", "b", "c", "a"}, b = {"aaa", "aa", "a"}, c = {"a", "b", "a"};
    Solution sln;
    cout << sln.kthDistinct(a, 2) << '\n'
         << sln.kthDistinct(b, 1) << '\n'
         << sln.kthDistinct(c, 3) << '\n';
    return 0;
}
