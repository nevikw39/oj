#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int c, s, q, t = 0;
    while (cin >> c >> s >> q && c)
    {
        if (t)
            cout << '\n';
        cout << "Case #" << ++t << '\n';
        vector<vector<int>> d(c + 1, vector<int>(c + 1, INT_MAX));
        while (s--)
        {
            int a, b, n;
            cin >> a >> b >> n;
            d[a][b] = d[b][a] = n;
        }
        for (int k = 1; k <= c; k++)
            for (int i = 1; i <= c; i++)
                for (int j = 1; j <= c; j++)
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            if (d[a][b] == INT_MAX)
                cout << "no path\n";
            else
                cout << d[a][b] << '\n';
        }
    }
    return 0;
}