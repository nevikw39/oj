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
    static constexpr int MOD = 1e9 + 7;

public:
    int countPartitions(const vector<int> &nums, int k)
    {
        const int n = nums.size();
        vector<int> dp(n), ps(n + 1);
        ps.front() = 1;
        deque<int> mn, mx;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (mx.size() && nums[mx.back()] <= nums[i])
                mx.pop_back();
            mx.push_back(i);
            while (mn.size() && nums[mn.back()] >= nums[i])
                mn.pop_back();
            mn.push_back(i);
            while (mx.size() && mn.size() && nums[mx.front()] - nums[mn.front()] > k)
            {
                if (mx.front() == j)
                    mx.pop_front();
                if (mn.front() == j)
                    mn.pop_front();
                ++j;
            }
            dp[i] = (ps[i] - (j ? ps[j - 1] : 0) + MOD) % MOD;
            ps[i + 1] = (ps[i] + dp[i]) % MOD;
        }
        return dp.back();
    }
};
