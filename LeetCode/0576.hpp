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
    static constexpr int M = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int x)
    {
        if (!~i || i == m || !~j || j == n)
            return 1;
        if (!x)
            return 0;
        if (~dp[i][j][x])
            return dp[i][j][x];
        static constexpr pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        dp[i][j][x] = 0;
        for (const auto &[di, dj] : dirs)
            (dp[i][j][x] += dfs(i + di, j + dj, x - 1)) %= M;
        return dp[i][j][x];
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        this->m = m;
        this->n = n;
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, maxMove);
    }
};
