#include "1043.hpp"

int main()
{
    vector<int> a{1, 15, 7, 9, 2, 5, 10}, b{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3}, c{1};
    Solution sln;
    cout << sln.maxSumAfterPartitioning(a, 3) << '\n'
         << sln.maxSumAfterPartitioning(b, 4) << '\n'
         << sln.maxSumAfterPartitioning(c, 1) << '\n';
    return 0;
}
