/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
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
    vector<int> p, r;
    disjoint_set(int _n) : n(_n)
    {
        g = n;
        r = vector<int>(n, 1);
        for (int i = 0; i < n;)
            p.push_back(i++);
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
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
        return true;
    }
};

struct edge
{
    int a, b, w;
    constexpr const bool operator<(const edge &x) const
    {
        return w < x.w;
    }
};

int
main()
{
    nevikw39;
    int n, m, r = 0;
    cin >> n >> m;
    disjoint_set dsu(n);
    vector<edge> v(m);
    for (edge &i : v)
        cin >> i.a >> i.b >> i.w;
    sort(ALL(v));
    for (const edge &i : v)
        if (dsu.unite(i.a, i.b))
            r += i.w;
    if (dsu.g > 1)
        r = -1;
    cout << r << '\n';
    return 0;
}