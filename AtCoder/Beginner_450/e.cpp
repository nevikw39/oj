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

int n = 2;
vector<int64_t> len;
vector<array<int64_t, 26>> ps_x, ps_y, ps;

int64_t solve(int64_t x, char c, int k)
{
    if (!x)
        return 0;
    if (k == 0)
        return ps_x[x][c - 'a'];
    if (k == 1)
        return ps_y[x][c - 'a'];
    if (x <= len[k - 1])
        return solve(x, c, k - 1);
    return ps[k - 1][c - 'a'] + solve(x - len[k - 1], c, k - 2);
}

int main()
{
    nevikw39;
    string x, y;
    int q;
    cin >> x >> y >> q;
    len.emplace_back(x.length());
    ps_x.assign(x.length() + 1, array<int64_t, 26>{});
    ps.emplace_back(array<int64_t, 26>{});
    for (auto [i, c] : x | views::enumerate)
    {
        ps_x[i + 1] = ps_x[i];
        ++ps_x[i + 1][c - 'a'];
        ++ps[0][c - 'a'];
    }
    len.emplace_back(y.length());
    ps_y.assign(y.length() + 1, array<int64_t, 26>{});
    ps.emplace_back(array<int64_t, 26>{});
    for (auto [i, c] : y | views::enumerate)
    {
        ps_y[i + 1] = ps_y[i];
        ++ps_y[i + 1][c - 'a'];
        ++ps[1][c - 'a'];
    }
    while (len.back() < 1e18)
    {
        len.emplace_back(len[n - 1] + len[n - 2]);
        ps.emplace_back(array<int64_t, 26>{});
        for (int j : views::iota(0, 26))
            ps[n][j] = ps[n - 1][j] + ps[n - 2][j];
        ++n;
    }
    while (q--)
    {
        int64_t l, r;
        char c;
        cin >> l >> r >> c;
        println("{}", solve(r, c, n) - solve(l - 1, c, n));
    }
    return 0;
}
