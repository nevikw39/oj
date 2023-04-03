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

constexpr int P = 29, M = 1e9 + 7;

struct seg_tree_node
{
    int val = 0;
    seg_tree_node *nl = nullptr, *nr = nullptr;

    inline void pull() { val = ((nl ? nl->val : 0) + (nr ? nr->val : 0)) % M; }

    void push(int l, int r) {}

    int query(int ql, int qr, int l, int r)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return val;
        push(l, r);
        int m = (l & r) + ((l ^ r) >> 1);
        return (nl->query(ql, qr, l, m) + nr->query(ql, qr, m + 1, r)) % M;
    }

    void modify(int q, int k, int l, int r)
    {
        if (l == r)
        {
            val = k;
            return;
        }
        push(l, r);
        int m = (l & r) + ((l ^ r) >> 1);
        if (q <= m)
            nl->modify(q, k, l, m);
        else
            nr->modify(q, k, m + 1, r);
        pull();
    }
};

seg_tree_node *build(int l, int r, const vector<int> &v)
{
    auto *n = new seg_tree_node;
    if (l == r)
    {
        n->val = v[l - 1];
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
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> pow_p(n, 1), v1(n), v2(n);
    for (int i = 1; i < n; i++) pow_p[i] = 1LL * pow_p[i - 1] * P % M;
    for (int i = 0 ; i < n; i++)
    {
        v1[i] = 1LL * (s[i] - 'a') * pow_p[i] % M;
        v2[i] = 1LL * (s[i] - 'a') * pow_p[n - i - 1] % M;
    }
    seg_tree_node *st1 = build(1, n, v1), *st2 = build(1, n, v2);
    while (m--)
    {
        char c;
        cin >> c;
        if (c == '1')
        {
            int k;
            char x;
            cin >> k >> x;
            st1->modify(k, 1LL * (x - 'a') * pow_p[k - 1] % M, 1, n);
            st2->modify(k, 1LL * (x - 'a') * pow_p[n - k] % M, 1, n);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << (1LL * st1->query(l, r, 1, n) * pow_p[n - r] % M == 1LL * st2->query(l, r, 1, n) * pow_p[l - 1] % M ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
