#include "2218.hpp"

int main()
{
    vector<vector<int>> a = {{1, 100, 3}, {7, 8, 9}}, b = {{100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}};
    Solution sln;
    cout << sln.maxValueOfCoins(a, 2) << '\n'
         << sln.maxValueOfCoins(b, 7) << '\n';
    return 0;
}
