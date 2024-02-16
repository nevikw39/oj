#include "1481.hpp"

int main()
{
    vector<int> a{5, 5, 4}, b{4, 3, 1, 1, 3, 3, 2};
    Solution sln;
    cout << sln.findLeastNumOfUniqueInts(a, 1) << '\n'
         << sln.findLeastNumOfUniqueInts(b, 3) << '\n';
    return 0;
}
