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
    long long minimumCost(const vector<int> &nums, int k, int dist)
    {
        const auto nums_indexed = views::zip(nums | views::drop(1), views::iota(0));
        _tree<pair<int, int>> t;
        for (const auto i : nums_indexed | views::take(dist + 1))
            t.insert(i);
        const auto itr = t.find_by_order(k - 1);
        int64_t sum = 0;
        for (const auto jtr : views::iota(t.begin(), itr))
            sum += jtr->ST;
        int64_t mn = sum;
        for (const auto sliding_window : nums_indexed | views::slide(dist + 2))
        {
            const auto sliding_window_original = sliding_window | views::keys;
            if (t.order_of_key(sliding_window.front()) < k - 1)
            {
                sum -= sliding_window_original.front();
                sum += t.find_by_order(k - 1)->ST;
            }
            t.erase(sliding_window.front());
            t.insert(sliding_window.back());
            if (t.order_of_key(sliding_window.back()) < k - 1)
            {
                sum += sliding_window_original.back();
                sum -= t.find_by_order(k - 1)->ST;
            }
            mn = min(mn, sum);
        }
        return nums.front() + mn;
    }
};
