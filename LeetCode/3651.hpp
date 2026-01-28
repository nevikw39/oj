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
    static constexpr int INF = numeric_limits<int>::max();

public:
    int minCost(const vector<vector<int>> &grid, int k)
    {
        const int n = grid.size(), m = grid.front().size();
        const int mx = ranges::max(grid | views::join);
        vector d(n, vector<int>(m, INF));
        d.front().front() = 0;
        int y = INF;
        for (int t : views::iota(0, k + 1))
        {
            for (int i : views::iota(0, n))
                for (int j : views::iota(0, m))
                {
                    if (i)
                        d[i][j] = min(d[i][j], d[i - 1][j] + grid[i][j]);
                    if (j)
                        d[i][j] = min(d[i][j], d[i][j - 1] + grid[i][j]);
                }
            if (t == k)
                break;
            vector<int> suf_min(mx + 1, INF);
            for (int i : views::iota(0, n))
                for (int j : views::iota(0, m))
                    suf_min[grid[i][j]] = min(suf_min[grid[i][j]], d[i][j]);
            for (auto &&[latter, former] : suf_min | views::reverse | views::pairwise)
                former = min(former, latter);
            vector p(n, vector<int>(m, INF));
            for (int i : views::iota(0, n))
                for (int j : views::iota(0, m))
                    p[i][j] = min(p[i][j], suf_min[grid[i][j]]);
            d = move(p);
            y = min(y, d.back().back());
        }
        return min(y, d.back().back());
    }
};
