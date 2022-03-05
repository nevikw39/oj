#include "2191.hpp"

int main()
{
    vector<int> a0 = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6}, a1 = {991, 338, 38}, b0 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, b1 = {789, 456, 123};
    Solution sln;
    for (auto &&i : sln.sortJumbled(a0, a1))
        cout << i << '\n';
    cout << '\n';
    for (auto &&i : sln.sortJumbled(b0, b1))
        cout << i << '\n';
    return 0;
}
