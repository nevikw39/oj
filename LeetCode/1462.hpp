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
    static constexpr int N = 100;

    vector<vector<int>> g, gp;

    struct kosaraju
    {
        int cnt;
        vector<bool> v;
        vector<int> scc;
        deque<int> dq;

        void dfs_rev(int x, const vector<vector<int>> &gp)
        {
            v[x] = true;
            for (int i : gp[x])
                if (!v[i])
                    dfs_rev(i, gp);
            dq.push_front(x);
        }

        void dfs(int x, int s, const vector<vector<int>> &g)
        {
            scc[x] = s;
            for (int i : g[x])
                if (!~scc[i])
                    dfs(i, s, g);
        }

        kosaraju(int n, const vector<vector<int>> &g, const vector<vector<int>> &gp) : cnt(0), v(n), scc(n, -1)
        {
            for (int i = 0; i < n; i++)
                if (!v[i])
                    dfs_rev(i, gp);
            for (int i : dq)
                if (!~scc[i])
                    dfs(i, cnt++, g);
        }
    };

    struct reachable_nodes
    {
        vector<vector<int>> _g;
        vector<bitset<N>> v;

        void dfs(int x)
        {
            v[x][x] = true;
            for (int i : _g[x])
            {
                if (v[i].none())
                    dfs(i);
                v[x] |= v[i];
            }
        }

        reachable_nodes(int n, int cnt, const vector<vector<int>> &g, const vector<int> &scc) : _g(cnt), v(cnt)
        {
            for (int i = 0; i < n; i++)
                for (int j : g[i])
                    if (scc[i] != scc[j])
                        _g[scc[i]].push_back(scc[j]);
            for (int i = 0; i < cnt; i++)
                if (v[i].none())
                    dfs(i);
        }
    };

public:
    vector<bool> checkIfPrerequisite(int numCourses, const vector<vector<int>> &prerequisites, const vector<vector<int>> &queries)
    {
        g.assign(numCourses, {});
        gp.assign(numCourses, {});
        for (const auto &edge : prerequisites)
        {
            g[edge.front()].push_back(edge.back());
            gp[edge.back()].push_back(edge.front());
        }
        kosaraju ksrj(numCourses, g, gp);
        reachable_nodes rn(numCourses, ksrj.cnt, g, ksrj.scc);
        const int q = queries.size();
        vector<bool> y(q);
        for (int i = 0; i < q; i++)
            y[i] = rn.v[ksrj.scc[queries[i].front()]][ksrj.scc[queries[i].back()]];
        return y;
    }
};
