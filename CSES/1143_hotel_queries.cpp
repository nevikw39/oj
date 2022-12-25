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
struct segment_tree
{
    struct node
    {
        T val;
        node *nl, *nr;
        node() : val(0) { nl = nr = nullptr; }
        void inline pull() { val = max(nl->val, nr->val); }
        void push(int l, int r) {}
        T query(int q, int l, int r)
        {
            if (q > val) return 0;
            if (l == r) return l;
            push(l, r);
            int m = (l & r) + ((l ^ r) >> 1);
            return nl->val >= q ? nl->query(q, l, m) : nr->query(q, m + 1, r);
        }
        void update(int q, int d, int l, int r)
        {
            if (q > r || q < l) return;
            if (q <= l && r <= q)
            {
                val += d;
                return;
            }
            push(l, r);
            int m = (l & r) + ((l ^ r) >> 1);
            if (q <= m) nl->update(q, d, l, m);
            else  nr->update(q, d, m + 1, r);
            pull();
        }
    } *root;
    int n;
    vector<T> v;
    node *build(int l, int r)
    {
        node *n = new node();
        if (l == r)
        {
            n->val = v[l];
            return n;
        }
        int m = (l & r) + ((l ^ r) >> 1);
        n->nl = build(l, m);
        n->nr = build(m + 1, r);
        n->pull();
        return n;
    }
    // assume 1-indexed array!
    segment_tree(const vector<int> &_v) : v(move(_v)), n(_v.size() - 1) { root = build(1, n); }
    T inline query(int q) { return root->query(q, 1, n); }
    void inline update(int q, int d) { root->update(q, d, 1, n); }
};

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int &i : h)
        cin >> i;
    h.insert(h.begin(), -1);
    segment_tree<int> st(h);
    while (m--)
    {
        int r;
        cin >> r;
        int q = st.query(r);
        cout << q << ' ';
        st.update(q, -r);
    }
    cout << '\n';
    return 0;
}
