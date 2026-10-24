/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

inline bool up(const pair<int, int> &p) { return p.ND > 0 || !p.ND && p.ST > 0; }
inline bool cross(const pair<int, int> &l, const pair<int, int> &r) { return 1LL * l.ST * r.ND > 1LL * l.ND * r.ST; }

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    for (auto &[x, y] : xy)
        cin >> x >> y;
    ranges::sort(xy, [](const auto &l, const auto &r) { const bool ul = up(l), ur = up(r); return ul != ur ? ul < ur : cross(l, r); });
    xy.reserve(n << 1);
    xy.append_range(xy);
    int sliding_window = 0;
    for (int j = 0; int i : views::iota(0, n))
    {
        if (j < i + 1)
            j = i + 1;
        while (j < i + n && cross(xy[i], xy[j]))
            ++j;
        sliding_window = max(sliding_window, j - i);
    }
    println("{}", sliding_window);
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
