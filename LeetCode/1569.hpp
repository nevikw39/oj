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
    static constexpr int MOD = 1e9 + 7, N = 1001;

    static constexpr auto binexp = [](int x, int k)
    {
        int y = 1;
        while (k)
        {
            if (k & 1)
                y = 1LL * y * x % MOD;
            x = 1LL * x * x % MOD;
            k >>= 1;
        }
        return y;
    };
    static constexpr auto inv = [](int x) { return binexp(x, MOD - 2); };

    static constexpr array<int, N> fact = []()
    {
        array<int, N> a;
        a.front() = 1;
        for (int i : views::iota(1, N))
            a[i] = 1LL * a[i - 1] * i % MOD;
        return a;
    }(),
                                  fact_inv = []()
    {
        array<int, N> a;
        a.back() = inv(fact.back());
        for (int i : views::iota(1, N) | views::reverse)
            a[i - 1] = 1LL * a[i] * i % MOD;
        return a;
    }();

    static constexpr int C(int n, int k) { return 1LL * fact[n] * fact_inv[k] % MOD * fact_inv[n - k] % MOD; }

    static int dfs(const vector<int> &x)
    {
        const int n = x.size();
        if (n < 1)
            return 1;
        vector<int> tl, tr;
        for (int i : x | views::drop(1))
            if (i < x.front())
                tl.push_back(i);
            else
                tr.push_back(i);
        const int l = dfs(tl), r = dfs(tr);
        return 1LL * l * r % MOD * C(n - 1, tl.size()) % MOD;
    }

public:
    int numOfWays(const vector<int> &nums) { return (dfs(nums) - 1) % MOD; }
};
