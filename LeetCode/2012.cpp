#include "2012.hpp"

int main()
{
    vector<int> a = {1, 2, 3}, b = {2, 4, 6, 4}, c = {3, 2, 1};
    Solution sln;
    cout << sln.sumOfBeauties(a) << '\n'
         << sln.sumOfBeauties(b) << '\n'
         << sln.sumOfBeauties(c) << '\n';
    return 0;
}
