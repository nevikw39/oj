#include "0532.hpp"

int main()
{
    vector<int> a = {3, 1, 4, 1, 5}, b = {1, 2, 3, 4, 5}, c = {1, 3, 1, 5, 4}, d = {1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    Solution sln;
    cout << sln.findPairs(a, 2) << '\n'
         << sln.findPairs(b, 1) << '\n'
         << sln.findPairs(c, 0) << '\n'
         << sln.findPairs(d, 3) << '\n';
    return 0;
}
