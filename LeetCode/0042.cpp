#include "0042.hpp"

int main()
{
    vector<int> a{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, b{4, 2, 0, 3, 2, 5};
    Solution sln;
    cout << sln.trap(a) << '\n'
         << sln.trap(b) << '\n';
    return 0;
}
