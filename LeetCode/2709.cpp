#include "2709.hpp"

int main()
{
    vector<int> a{2, 3, 6}, b{3, 9, 5}, c{4, 3, 12, 8};
    Solution sln;
    cout << sln.canTraverseAllPairs(a) << '\n'
         << sln.canTraverseAllPairs(b) << '\n'
         << sln.canTraverseAllPairs(c) << '\n';
    return 0;
}
