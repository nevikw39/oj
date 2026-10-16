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

    struct bit
    {
        int n;
        vector<int> v;
        bit(int _n) : n(_n), v(_n + 1) {}

        static constexpr int lowbit(int x) { return x & -x; }

        int query(int x)
        {
            int y = 0;
            for (; x; x -= lowbit(x))
                (y += v[x]) %= MOD;
            return y;
        }

        void update(int x, int val = 1)
        {
            for (; x <= n; x += lowbit(x))
                (v[x] += val) %= MOD;
        }
    };

public:
    int sumCounts(const vector<int> &nums)
    {
        const int n = nums.size();
        bit ft_a(n), ft_b(n);
        _hash<int, int> hm;
        int y = 0, sum = 0;
        for (int r : views::iota(0, n))
        {
            const int l = hm[nums[r]], prv = (ft_a.query(r + 1) * (r + 1LL) - ft_b.query(r + 1)) - (ft_a.query(l) * (l + 0LL) - ft_b.query(l));
            (y += (sum += ((prv << 1) % MOD + (r - l + 1)) % MOD) %= MOD) %= MOD;
            ft_a.update(l + 1);
            ft_a.update(r + 2, -1);
            ft_b.update(l + 1, l);
            ft_b.update(r + 2, -r - 1);
            hm[nums[r]] = r + 1;
        }
        return y;
    }
};
