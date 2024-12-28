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
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int sum1 = accumulate(nums.begin(), nums.begin() + k, 0), sum2 = accumulate(nums.begin() + k, nums.begin() + 2 * k, 0), sum3 = accumulate(nums.begin() + 2 * k, nums.begin() + 3 * k, 0), // sliding windows
            max1 = sum1, max2 = sum1 + sum2, max3 = sum1 + sum2 + sum3,
            start1{0};
        pair<int, int> start2{0, k};
        tuple<int, int, int> start3{0, k, 2 * k};
        for (int i : views::iota(k * 3, static_cast<int>(nums.size())))
        {
            sum1 += nums[i - 2 * k] - nums[i - 3 * k];
            sum2 += nums[i - k] - nums[i - 2 * k];
            sum3 += nums[i] - nums[i - k];
            if (max1 < sum1)
            {
                max1 = sum1;
                start1 = i - 3 * k + 1;
            }
            if (max2 < max1 + sum2)
            {
                max2 = max1 + sum2;
                start2 = {start1, i - 2 * k + 1};
            }
            if (max3 < max2 + sum3)
            {
                max3 = max2 + sum3;
                start3 = {start2.ST, start2.ND, i - k + 1};
            }
        }
        return {get<0>(start3), get<1>(start3), get<2>(start3)};
    }
};
