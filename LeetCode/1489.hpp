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

struct disjoint_set
{
    int n, g;
    vector<int> p, sz;
    disjoint_set(int _n) : n(_n), g(_n), p(n), sz(n, 1) { iota(ALL(p), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        --g;
        return true;
    }
};

class Solution
{
private:
    using edge = tuple<int, int, int>;

    vector<bool> critical, pseudo, vis;

    vector<int> dep, low;
    int tarjan_dfs(const vector<vector<pair<int, int>>> &g, int x, int p = -1, int edge = -1)
    {
        vis[x] = true;
        low[x] = dep[x] = ~p ? dep[p] + 1 : 0;
        for (auto [i, e] : g[x])
            if (i != p)
            {
                if (vis[i])
                    low[x] = min(low[x], dep[i]);
                else
                    low[x] = min(low[x], tarjan_dfs(g, i, x, e));
            }
        if (~p && low[x] == dep[x] && !pseudo[edge])
            critical[edge] = true;
        return low[x];
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        disjoint_set dsu(n);
        low.resize(n);
        dep.resize(n);
        int m = edges.size();
        critical.resize(m);
        pseudo.resize(m);
        map<int, vector<edge>> mp;
        for (int i = 0; i < m; i++)
            mp[edges[i][2]].emplace_back(edges[i][0], edges[i][1], i);
        for (auto [_, edges] : mp)
        {
            map<pair<int, int>, vector<int>> mp;
            for (auto [u, v, i] : edges)
            {
                int pu = dsu.find(u), pv = dsu.find(v);
                if (pu != pv)
                    mp[minmax(pu, pv)].push_back(i);
            }
            edges.clear();
            vector<vector<pair<int, int>>> g(n);
            for (auto [p, v] : mp)
            {
                if (v.size() > 1)
                    for (int i : v)
                        pseudo[i] = true;
                auto [pu, pv] = p;
                g[pu].emplace_back(pv, v.front());
                g[pv].emplace_back(pu, v.front());
                edges.emplace_back(pu, pv, v.front());
                dsu.unite(pu, pv);
            }
            vis.assign(n, false);
            for (auto [u, v, i] : edges)
                if (!vis[u])
                    tarjan_dfs(g, u);
            for (auto [u, v, i] : edges)
                if (!critical[i])
                    pseudo[i] = true;
        }
        vector<vector<int>> y(2);
        for (int i = 0; i < m; i++)
            if (critical[i])
                y.front().push_back(i);
            else if (pseudo[i])
                y.back().push_back(i);
        return y;
    }
};
