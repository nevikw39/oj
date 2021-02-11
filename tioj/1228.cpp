#include <bits/extc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#define nevikw39 cin.tie(nullptr); ios::sync_with_stdio(false);
struct _cerr { template<typename T> _cerr &operator<<(const T &x) { return *this; } } __cerr;
#define cerr __cerr
#else
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
struct bit
{
    int n;
    vector<int> v;
    bit(int _n): n(_n)
    {
        v.resize(n + 1);
    }
    int inline lowbit(int x)
    {
        return x & -x;
    }
    int query(int x)
    {
        int y = 0;
        for (; x; x -= lowbit(x))
            y += v[x];
        return y;
    }
    void update(int x, int val = 1)
    {
        for (; x <= n; x += lowbit(x))
            v[x] += val;
    }
};
int cnt = 0;
vector<int> l, e, r, v;
vector<vector<pair<int, int>>> t;
void dfs(int x = 0)
{
    l[x] = cnt;
    for (const auto &i : t[x])
    {
        e[i.first] = cnt;
        v[cnt++] = i.second;
        dfs(i.first);
    }
    r[x] = cnt;
}
int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    l.resize(n);
    e.resize(n);
    r.resize(n);
    t.resize(n);
    v.resize(n);
    for (int i = 1; i < n; i++)
    {
        int a, b, m;
        cin >> a >> b >> m;
        t[a].emplace_back(b, m);
    }
    dfs();
    bit b(n);
    for (int i = 0; i < n; i++)
        b.update(i + 1, v[i]);
    while (q--)
    {
        bool t;
        int d, m;
        cin >> t >> d;
        if (t)
            cout << ((b.query(r[d]) - b.query(l[d])) << 1) << '\n';
        else
        {
            cin >> m;
            b.update(e[d] + 1, m - v[e[d]]);
            v[e[d]] = m;
        }
    }
    cerr << '\n';
    return 0;
}