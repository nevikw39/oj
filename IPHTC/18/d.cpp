#include <bits/extc++.h>

using namespace std;

int inline sq(int x) { return x * x; }

struct disjoint_set
{
    int n, g;
    vector<int> p, s;
    disjoint_set(int _n) : n(_n), g(_n)
    {
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
        s.resize(n, 1);
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (s[a] < s[b])
                swap(a, b);
            p[b] = a;
            s[a] += s[b];
            --g;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, r, k, a = 0, b = 0;
        cin >> n >> r >> k;
        r *= r;
        vector<pair<int, int>> pts(n);
        for (auto &i : pts)
            cin >> i.first >> i.second;
        disjoint_set dsu(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (sq(pts[i].first - pts[j].first) + sq(pts[i].second - pts[j].second) <= r)
                    dsu.unite(i, j);
        vector<bool> v(n);
        for (int i = 0; i < n; i++)
        {
            r = dsu.find(i);
            if (v[r])
                continue;
            v[r] = true;
            dsu.s[r] < k ? ++a : ++b;
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}
