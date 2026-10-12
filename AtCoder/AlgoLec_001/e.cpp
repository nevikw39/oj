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

struct node
{
    inline static string s;

    modint998244353 r, g, b, rg, gb, rgb;

    node() = default;
    node(int i, int x)
    {
        switch (s[i])
        {
        case 'R':
            r = x;
            break;
        case 'G':
            g = x;
            break;
        default:
            b = x;
        }
    }

    static node op(node l, node r)
    {
        node y;

        y.r = l.r + r.r;
        y.g = l.g + r.g;
        y.b = l.b + r.b;

        y.rg = l.rg + r.rg + l.r * r.g;
        y.gb = l.gb + r.gb + l.g * r.b;

        y.rgb = l.rgb + r.rgb + l.rg * r.b + l.r * r.gb;

        return y;
    }
};

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    std::copy_n(istream_iterator<int>(cin), n, a.begin());
    cin >> node::s;
    segtree<node, node::op, [](){ return node{}; }> st(a | views::enumerate | views::transform([](auto t) { return std::make_from_tuple<node>(t); }) | ranges::to<vector<node>>());
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            int i, x;
            cin >> i >> x;
            st.set(i - 1, node(i - 1, x));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            println("{}", st.prod(l - 1, r).rgb.val());
        }
    }
    return 0;
}
