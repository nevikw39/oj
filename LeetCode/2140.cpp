#include "2140.hpp"

int main()
{
    vector<vector<int>> a{{3, 2}, {4, 3}, {4, 4}, {2, 5}}, b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}, c{{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}};
    Solution sln;
    cout << sln.mostPoints(a) << '\n'
         << sln.mostPoints(b) << '\n'
         << sln.mostPoints(c) << '\n';
    return 0;
}
