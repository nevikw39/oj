/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int main()
{
    nevikw39;
    int64_t n, x, a, b, m, r;
    cin >> n >> x >> a >> b >> m;
    vector<int64_t> v(n), id(n), ps(n);
    for (auto &i : v)
        cin >> i;
    iota(ALL(id), 0);
    sort(ALL(id), [&](const auto &l, const auto &r)
         { return v[l] < v[r]; });
    for (int i = 1; i < n; i++)
        ps[i] = ps[i - 1] + (v[id[i]] - v[id[i - 1]]) * i;
    ps.push_back(ps.back() + (x - v[id[n - 1]]) * n);
    auto f = [&]()
    {
        int idx = upper_bound(ALL(ps), m) - ps.begin() - 1;
        return min(v[id[idx]] + int64_t(floor((m - ps[idx]) / (idx + 1.0))), x);
    };
    r = b * f();
    auto s = make_pair(n, m);
    for (int i = n - 1; i >= 0; i--)
    {
        if ((m -= x - v[id[i]]) < 0)
            break;
        auto t = a * (n - i) + b * f();
        cerr << n - i << ' ' << f() << '\n';
        if (r < t)
        {
            r = t;
            s = {i, m};
        }
    }
    for (int i = 0, idx = upper_bound(ALL(ps), s.ND) - ps.begin() - 1, mn = min(v[id[idx]] + int64_t(floor((s.ND - ps[idx]) / (idx + 1.0))), x); i <= idx; i++)
        v[id[i]] = mn;
    for (int i = n - 1; i >= s.ST; i--)
        v[id[i]] = x;
    cout << r << '\n'
         << v[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << v[i];
    cout << '\n';
    return 0;
}