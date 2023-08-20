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
private:
    vector<int> topo_sort(_hash<int, vector<int>> &g)
    {
        vector<int> y;
        _hash<int, int> deg;
        for (const auto &[_, i] : g)
            for (int j : i)
                ++deg[j];
        queue<int> q;
        for (const auto &[i, _] : g)
            if (deg.find(i) == deg.end())
                q.emplace(i);
        while (q.size())
        {
            int f = q.front();
            q.pop();
            y.push_back(f);
            for (int i : g[f])
                if (!--deg[i])
                    q.push(i);
        }
        return y;
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        vector<vector<int>> groups(m);
        for (int i = 0; i < n; i++)
        {
            if (!~group[i])
            {
                group[i] = m++;
                groups.emplace_back();
            }
            groups[group[i]].push_back(i);
        }
        _hash<int, vector<int>> g_group;
        for (auto &gp : groups)
        {
            _hash<int, vector<int>> g;
            for (int i : gp)
                for (int j : beforeItems[i])
                    if (group[i] != group[j])
                        g_group[group[j]].push_back(group[i]);
                    else
                        g[j].push_back(i);
            for (int i : gp)
                if (g.find(i) == g.end())
                    g[i] = vector<int>();
            auto topo = topo_sort(g);
            if (topo.size() != gp.size())
                return {};
            gp = topo;
        }
        for (int i = 0; i < m; i++)
            if (g_group.find(i) == g_group.end())
                g_group[i] = vector<int>();
        auto topo = topo_sort(g_group);
        if (topo.size() != m)
            return {};
        vector<int> y;
        for (int i : topo)
            for (int j : groups[i])
                y.push_back(j);
        return y;
    }
};
