#include "5227.hpp"

int main()
{
    vector<int> a = {5, 2, 2, 4, 0, 6}, b = {2};
    Solution sln;
    cout << sln.maximumTop(a, 4) << '\n'
         << sln.maximumTop(b, 1) << '\n';
    return 0;
}
