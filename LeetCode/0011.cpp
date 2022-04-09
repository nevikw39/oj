#include "0011.hpp"

int main()
{
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7}, b = {1, 1};
    Solution sln;
    cout << sln.maxArea(a) << '\n'
         << sln.maxArea(b) << '\n';
    return 0;
}
