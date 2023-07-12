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
    vector<vector<int>> gp;
    vector<bool> v;
    vector<int> scc;
    deque<int> dq;
    _hash<int, int> sz;

    void dfs_rev(int x)
    {
        v[x] = true;
        for (int i : gp[x])
            if (!v[i])
                dfs_rev(i);
        dq.push_front(x);
    }

    void dfs(const vector<vector<int>> &g, int x, int s)
    {
        scc[x] = s;
        ++sz[s];
        for (int i : g[x])
            if (!~scc[i])
                dfs(g, i, s);
    }

    int kosaraju(const vector<vector<int>> &g, int n)
    {
        for (int i = 0; i < n; i++)
            if (!v[i])
                dfs_rev(i);
        int cnt = 0;
        for (int i : dq)
            if (!~scc[i])
                dfs(g, i, cnt++);
        return cnt;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        gp.assign(n, {});
        v.assign(n, false);
        scc.assign(n, -1);
        dq.clear();
        sz.clear();
        for (int i = 0; i < n; i++)
            for (int j : graph[i])
                gp[j].push_back(i);
        // kosaraju(graph, n);
        for (int i = 0; i < n; i++)
            if (!v[i])
                dfs_rev(i);
        for (int i : dq)
            scc[i] = all_of(ALL(graph[i]), [&](int x){ return ~scc[x]; }) ?: -1;
        vector<int> y;
        for (int i = 0; i < n; i++)
            if (~scc[i])
                y.push_back(i);
        return y;
    }
};
