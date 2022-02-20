#include "2176.hpp"

int main()
{
    vector<int> a = {3, 1, 2, 2, 2, 1, 3}, b = {1, 2, 3, 4};
    Solution sln;
    cout << sln.countPairs(a, 2) << '\n'
         << sln.countPairs(b, 1) << '\n';
    return 0;
}
