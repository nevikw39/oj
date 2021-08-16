/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
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
struct segment_tree
{
    struct node
    {
        long long val, tag;
        node *nl, *nr;
        node()
        {
            val = tag = 0;
            nl = nr = nullptr;
        }
        void pull()
        {
            val = nl->val + nr->val;
        }
        void push(int l, int r)
        {
            if (!tag)
                return;
            if (l != r)
            {
                int m = (l + r) >> 1;
                nl->tag += tag;
                nr->tag += tag;
                nl->val += tag * (m - l + 1);
                nr->val += tag * (r - m);
            }
            tag = 0;
        }
        long long query(int ql, int qr, int l, int r)
        {
            if (ql > r || qr < l)
                return 0;
            if (ql <= l && r <= qr)
                return val;
            push(l, r);
            int m = (l + r) >> 1;
            return nl->query(ql, qr, l, m) + nr->query(ql, qr, m + 1, r);
        }
        void modify(int ql, int qr, int d, int l, int r)
        {
            if (ql > r || qr < l)
                return;
            if (ql <= l && r <= qr)
            {
                tag += d;
                val += d * (r - l + 1);
                return;
            }
            push(l, r);
            int m = (l + r) >> 1;
            nl->modify(ql, qr, d, l, m);
            nr->modify(ql, qr, d, m + 1, r);
            pull();
        }
    } * root;
    int n;
    vector<int> v;
    node *build(int l, int r)
    {
        node *n = new node();
        if (l == r)
        {
            n->val = v[l];
            return n;
        }
        int m = (l + r) >> 1;
        n->nl = build(l, m);
        n->nr = build(m + 1, r);
        n->pull();
        return n;
    }
    segment_tree(const vector<int> &_v)
    {
        v = move(_v);
        n = v.size() - 1;
        root = build(1, n);
    }
    long long inline query(int ql, int qr)
    {
        return root->query(ql, qr, 1, n);
    }
    void inline modify(int ql, int qr, int d)
    {
        root->modify(ql, qr, d, 1, n);
    }
};
int main()
{
    nevikw39;
    int n, q;
    cin >> n;
    vector<int> v;
    v.push_back(0);
    while (n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    segment_tree st(move(v));
    cin >> q;
    while (q--)
    {
        int v, x, y, k;
        cin >> v >> x >> y;
        if (v == 1)
        {
            cin >> k;
            st.modify(x, y, k);
        }
        else
            cout << st.query(x, y) << '\n';
    }
    return 0;
}