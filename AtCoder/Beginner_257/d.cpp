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

int64_t inline ceil_div(int64_t x, int64_t y) { return (x + y - 1) / y; }

int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<tuple<int, int, int>> xyp(n);
    for (auto &[x, y, p] : xyp)
        cin >> x >> y >> p;
    vector<vector<int64_t>> d(n, vector<int64_t>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            const auto &[xi, yi, pi] = xyp[i];
            const auto &[xj, yj, pj] = xyp[j];
            d[i][j] = ceil_div(1LL * abs(xi - xj) + abs(yi - yj), pi);
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
    int64_t r = INT64_MAX;
    for (const auto &i : d)
        r = min(r, *max_element(ALL(i)));
    cout << r << '\n';
    return 0;
}
