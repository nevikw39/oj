#include "5912.hpp"

int main()
{
    vector<vector<int>> a0 = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}}, b0 = {{1, 2}, {1, 2}, {1, 3}, {1, 4}}, c0 = {{10, 1000}};
    vector<int> a1 = {1, 2, 3, 4, 5, 6}, b1 = {1}, c1 = {5};
    Solution sln;
    for (int i : sln.maximumBeauty(a0, a1))
        cout << i << '\n';
    cout << '\n';
    for (int i : sln.maximumBeauty(b0, b1))
        cout << i << '\n';
    cout << '\n';
    for (int i : sln.maximumBeauty(c0, c1))
        cout << i << '\n';
    cout << '\n';
    return 0;
}
