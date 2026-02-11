/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#define __builtin_sprintf sprintf
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

struct seg_tree
{
    const int n;
    struct node
    {
        static constexpr int NEG_INF = numeric_limits<int>::min() >> 1, INF = numeric_limits<int>::max() >> 1;
        int mn = 0, mx = 0, upd = 0;
        node *nl = nullptr, *nr = nullptr;

        void pull()
        {
            mn = min(nl ? nl->mn : INF, nr ? nr->mn : INF);
            mx = max(nl ? nl->mx : NEG_INF, nr ? nr->mx : NEG_INF);
        }

        void apply(int k)
        {
            mn += k;
            mx += k;
            upd += k;
        }

        void push(int l, int r)
        {
            if (!upd || l == r)
                return;
            nl->apply(upd);
            nr->apply(upd);
            upd = 0;
        }

        void update(int ql, int qr, int k, int l, int r)
        {
            if (ql > r || qr < l)
                return;
            if (ql <= l && r <= qr)
            {
                apply(k);
                return;
            }
            push(l, r);
            const int m = (l & r) + ((l ^ r) >> 1);
            nl->update(ql, qr, k, l, m);
            nr->update(ql, qr, k, m + 1, r);
            pull();
        }

        int query(int k, int l, int r)
        {
            if (mn > k || mx < k)
                return INF;
            if (l == r)
                return l;
            push(l, r);
            const int m = (l & r) + ((l ^ r) >> 1);
            // return min(nl->query(k, l, m), nr->query(k, m + 1, r));
            if (const int x = nl->query(k, l, m); x != INF)
                return x;
            return nr->query(k, m + 1, r);
        }
    } *const root;

    node *build(int l, int r)
    {
        node *n = new node();
        if (l == r)
            return n;
        const int m = (l & r) + ((l ^ r) >> 1);
        n->nl = build(l, m);
        n->nr = build(m + 1, r);
        n->pull();
        return n;
    }

    seg_tree(int _n) : n(_n), root(build(0, n - 1)) {}
    void update(int ql, int qr, int k) { root->update(ql, qr, k, 0, n - 1); }
    int query(int k) { return root->query(k, 0, n - 1); }
};

class Solution
{
public:
    int longestBalanced(const vector<int> &nums)
    {
        const int n = nums.size();
        seg_tree st(n);
        _hash<int, int> hm;
        int mx = 0;
        for (int i : views::iota(0, n))
        {
            if (hm.find(nums[i]) != hm.end())
                st.update(0, hm[nums[i]], (~nums[i]) & 1 ?: -1);
            st.update(0, i, nums[i] & 1 ?: -1);
            const int q = st.query(0);
            if (q < n)
                mx = max(mx, i - q + 1);
            hm[nums[i]] = i;
        }
        return mx;
    }
};
