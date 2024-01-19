#include "0931.hpp"

int main()
{
    vector<vector<int>> a{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}}, b{{-19, 57}, {-40, -5}};
    Solution sln;
    cout << sln.minFallingPathSum(a) << '\n'
         << sln.minFallingPathSum(b) << '\n';
    return 0;
}
