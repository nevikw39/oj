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
    vector<vector<pair<int, int>>> g;
    vector<int> d;

    void dijkstra(int n, int s, int t)
    {
        _heap<pair<int64_t, int>> pq;
        vector<decltype(pq)::point_iterator> itrs(n);
        itrs[s] = pq.push({d[s] = 0, s});
        while (pq.size())
        {
            if (pq.top().ND == t)
                break;
            const int t = pq.top().ND;
            pq.pop();
            itrs[t] = nullptr;
            for (const auto &[i, w] : g[t])
                if (d[i] > d[t] + w)
                {
                    if (itrs[i] != nullptr)
                        pq.modify(itrs[i], {d[i] = d[t] + w, i});
                    else
                        itrs[i] = pq.push({d[i] = d[t] + w, i});
                }
        }
    }

public:
    int minCost(int n, const vector<vector<int>> &edges)
    {
        g.assign(n, {});
        d.assign(n, numeric_limits<int>::max());
        for (const auto &e : edges)
        {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2] << 1);
        }
        dijkstra(n, 0, n - 1);
        return d.back() != numeric_limits<int>::max() ? d.back() : -1;
    }
};
