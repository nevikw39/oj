#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<short>> v(n), w(n);
    for (auto &i : v)
    {
        i.resize(m);
        for (short &j : i)
            cin >> j;
    }
    for (auto &i : w)
    {
        i.resize(m);
        for (short &j : i)
            cin >> j;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int sum = -w[i][j];
            for (int k = 0; k < m; k++)
                sum += w[i][k];
            for (int k = 0; k < n; k++)
                sum += w[k][j];
            v[i][j] ^= sum & 1;
        }
    for (const auto &i : v)
    {
        for (const short &j : i)
            cout << j << ' ';
        cout.put('\n');
    }
    return 0;
}