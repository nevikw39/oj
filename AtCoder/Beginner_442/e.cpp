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

struct point
{
    const int x, y, quad;
    static int q(int x, int y)
    {
        if (x >= 0 && y > 0)
            return 1;
        if (x > 0 && y <= 0)
            return 2;
        if (x <= 0 && y < 0)
            return 3;
        return 4;
    }
    point(int _x, int _y) : x(_x), y(_y), quad(q(x, y)) {}
    bool operator<(const point &p) const { return quad != p.quad ? quad < p.quad : 1LL * x * p.y < 1LL * y * p.x ; }
};

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    vector<point> xy;
    xy.reserve(n);
    map<point, int> cnt, mp;
    for (int i : views::iota(0, n))
    {
        int x, y;
        cin >> x >> y;
        const int g = gcd(abs(x), abs(y)); 
        xy.emplace_back(x /= g, y /= g);
        ++cnt[{x, y}];
    }
    vector<int> ps(cnt.size());
    for (auto [i, pp] : cnt | views::enumerate)
    {
        auto [p, c] = pp;
        ps[i] = c + (i ? ps[i - 1] : 0);
        mp[p] = i;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a = mp[xy[a - 1]];
        b = mp[xy[b - 1]];
        if (a <= b)
            println("{}", ps[b] - (a ? ps[a - 1] : 0));
        else
            println("{}", ps.back() - ps[a - 1] + ps[b]);
    }
    return 0;
}
