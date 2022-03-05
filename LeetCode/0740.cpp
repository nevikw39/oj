#include "0740.hpp"

int main()
{
    vector<int> a = {3, 4, 2}, b = {2, 2, 3, 3, 3, 4};
    Solution sln;
    cout << sln.deleteAndEarn(a) << '\n'
         << sln.deleteAndEarn(b) << '\n';
    return 0;
}
