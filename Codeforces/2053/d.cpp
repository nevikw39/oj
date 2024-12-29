/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

constexpr int MOD = 998244353;

inline int binexp(int64_t x, int n, int m = MOD)
{
    int64_t y = 1;
    for (x %= m; n; (x *= x) %= m, n >>= 1)
        if (n & 1)
            (y *= x) %= m;
    return y;
}

inline int inv(int x, int m = MOD) { return binexp(x, m - 2, m); }

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), c(n), d(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    ranges::partial_sort_copy(a, c);
    ranges::partial_sort_copy(b, d);
    int64_t prod = 1;
    for (int i : views::iota(0, n))
        (prod *= min(c[i], d[i])) %= MOD;
    cout << prod << ' ';
    while (q--)
    {
        char op;
        int x;
        cin >> op >> x;
        --x;
        if (op == '1')
        {
            const auto itr = --ranges::upper_bound(c, a[x]++);
            if (*itr < d[itr - ranges::begin(c)])
                (prod *= inv(*itr) * (*itr + INT64_C(1)) % MOD) %= MOD;
            ++*itr;
        }
        else
        {
            const auto itr = --ranges::upper_bound(d, b[x]++);
            if (*itr < c[itr - ranges::begin(d)])
                (prod *= inv(*itr) * (*itr + INT64_C(1)) % MOD) %= MOD;
            ++*itr;
        }
        cout << prod << ' ';
    }
    cout << '\n';
}

int main()
{
    nevikw39;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
