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

using mint = atcoder::modint998244353;

template <typename T>
generator<T> scan_n(istream &in, size_t n)
{
    for (T t; n-- && in >> t;)
        co_yield t;
}

struct node
{
    array<mint, 5> a{};

    static node make(int x)
    {
        node n{1};
        for (auto [prv, nxt] : n.a | views::pairwise)
            nxt = prv * x;
        return n;
    }

    static node op(node l, node r) { return {l.a[0] + r.a[0], l.a[1] + r.a[1], l.a[2] + r.a[2], l.a[3] + r.a[3], l.a[4] + r.a[4]}; }
    static node e() { return {}; }

    static node maapping(mint tag, node n)
    {
        array<mint, 5> a{1};
        for (auto [prv, nxt] : a | views::pairwise)
            nxt = prv * tag;
        n.a[4] += n.a[3] * a[1] * 4 + n.a[2] * a[2] * 6 + n.a[1] * a[3] * 4 + n.a[0] * a[4];
        n.a[3] += n.a[2] * a[1] * 3 + n.a[1] * a[2] * 3 + n.a[0] * a[3];
        n.a[2] += n.a[1] * a[1] * 2 + n.a[0] * a[2];
        n.a[1] += n.a[0] * a[1];
        return n;
    }
    static mint composition(mint x, mint y) { return x + y; }
    static mint id() { return 0; }
};

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    lazy_segtree<node, node::op, node::e, mint, node::maapping, node::composition, node::id> st(scan_n<int>(cin, n) | views::transform(node::make) | ranges::to<vector<node>>());
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        --l;
        if (c == '1')
        {
            int x;
            cin >> x;
            st.apply(l, r, x);
        }
        else
        {
            int k;
            cin >> k;
            println("{}", st.prod(l, r).a[k].val());
        }
    }
    return 0;
}
