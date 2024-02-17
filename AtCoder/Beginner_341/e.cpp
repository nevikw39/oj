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

using lazy_segtree_t = tuple<int, int, bool>;
using lazy_segtree_tag_t = bool;

lazy_segtree_t op(lazy_segtree_t l, lazy_segtree_t r)
{
    auto [lf, lb, lx] = l;
    auto [rf, rb, rx] = r;
    if (!~lf)
        return r;
    if (!~rb)
        return l;
    return {lf, rb, lx && rx && lb != rf};
}

lazy_segtree_t e() { return {-1, -1, true}; }

lazy_segtree_t mapping(lazy_segtree_tag_t l, lazy_segtree_t r)
{
    auto [f, b, x] = r;
    return {f ^ l, b ^ l, x};
}

lazy_segtree_tag_t composition(lazy_segtree_tag_t l, lazy_segtree_tag_t r) { return l ^ r; }

lazy_segtree_tag_t id() { return false; }

int main()
{
    nevikw39;
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<lazy_segtree_t> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {s[i] - '0', s[i] - '0', true};
    lazy_segtree<lazy_segtree_t, op, e, lazy_segtree_tag_t, mapping, composition, id> seg(v);
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        --l;
        if (c == '1')
            seg.apply(l, r, true);
        else
            cout << (get<2>(seg.prod(l, r)) ? "Yes\n" : "No\n");
    }
    return 0;
}
