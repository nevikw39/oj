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
    vector<int> w;

    int query(int l, int r) const { return l <= r ? ranges::upper_bound(w, r) - ranges::lower_bound(w, l) : 0; }

public:
    int maxWalls(const vector<int> &robots, const vector<int> &distance, const vector<int> &walls)
    {
        auto rd = views::zip(robots, distance) | ranges::to<vector<pair<int, int>>>();
        ranges::sort(rd);
        rd.emplace_back(numeric_limits<int>::max(), 0);
        w = walls;
        ranges::sort(w);
        const int n = rd.size() - 1;
        vector<array<int, 2>> dp(n);
        dp[0] = {query(apply(minus{}, rd[0]), rd[0].ST), query(rd[0].ST, min(apply(plus{}, rd[0]), rd[1].ST - 1))};
        for (int i : views::iota(1, n))
        {
            const auto [r, d] = rd[i];
            dp[i][1] = ranges::max(dp[i - 1]) + query(r, min(r + d, rd[i + 1].ST - 1));
            const int l = max(r - d, rd[i - 1].ST + 1);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - query(l, min(apply(plus{}, rd[i - 1]), r - 1))) + query(l, r);
        }
        return ranges::max(dp.back());
    }
};
