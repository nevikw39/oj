#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
struct node
{
    int x, c;
};
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ifstream f("in.txt");
    #define cin f
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> d(n + 1), v(n + 1), r(n + 1, INT_MAX);
        vector<vector<node>> g(n + 1);
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        deque<int> q;
        q.push_back(n);
        d[n] = 0;
        bool flag = true;
        while (q.size() && flag)
        {
            int a = q.front();
            q.pop_front();
            for (const auto &i : g[a])
                if (!d[i.x] && i.x != n)
                {
                    d[i.x] = d[a] + 1;
                    if (i.x == 1)
                    {
                        flag = false;
                        break;
                    }
                    q.push_back(i.x);
                }
        }
        q.clear();
        q.push_back(1);
        while (q.size())
        {
            int a = q.front(), mn = INT_MAX;
            q.pop_front();
            for (const auto &i : g[a])
                if (d[a] == d[i.x] + 1)
                    mn = min(mn, i.c);
            for (const auto &i : g[a])
                if (d[a] == d[i.x] + 1 && i.c == mn && !v[i.x])
                {
                    q.push_back(i.x);
                    v[i.x] = true;
                }
            r[d[1] - d[a]] = min(r[d[1] - d[a]], mn);
            if (a == n)
                break;
        }
        cout << d[1] << '\n'
             << r[0];
        for (int i = 1; i < d[1]; i++)
            cout << ' ' << r[i];
        cout << '\n';
    }
    return 0;
}