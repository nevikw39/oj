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
    static constexpr int64_t NEG_INF = numeric_limits<int64_t>::min() >> 1;

public:
    long long maxSumTrionic(const vector<int> &nums)
    {
        return ranges::fold_left(nums | views::pairwise, array{NEG_INF, NEG_INF, NEG_INF, NEG_INF}, [](auto &&dp, auto &&pair)
            {
                const auto [former, latter] = pair;
                if (former < latter)
                {
                    const auto trionic = max(dp[1], dp[2]) + latter;
                    return array{max(dp[0], static_cast<int64_t>(former)) + latter, NEG_INF, trionic, max(trionic, dp.back())};
                }
                else if (former > latter)
                    return array{NEG_INF, max(dp[0], dp[1]) + latter, NEG_INF, dp.back()};
                else
                    return array{NEG_INF, NEG_INF, NEG_INF, dp.back()};
            }
        ).back();
    }
};
