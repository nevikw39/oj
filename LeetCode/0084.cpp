#include "0084.hpp"

int main()
{
    vector<int> a = {2, 1, 5, 6, 2, 3}, b = {2, 4};
    Solution sln;
    cout << sln.largestRectangleArea(a) << '\n'
         << sln.largestRectangleArea(b) << '\n';
    return 0;
}
