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

int64_t inline sq(int x) { return 1LL * x * x; }

int main()
{
    nevikw39;
    int n, sx, sy, tx, ty, s = -1, t = -1;
    cin >> n >> sx >> sy >> tx >> ty;
    dsu disjoint_set(n);
    vector<tuple<int, int, int>> xyr(n);
    for (int i = 0; i < n; i++)
    {
        auto &[x, y, r] = xyr[i];
        cin >> x >> y >> r;
        if (sq(sx - x) + sq(sy - y) == sq(r))
            s = i;
        if (sq(tx - x) + sq(ty - y) == sq(r))
            t = i;
        for (int j = 0; j < i; j++)
        {
            auto &[xp, yp, rp] = xyr[j];
            auto d2 = sq(xp - x) + sq(yp - y);
            if (sq(r - rp) <= d2 && d2 <= sq(r + rp))
                disjoint_set.merge(i, j);
        }
    }
    cout << (disjoint_set.same(s, t) ? "Yes\n" : "No\n") << '\n';
    return 0;
}