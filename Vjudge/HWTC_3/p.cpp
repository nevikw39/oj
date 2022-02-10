/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct disjoint_set
{
    int n, g;
    vector<int> p, s;

    disjoint_set(int _n) : n(_n), g(_n)
    {
        s.resize(n, 1);
        p.resize(n);
        iota(ALL(p), 0);
    }

    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        --g;
        if (s[x] < s[y])
            swap(x, y);
        p[y] = x;
        s[x] += s[y];
        return true;
    }

    bool inline same(int x, int y) { return find(x) == find(y); }
};

struct edge
{
    int u, v;
    double w;
    bool operator<(const edge &x) { return w < x.w; }
};

inline double square(double x) { return x * x; }

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<double, double>> v(n);
        for (auto &i : v)
            cin >> i.ST >> i.ND;
        vector<edge> edges;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                edges.push_back({i, j, sqrt(square(v[i].ST - v[j].ST) + square(v[i].ND - v[j].ND))});
        sort(ALL(edges));
        disjoint_set dsu(n);
        double r = 0;
        for (const edge &e : edges)
        {
            if (dsu.unite(e.u, e.v))
                r += e.w;
            if (dsu.g == 1)
                break;
        }
        cout << fixed << setprecision(2) << r << '\n';
        if (t)
            cout << '\n';
    }
    return 0;
}