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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct seg_tree_node
{
    int64_t val = 0;
    seg_tree_node *nl = nullptr, *nr = nullptr;

    inline void pull() { val = (nl ? nl->val : 0) + (nr ? nr->val : 0); }

    void push(int l, int r) {}

    int64_t query(int ql, int qr, int l, int r)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return val;
        push(l, r);
        int m = (l & r) + ((l ^ r) >> 1);
        return nl->query(ql, qr, l, m) + nr->query(ql, qr, m + 1, r);
    }

    void modify(int ql, int qr, int k, int l, int r)
    {
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr)
        {
            val = k * (r - l + 1);
            return;
        }
        push(l, r);
        int m = (l & r) + ((l ^ r) >> 1);
        nl->modify(ql, qr, k, l, m);
        nr->modify(ql, qr, k, m + 1, r);
        pull();
    }
};

seg_tree_node *build(int l, int r, const vector<int> &v)
{
    auto *n = new seg_tree_node();
    if (l == r)
    {
        n->val = v[l];
        return n;
    }
    int m = (l & r) + ((l ^ r) >> 1);
    n->nl = build(l, m, v);
    n->nr = build(m + 1, r, v);
    n->pull();
    return n;
}

int main()
{
    nevikw39;
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    auto *root = build(1, n, x);
    while (q--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '1')
            root->modify(a, a, b, 1, n);
        else
            cout << root->query(a, b, 1, n) << '\n';
    }
    return 0;
}