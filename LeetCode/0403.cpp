#include "0403.hpp"

int main()
{
    vector<int> a{0, 1, 3, 5, 6, 8, 12, 17}, b{0, 1, 2, 3, 4, 8, 9, 11};
    Solution sln;
    cout << sln.canCross(a) << '\n'
         << sln.canCross(b) << '\n';
    return 0;
}
