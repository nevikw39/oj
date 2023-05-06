#include "1498.hpp"

int main()
{
    vector<int> a{3, 5, 6, 7}, b{3, 3, 6, 8}, c{2, 3, 3, 4, 6, 7};
    Solution sln;
    cout << sln.numSubseq(a, 9) << '\n'
         << sln.numSubseq(b, 10) << '\n'
         << sln.numSubseq(c, 12) << '\n';
    return 0;
}
