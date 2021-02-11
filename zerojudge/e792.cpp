#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<short>> v(n, vector<short>(n));
    for (int i = 0; i < n; i++)
        v[i][i] = 1;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] |= v[i][k] & v[k][j];
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (v[a][b] ? "YES\n" : "NO\n");
    }
    return 0;
}