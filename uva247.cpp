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
    int n, m, t = 0;
    while (cin >> n >> m && n)
    {
        if (t)
            cout << '\n';
        cout << "Calling circles for data set " << ++t << ":\n";
        cc_hash_table<string, int> si;
        vector<string> is;
        vector<vector<int>> d(n, vector<int>(n));
        vector<int> v(n);
        auto f = [&](const string &x) { if (si.find(x) != si.end()) return si[x]; is.push_back(x); return si[x] = is.size() - 1; };
        while (m--)
        {
            string a, b;
            cin >> a >> b;
            d[f(a)][f(b)] = true;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    d[i][j] |= d[i][k] && d[k][j];
        for (int i = 0; i < n; i++)
        {
            if (v[i])
                continue;
            v[i] = true;
            cout << is[i];
            for (int j = i + 1; j < n; j++)
                if (!v[j] && d[i][j] && d[j][i])
                {
                    v[j] = true;
                    cout << ", " << is[j];
                }
            cout << '\n';
        }
    }
    return 0;
}