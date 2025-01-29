/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#define __builtin_sprintf sprintf
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
    struct disjoint_set
    {
        int n, g;
        vector<int> p, sz;
        disjoint_set(int _n) : n(_n), g(n), p(n), sz(n, 1) { iota(ALL(p), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        bool unite(int x, int y)
        {
            x = find(x);
            y = find(y);
            if (x == y)
                return false;
            --g;
            if (sz[x] > sz[y])
                swap(x, y);
            sz[p[x] = y] += sz[x];
            return true;
        }
        bool same(int x, int y) { return find(x) == find(y); }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        const int n = edges.size();
        disjoint_set dsu(n);
        for (const auto &e : edges)
            if (!dsu.unite(e.front() - 1, e.back() - 1))
                return e;
        assert(false);
    }
};
