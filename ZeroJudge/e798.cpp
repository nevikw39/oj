#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (auto &i : v)
    {
        i = vector<int>(n);
        for (int &j : i)
            cin >> j;
    }
    int m = n >> 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cout << max({v[i << 1][j << 1], v[i << 1 | 1][j << 1], v[i << 1][j << 1 | 1], v[i << 1 | 1][j << 1 | 1]}) << ' ';
        cout << '\n';
    }
    return 0;
}