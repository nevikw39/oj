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
        T val, lval, rval, sum;
        node *nl, *nr;
        node()
        {
            val = lval = rval = sum = 0;
            nl = nr = nullptr;
        }
        void inline pull()
        {
            val = max({nl->val, nr->val, nl->rval + nr->lval});
            lval = max(nl->lval, nl->sum + nr->lval);
            rval = max(nl->rval + nr->sum, nr->rval);
            sum = nl->sum + nr->sum;
        }
        void push(int l, int r) {}
        void modify(int q, T k, int l, int r)
        {
            if (l == r)
            {
                sum = k;
                lval = rval = val = max(T(0), k);
                return;
            }
            push(l, r);
            int m = (l & r) + ((l ^ r) >> 1);
            if (q <= m) nl->modify(q, k, l, m);
            else nr->modify(q, k, m + 1, r);
            pull();
        }
    } *root;
    int n;
    node *build(const vector<T> &v, int l, int r)
    {
        node *n = new node();
        if (l == r)
        {
            n->sum = v[l];
            n->lval = n->rval = n->val = max(T(0), T(v[l]));
            return n;
        }
        int m = (l & r) + ((l ^ r) >> 1);
        n->nl = build(v, l, m);
        n->nr = build(v, m + 1, r);
        n->pull();
        return n;
    }
    // assume 1-indexed array!
    segment_tree(const vector<T> &v) : n(v.size() - 1) { root = build(v, 1, n); }
    void inline modify(int q, int k) { root->modify(q, k, 1, n); }
};

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<int64_t> v(n);
    for (auto &i : v)
        cin >> i;
    v.insert(v.begin(), -1);
    segment_tree<int64_t> st(v);
    while (m--)
    {
        int64_t k, x;
        cin >> k >> x;
        st.modify(k, x);
        cout << st.root->val << '\n';
    }
    return 0;
}
