#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

int n, m;

int *p;
int find(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}
void unite(int x, int y)
{
    // cerr << '\t' << x << ' ' << y << '\n';
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    p[y] = x;
}

struct edge
{
    int a, b, c;
    bool operator<(const edge &x) const
    {
        return c < x.c;
    }
};

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        int x = 0, t = n;

        p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = i;

        vector<edge> v;
        while (m--)
        {
            int i, j, c;
            cin >> i >> j >> c;
            v.push_back({i, j, c});
        }
        sort(v.begin(), v.end());
        for (const auto &i : v)
        {
            if (find(i.a) == find(i.b))
                continue;
            unite(i.a, i.b);
            x += i.c;
            t--;
        }
        cout << (t == 1 ? x : -1) << '\n';

        delete[] p;
    }
    return 0;
}