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
    int row, col;
    vector<vector<int>> g;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j1, int j2)
    {
        if (~dp[i][j1][j2])
            return dp[i][j1][j2];
        dp[i][j1][j2] = 0;
        if (row - i > 1)
            for (int k1 = -1; k1 <= 1; k1++)
                if (0 <= j1 + k1 && j1 + k1 < col)
                    for (int k2 = -1; k2 <= 1; k2++)
                        if (0 <= j2 + k2 && j2 + k2 < col && j1 + k1 <= j2 + k2)
                            dp[i][j1][j2] = max(dp[i][j1][j2], dfs(i + 1, j1 + k1, j2 + k2));
        return dp[i][j1][j2] += j1 != j2 ? g[i][j1] + g[i][j2] : g[i][j1];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid.front().size();
        g = move(grid);
        dp.assign(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return dfs(0, 0, col - 1);
    }
};
