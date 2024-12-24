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
    void bfs(const vector<vector<int>> &g, vector<int> &d, const int s = 0)
    {
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (q.size())
        {
            const int f = q.front();
            q.pop();
            for (const int &i : g[f])
                if (d[i] == -1)
                {
                    d[i] = d[f] + 1;
                    q.push(i);
                }
        }
    }

    int diamter(const int n, const vector<vector<int>> &g)
    {
        vector<int> d(n, -1);
        bfs(g, d);
        const int s = ranges::max_element(d) - ranges::begin(d);
        ranges::fill(d, -1);
        bfs(g, d, s);
        return ranges::max(d);
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        const int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for (const auto &e : edges1)
        {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (const auto &e : edges2)
        {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        const int d1 = diamter(n, g1), d2 = diamter(m, g2);
        return max({d1, d2, (d1 + 1 >> 1) + 1 + (d2 + 1 >> 1)});
    }
};
