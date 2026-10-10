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
    long long minSumSquareDiff(const vector<int> &nums1, const vector<int> &nums2, int k1, int k2)
    {
        const auto diff = views::zip_transform(minus{}, nums1, nums2) | views::transform(static_cast<int (*)(int)>(&abs));
        const int mx = ranges::max(diff);
        if (!mx)
            return 0;
        vector<int> cnt(mx);
        for (int d : diff)
            if (d)
                ++cnt[d - 1];
        int k = k1 + k2;
        for (auto [prv, nxt] : cnt | views::pairwise | views::reverse)
        {
            const int mn = min(k, nxt);
            nxt -= mn;
            prv += mn;
            if (!(k -= mn))
                break;
        }
        cnt.front() -= min(k, cnt.front());
        return ranges::fold_left(views::iota(0, mx), 0LL, [&](int64_t sum, int i){ return sum + (i + 1LL) * (i + 1) * cnt[i]; });
    }
};
