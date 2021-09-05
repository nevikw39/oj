#include "1992.hpp"

int main()
{
    vector<vector<int>> a = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}}, b = {{1, 1}, {1, 1}}, c = {{0}};
    Solution sln;
    for (auto &&i : sln.findFarmland(a))
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << '\n';
    cout << '\n';
    for (auto &&i : sln.findFarmland(b))
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << '\n';
    cout << '\n';
    for (auto &&i : sln.findFarmland(c))
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << '\n';
    cout << '\n';
    return 0;
}
