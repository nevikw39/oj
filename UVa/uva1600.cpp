#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
struct node
{
    int x, y, o, s;
};
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k, r = INT_MAX;
        cin >> m >> n >> k;
        bool b[m][n][k + 1];
        memset(b, 0, sizeof(b));
        vector<vector<char>> v(m, vector<char>(n));
        for (auto &i : v)
            for (char &j : i)
                cin >> j;
        queue<node> q;
        q.push({0, 0, v[0][0] == '1', 0});
        while (q.size())
        {
            node t = q.front();
            q.pop();
            if (t.x + 1 == m && t.y + 1 == n)
            {
                r = min(r, t.s);
                continue;
            }
            if (b[t.x][t.y][t.o])
                continue;

            if (t.x + 1 < m && (v[t.x + 1][t.y] == '1' ? t.o + 1 : 0) <= k)
                q.push({t.x + 1, t.y, (v[t.x + 1][t.y] == '1' ? t.o + 1 : 0), t.s + 1});

            if (t.y + 1 < n && (v[t.x][t.y + 1] == '1' ? t.o + 1 : 0) <= k)
                q.push({t.x, t.y + 1, (v[t.x][t.y + 1] == '1' ? t.o + 1 : 0), t.s + 1});

            if (t.x - 1 >= 0 && (v[t.x - 1][t.y] == '1' ? t.o + 1 : 0) <= k)
                q.push({t.x - 1, t.y, (v[t.x - 1][t.y] == '1' ? t.o + 1 : 0), t.s + 1});

            if (t.y - 1 >= 0 && (v[t.x][t.y - 1] == '1' ? t.o + 1 : 0) <= k)
                q.push({t.x, t.y - 1, (v[t.x][t.y - 1] == '1' ? t.o + 1 : 0), t.s + 1});

            b[t.x][t.y][t.o] = true;
        }
        cout << (r != INT_MAX ? r : -1) << '\n';
    }
    return 0;
}