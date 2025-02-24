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
    vector<vector<int>> t;
    vector<int> d, amt;
    int b;

    int dfs(int x = 0, int p = -1, int dep = 0)
    {
        int y;
        if (t[x].size() == 1 && dep)
            y = 0;
        else
        {
            y = numeric_limits<int>::min();
            for (int i : t[x])
                if (i != p)
                {
                    y = max(y, dfs(i, x, dep + 1));
                    d[x] = min(d[x], d[i] + 1);
                }
        }
        if (d[x] > dep)
            y += amt[x];
        else if (d[x] == dep)
            y += amt[x] >> 1;
        return y;
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        const int n = edges.size() + 1;
        t.assign(n, {});
        for (const auto &e : edges)
        {
            t[e.front()].push_back(e.back());
            t[e.back()].push_back(e.front());
        }
        d.assign(n, n);
        d[b = bob] = 0;
        amt = move(amount);
        return dfs();
    }
};
