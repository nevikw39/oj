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

template <typename T>
generator<T> scan_n(istream &in, size_t n)
{
    for (T t; n-- && in >> t;)
        co_yield t;
}

struct node
{
    int len = 0, l, r, pre = 0, suf = 0, best = 0;

    static node make(int x) { return {1, x, x, 1, 1, 1}; }

    static node op(node l, node r)
    {
        node y{l.len + r.len, l.l, r.r, l.pre, r.suf, max(l.best, r.best)};
        if (l.r == r.l)
        {
            y.best = max(y.best, l.suf + r.pre);
            if (l.pre == l.len)
                y.pre += r.pre;
            if (r.suf == r.len)
                y.suf += l.suf;
        }
        return y;
    }
};

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    segtree<node, node::op, []() { return node{}; }> st(scan_n<int>(cin, n) | views::transform(node::make) | ranges::to<vector<node>>());
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            int i, x;
            cin >> i >> x;
            st.set(i - 1, node::make(x));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            println("{}", st.prod(l - 1, r).best);
        }
    }
    return 0;
}
