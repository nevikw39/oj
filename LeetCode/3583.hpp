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
    static constexpr int N = 1e5 + 1, MOD = 1e9 + 7;
    constexpr int binexp(int64_t a, int n)
    {
        int64_t prod = 1;
        while (n)
        {
            if (n & 1)
                (prod *= a) %= MOD;
            (a *= a) %= MOD;
            n >>= 1;
        }
        return prod;
    }
    constexpr int64_t inv(int x) { return binexp(x, MOD - 2);}

public:
    int specialTriplets(const vector<int> &nums)
    {
        int cnt = 0, zero = 0;
        array<int, N> cnt_a{}, cnt_b{};
        for (int i : nums)
        {
            if (!i)
            {
                ++zero;
                continue;
            }
            if (~i & 1)
                (cnt += cnt_a[i >> 1]) %= MOD;
            ++cnt_b[i];
            if (i << 1 < N)
                (cnt_a[i] += cnt_b[i << 1]) %= MOD;
        }
        if (zero >= 3)
            (cnt += zero * (zero - 1LL) % MOD * inv(2) % MOD * (zero - 2LL) % MOD * inv(3) % MOD) %= MOD;
        return cnt;
    }
};
