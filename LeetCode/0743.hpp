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
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> g(n);
        for (const auto &i : times)
            g[i[0] - 1].emplace_back(i[1] - 1, i[2]);
        vector<int> d(n, INT_MAX);
        _heap<pair<int, int>> pq;
        vector<decltype(pq)::point_iterator> itrs(n, nullptr);
        --k;
        itrs[k] = pq.push({d[k] = 0, k});
        while (pq.size())
        {
            int t = pq.top().ND;
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
        int y = 0;
        for (const int &i : d)
            if (i < INT_MAX)
                y = max(y, i);
            else
                return -1;
        return y;
    }
};
