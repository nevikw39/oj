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
    int largest, largest_2nd, cnt_largest, cnt_largest_2nd;
};

node op(node a, node b)
{
    node y;
    set<int> s{a.largest, a.largest_2nd, b.largest, b.largest_2nd};
    y.largest = *s.rbegin();
    if (s.size() > 1)
        y.largest_2nd = *++s.rbegin();
    else
        y.largest_2nd = 0;
    y.cnt_largest = y.cnt_largest_2nd = 0;
    if (y.largest == a.largest)
        y.cnt_largest += a.cnt_largest;
    if (y.largest == b.largest)
        y.cnt_largest += b.cnt_largest;
    if (y.largest_2nd)
    {
        if (y.largest_2nd == a.largest)
            y.cnt_largest_2nd += a.cnt_largest;
        if (y.largest_2nd == b.largest)
            y.cnt_largest_2nd += b.cnt_largest;
        if (y.largest_2nd == a.largest_2nd)
            y.cnt_largest_2nd += a.cnt_largest_2nd;
        if (y.largest_2nd == b.largest_2nd)
            y.cnt_largest_2nd += b.cnt_largest_2nd;
    }
    return y;
}
node e() { return node{0, 0, 0, 0}; }

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    vector<node> v(n);
    for (node &i : v)
    {
        cin >> i.largest;
        i.largest_2nd = 0;
        i.cnt_largest = 1;
        i.cnt_largest_2nd = 0;
    }
    segtree<node, op, e> seg(v);
    while (q--)
    {
        char c;
        int pl, xr;
        cin >> c >> pl >> xr;
        if (c == '1')
            seg.set(pl - 1, node{xr, 0, 1, 0});
        else
            cout << seg.prod(pl - 1, xr).cnt_largest_2nd << '\n';
    }
    return 0;
}
