#include "0446.hpp"

int main()
{
    vector<int> a{2, 4, 6, 8, 10}, b{7, 7, 7, 7, 7};
    Solution sln;
    cout << sln.numberOfArithmeticSlices(a) << '\n'
         << sln.numberOfArithmeticSlices(b) << '\n';
    return 0;
}
