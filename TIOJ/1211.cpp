#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
struct djs
{
    int g;
    vector<int> p, r;
    djs(int n)
    {
        for (int i = 0; i <= n; i++)
            p.push_back(i);
        r.resize(n + 1, 1);
        g = n;
    }
    int find(int x)
    {

        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        --g;
        if (r[x] < r[y])
        {
            p[x] = y;
            r[y] += r[x];
        }
        else
        {
            p[y] = x;
            r[x] += r[y];
        }
    }
};
struct edge
{
    int s, t, w;
    bool operator<(const edge &x) const
    {
        return w < x.w;
    }
};
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m && n && m)
    {
        int r = 0;
        djs d(n);
        vector<edge> v(m);
        for (edge &i : v)
            cin >> i.s >> i.t >> i.w;
        sort(v.begin(), v.end());
        for (const edge &i : v)
            if (d.find(i.s) != d.find(i.t))
            {
                d.unite(i.s, i.t);
                r += i.w;
            }
        cout << (d.g == 1 ? r : -1) << '\n';
    }
    return 0;
}