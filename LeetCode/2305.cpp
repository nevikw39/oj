#include "2305.hpp"

int main()
{
    vector<int> a{8, 15, 10, 20, 8}, b{6, 1, 3, 2, 2, 4, 1, 2};
    Solution sln;
    cout << sln.distributeCookies(a, 2) << '\n'
         << sln.distributeCookies(b, 3) << '\n';
    return 0;
}
