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
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        if (n == 1)
            return 1;
        vector<int> deg(n);
        ranges::fill(deg, 0);
        vector<vector<int>> g(n);
        for (const auto &i : edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            ++deg[i[0]];
            ++deg[i[1]];
        }
        queue<int> q;
        for (int i : views::iota(0, n))
            if (deg[i] == 1)
                q.push(i);
        int components = 0;
        while (q.size())
        {
            int f = q.front();
            q.pop();
            --deg[f];
            if (!(values[f] % k))
                ++components;
            for (int i : g[f])
                if (deg[i])
                {
                    (values[i] += values[f]) %= k;
                    if (--deg[i] == 1)
                        q.push(i);
                }
        } 
        return components;
    }
};
