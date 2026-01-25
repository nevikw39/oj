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

void solve()
{
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<int> x(n), y(n);
    std::copy_n(istream_iterator<int>(cin), n, x.begin());
    std::copy_n(istream_iterator<int>(cin), n, y.begin());
    map<int, pair<int, int>> xy;
    xy[ax] = {ay, ay};
    xy[bx] = {by, by};
    for (auto [x, y] : views::zip(x, y))
        if (xy.count(x))
        {
            auto &[mn, mx] = xy[x];
            mn = min(mn, y);
            mx = max(mx, y);
        }
        else
            xy[x] = {y, y};
    pair<int64_t, int64_t> d{0, 0};
    pair<int, int> p{ax, ay};
    for (const auto &[_, mnx] : xy)
    {
        const auto &[mn, mx] = mnx;
        const int l = mx - mn;
        pair<int64_t, int64_t> dp;
        dp.ST = min(d.ST + min(1LL * abs(p.ST - mx) + l, 1LL * abs(p.ST - mn) + (l << 1)), d.ND + min(1LL * abs(p.ND - mx) + l, 1LL * abs(p.ND - mn) + (l << 1)));
        dp.ND = min(d.ST + min(1LL * abs(p.ST - mn) + l, 1LL * abs(p.ST - mx) + (l << 1)), d.ND + min(1LL * abs(p.ND - mn) + l, 1LL * abs(p.ND - mx) + (l << 1)));
        d = dp;
        p = mnx;
    }
    println("{}", min(d.ST, d.ND) + bx - ax);
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
