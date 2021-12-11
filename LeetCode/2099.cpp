#include "2099.hpp"

int main()
{
    vector<int> a = {2, 1, 3, 3}, b = {-1, -2, 3, 4}, c = {3, 4, 3, 3}, d = {50, -75};
    Solution sln;
    for (auto &i : sln.maxSubsequence(a, 2))
        cout << i << ' ';
    cout << '\n';
    for (auto &i : sln.maxSubsequence(b, 3))
        cout << i << ' ';
    cout << '\n';
    for (auto &i : sln.maxSubsequence(c, 2))
        cout << i << ' ';
    cout << '\n';
    for (auto &i : sln.maxSubsequence(d, 2))
        cout << i << ' ';
    cout << '\n';
    return 0;
}
