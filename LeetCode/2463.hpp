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
    static inline int64_t bwmin(int64_t x, int64_t y) { return y ^ ((x ^ y) & -(x < y)); }
    static inline int64_t bwabs(int64_t x) { return (x ^ (x >> ((sizeof(int64_t) << 3) - 1))) - (x >> ((sizeof(int64_t) << 3) - 1)); }

public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        ranges::sort(robot);
        ranges::sort(factory);
        vector<int> factory_flatten;
        for (auto [pos, lmt] : factory | views::transform([](const auto &x){ return pair{x[0], x[1]}; }))
            for (int i : views::iota(0, lmt))
                factory_flatten.push_back(pos);
        const int n = robot.size(), m = factory_flatten.size();
        vector<int64_t> dp(m), rolling(m);
        for (int i : views::iota(0, n) | views::reverse)
        {
            for (int j : views::iota(0, m) | views::reverse)
                dp[j] = bwmin(bwabs(robot[i] - factory_flatten[j]) + (j + 1 < m ? rolling[j + 1] : i + 1 < n ? numeric_limits<int64_t>::max() >> 1 : 0),
                              j + 1 < m ? dp[j + 1] : numeric_limits<int64_t>::max() >> 1);
            rolling = dp;
        }
        return dp.front();
    }
};
