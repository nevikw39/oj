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
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        vector<vector<int>> dp(target + 1, vector<int>(n, INT_MAX >> 1));
        if (houses[0])
            dp[1][houses[0] - 1] = 0;
        else
            for (int k = 0; k < n; k++)
                dp[1][k] = cost[0][k];
        for (int i = 1; i < m; i++)
        {
            vector<vector<int>> rolling(target + 1, vector<int>(n, INT_MAX >> 1));
            for (int j = 1; j <= target && j <= i + 1; j++)
                for (int k = 0; k < n; k++)
                {
                    if (houses[i] && houses[i] != k + 1)
                        continue;
                    int r = INT_MAX >> 1;
                    for (int l = 0; l < n; l++)
                        if (l != k)
                            r = min(r, dp[j - 1][l]);
                        else
                            r = min(r, dp[j][l]);
                    rolling[j][k] = r + (houses[i] ? 0 : cost[i][k]);
                }
            swap(dp, rolling);
        }
        int y = *min_element(ALL(dp.back()));
        return y < INT_MAX >> 1 ? y : -1;
    }
};
