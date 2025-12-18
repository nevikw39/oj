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
    long long maxProfit(const vector<int> &prices, const vector<int> &strategy, int k)
    {
        const int n = prices.size();
        vector<int64_t> prices_sum(n), profits(n);
        prices_sum[0] = prices[0];
        profits[0] = prices[0] * strategy[0];
        for (int i : views::iota(1, n))
        {
            prices_sum[i] = prices_sum[i - 1] + prices[i];
            profits[i] = profits[i - 1] + prices[i] * strategy[i];
        }
        int64_t y = profits.back();
        y = max(y, prices_sum[k - 1] - prices_sum[k - 1 - (k >> 1)] + profits.back() - profits[k - 1]);
        for (int i : views::iota(k, n))
            y = max(y, profits[i - k] + prices_sum[i] - prices_sum[i - (k >> 1)] + profits.back() - profits[i]);
        return y;
    }
};
