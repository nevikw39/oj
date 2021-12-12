#include "2104.hpp"

int main()
{
    vector<int> a = {1, 2, 3}, b = {1, 3, 3}, c = {4, -2, -3, 4, 1};
    Solution sln;
    cout << sln.subArrayRanges(a) << '\n'
         << sln.subArrayRanges(b) << '\n'
         << sln.subArrayRanges(c) << '\n';
    return 0;
}
