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
    vector<vector<int>> g;
    vector<array<int, 26>> dp;
    vector<int> v;
    bool dfs(const string &s, int x)
    {
        if (!~v[x])
            return false;
        if (v[x])
            return true;
        v[x] = -1;
        for (int i : g[x])
            if (!dfs(s, i))
                return false;
            else
                for (int k = 0; k < 26; k++)
                    dp[x][k] = max(dp[x][k], dp[i][k]);
        ++dp[x][s[x] - 'a'];
        v[x] = 1;
        return true;
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.length();
        g.assign(n, {});
        dp.assign(n, {});
        v.assign(n, 0);
        for (const auto &i : edges)
            g[i[0]].push_back(i[1]);
        int y = 0;
        for (int i = 0; i < n; i++)
            if (!dfs(colors, i))
                return -1;
            else
                for (int k = 0; k < 26; k++)
                    y = max(y, dp[i][k]);
        return y;
    }
};
