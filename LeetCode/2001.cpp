#include "2001.hpp"

int main()
{
    vector<vector<int>> a = {{4, 8}, {3, 6}, {10, 20}, {15, 30}}, b = {{4, 5}, {7, 8}};
    Solution sln;
    cout << sln.interchangeableRectangles(a) << '\n'
         << sln.interchangeableRectangles(b) << '\n';
    return 0;
}
