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
    int n, m;
    vector<vector<int>> ps;
    vector<vector<vector<int>>> dp;

    int cnt(int x1, int y1, int x2, int y2) { return ps[x2][y2] - (x1 ? ps[x1 - 1][y2] : 0) - (y1 ? ps[x2][y1 - 1] : 0) + (x1 && y1 ? ps[x1 - 1][y1 - 1] : 0); }

    int f(int i, int j, int k)
    {
        if (!k)
            return 1;
        if (~dp[i][j][k])
            return dp[i][j][k];
        int y = 0;
        for (int ip = i + 1; ip < m; ip++)
            if (cnt(i, j, ip - 1, n - 1) && cnt(ip, j, m - 1, n - 1))
                (y += f(ip, j, k - 1)) %= M;
        for (int jp = j + 1; jp < n; jp++)
            if (cnt(i, j, m - 1, jp - 1) && cnt(i, jp, m - 1, n - 1))
                (y += f(i, jp, k - 1)) %= M;
        return dp[i][j][k] = y;
    }

public:
    int ways(vector<string> &pizza, int k)
    {
        m = pizza.size(), n = pizza.front().length();
        ps.assign(m, vector<int>(n));
        dp.assign(m, vector(n, vector<int>(k, -1)));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ps[i][j] = (i ? ps[i - 1][j] : 0) + (j ? ps[i][j - 1] : 0) - (i && j ? ps[i - 1][j - 1] : 0) + (pizza[i][j] == 'A');
        return f(0, 0, k - 1);
    }
};
