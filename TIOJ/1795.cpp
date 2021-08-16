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
    int n, m, k, mn = 0, mx = 0;
    cin >> n >> m >> k;
    djs d1(n), d2(n);
    vector<edge> v(m);
    for (edge &i : v)
        cin >> i.s >> i.t >> i.w;
    sort(v.begin(), v.end());
    for (const edge &i : v)
        if (d1.find(i.s) != d1.find(i.t))
        {
            d1.unite(i.s, i.t);
            mn += i.w;
        }
    reverse(v.begin(), v.end());
    for (const edge &i : v)
        if (d2.find(i.s) != d2.find(i.t))
        {
            d2.unite(i.s, i.t);
            mx += i.w;
        }
    cout << (mn <= k && k <= mx ? "TAK\n" : "NIE\n");
    return 0;
}