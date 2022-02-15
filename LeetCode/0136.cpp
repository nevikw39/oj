#include "0136.hpp"

int main()
{
    vector<int> a = {2, 2, 1}, b = {4, 1, 2, 1, 2}, c = {1};
    Solution sln;
    cout << sln.singleNumber(a) << '\n'
         << sln.singleNumber(b) << '\n'
         << sln.singleNumber(c) << '\n';
    return 0;
}
