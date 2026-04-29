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
    long long maximumScore(const vector<vector<int>> &grid)
    {
        const int n = grid.size();
        vector<array<int64_t, 2>> dp(n + 1, {0, 0});
        for (int j : views::iota(1, n))
        {
            vector<array<int64_t, 2>> rolling(n + 1, {0, 0});
            for (int i : views::iota(0, n + 1))
            {
                int64_t sum = 0, prv = 0;
                for (int k : views::iota(0, i))
                    sum += grid[k][j];
                for (int k : views::iota(0, n + 1))
                {
                    if (k && k <= i)
                        sum -= grid[k - 1][j];
                    if (k > i)
                        prv += grid[k - 1][j - 1];
                    rolling[k][0] = max({rolling[k][0], prv + dp[i][0], dp[i][1]});
                    rolling[k][1] = max({rolling[k][1], sum + dp[i][1], sum + prv + dp[i][0]});
                }
            }
            dp = move(rolling);
        }
        return ranges::max(dp | views::values);
    }
};
