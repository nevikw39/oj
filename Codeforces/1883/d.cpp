/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

template<typename T>
struct st_max
{
    constexpr static T e = numeric_limits<int>::min();
    inline static T foo(T x, T y) { return max(x, y); }
    inline static T bar(T x) { return 1; }
};
 
template<typename T, typename t=st_max<T>>
struct segment_tree
{
    struct node
    {
        T val, upd, mdf;
        bool modified;
        node *nl, *nr;
        node()
        {
            val = upd = modified = 0;
            nl = nr = nullptr;
        }
        void inline pull() { val = t::foo(nl->val, nr->val); }
        void push(int l, int r)
        {
            int m = (l & r) + ((l ^ r) >> 1);
            if (modified)
            {
                if (l != r)
                {
                    nl->mdf = nr->mdf = mdf;
                    nl->modified = nr->modified = true;
                    nl->val = mdf * t::bar(m - l + 1);
                    nr->val = mdf * t::bar(r - m);
                    nl->upd = nr->upd = 0;
                }
                modified = mdf = 0;
            }
            if (upd)
            {
                if (l != r)
                {
                    nl->upd += upd;
                    nr->upd += upd;
                    nl->val += upd * t::bar(m - l + 1);
                    nr->val += upd * t::bar(r - m);
                }
                upd = 0;
            }
        }
        T query(int ql, int qr, int l, int r)
        {
            if (ql > r || qr < l) return t::e;
            if (ql <= l && r <= qr) return val;
            push(l, r);
            int m = (l & r) + ((l ^ r) >> 1);
            return t::foo(nl->query(ql, qr, l, m), nr->query(ql, qr, m + 1, r));
        }
        void update(int ql, int qr, int d, int l, int r)
        {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr)
            {
                upd += d;
                val += d * t::bar(r - l + 1);
                return;
            }
            push(l, r);
            int m = (l & r) + ((l ^ r) >> 1);
            nl->update(ql, qr, d, l, m);
            nr->update(ql, qr, d, m + 1, r);
            pull();
        }
        void modify(int ql, int qr, int k, int l, int r)
        {
            if (ql > r || qr < l) return;
            if (ql <= l && r <= qr)
            {
                if (upd) upd = 0;
                mdf = k;
                modified = true;
                val = k * t::bar(r - l + 1);
                return;
            }
            push(l, r);
            int m = (l & r) + ((l ^ r) >> 1);
            nl->modify(ql, qr, k, l, m);
            nr->modify(ql, qr, k, m + 1, r);
            pull();
        }
    } *root;
    int n;
    node *build(const vector<T> &v, int l, int r)
    {
        node *n = new node();
        if (l == r)
        {
            n->val = v[l];
            return n;
        }
        int m = (l & r) + ((l ^ r) >> 1);
        n->nl = build(v, l, m);
        n->nr = build(v, m + 1, r);
        n->pull();
        return n;
    }
    // assume 1-indexed array!
    segment_tree(vector<T> v) : n(v.size() - 1) { root = build(v, 1, n); }
    T inline query(int ql, int qr) { return root->query(ql, qr, 1, n); }
    void inline update(int ql, int qr, int d) { root->update(ql, qr, d, 1, n); }
    void inline modify(int ql, int qr, int k) { root->modify(ql, qr, k, 1, n); }
};

int main()
{
    nevikw39;
    int q, sz = 0;
    cin >> q;
    vector<tuple<bool, int, int>> oplr(q);
    set<int> s;
    for (auto &[op, l, r] : oplr)
    {
        char c;
        cin >> c >> l >> r;
        op = c == '+';
        s.insert(l);
        s.insert(r);
    }
    vector<int> v(ALL(s));
    int n = v.size();
    segment_tree<int> st(vector<int>(n + 1));
    for (auto [op, l, r] : oplr)
    {
        l = lower_bound(ALL(v), l) - v.begin() + 1;
        r = lower_bound(ALL(v), r) - v.begin() + 1;
        if (op)
        {
            st.update(l, r, 1);
            ++sz;
        }
        else
        {
            st.update(l, r, -1);
            --sz;
        }
        if (st.query(1, n) <= sz - 1)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
