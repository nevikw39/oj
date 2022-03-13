#include "2201.hpp"

int main()
{
    vector<vector<int>> a0 = {{0, 0, 0, 0}, {0, 1, 1, 1}}, a1 = {{0, 0}, {0, 1}}, b0 = {{0, 0, 0, 0}, {0, 1, 1, 1}}, b1 = {{0, 0}, {0, 1}, {1, 1}};
    Solution sln;
    cout << sln.digArtifacts(2, a0, a1) << '\n'
         << sln.digArtifacts(2, b0, b1) << '\n';
    return 0;
}
