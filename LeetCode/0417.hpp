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
    int m, n;
    void dfs(const vector<vector<int>> &h, int i, int j, vector<vector<bool>> &v)
    {
        static const pair<int, int> dirs[] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        v[i][j] = true;
        for (const auto [di, dj] : dirs)
        {
            int ip = i + di, jp = j + dj;
            if (0 <= ip && ip < m && 0 <= jp && jp < n && !v[ip][jp] && h[ip][jp] >= h[i][j])
                dfs(h, ip, jp, v);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights.front().size();
        vector<vector<bool>> p(m, vector<bool>(n)), a(m, vector<bool>(n));
        for (int j = 0; j < n; j++)
        {
            dfs(heights, 0, j, p);
            dfs(heights, m - 1, j, a);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(heights, i, 0, p);
            dfs(heights, i, n - 1, a);
        }
        vector<vector<int>> y;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (p[i][j] && a[i][j])
                    y.push_back({i, j});
        return y;
    }
};
