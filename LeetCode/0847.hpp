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
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> d(n, vector<int>(n, INT_MAX >> 1));
        for (int i = 0; i < n; i++)
            for (const int &j : graph[i])
                d[i][j] = 1;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX >> 1));
        for (int i = 0; i < n; i++)
            dp[1 << i][i] = 0;
        for (int i = 1; i < 1 << n; i++)
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    for (int k = 0; k < n; k++)
                        if (i & (1 << k))
                            dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + d[k][j]);
        int y = INT_MAX;
        for (const int &i : dp[(1 << n) - 1])
            y = min(y, i);
        return y;
    }
};
