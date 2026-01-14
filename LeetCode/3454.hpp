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

struct seg_tree_interval_union
{
    struct node
    {
        int cnt, len;
        node *nl, *nr;
        node() : cnt(0), len(0), nl(nullptr), nr(nullptr) {}
        inline void pull(int l, int r, const vector<int> &x)
        {
            if (cnt > 0)
                len = x[r + 1] - x[l];
            else
            {
                if (l != r)
                    len = (nl ? nl->len : 0) + (nr ? nr->len : 0);
                else
                    len = 0;
            }
        }
        void update(int ql, int qr, int d, int l, int r, const vector<int> &xs)
        {
            if (ql > r || qr < l)
                return;
            if (ql <= l && r <= qr)
            {
                cnt += d;
                pull(l, r, xs);
                return;
            }
            const int m = (l & r) + ((l ^ r) >> 1);
            if (ql <= m)
            {
                if (!nl)
                    nl = new node();
                nl->update(ql, qr, d, l, m, xs);
            }
            if (qr > m)
            {
                if (!nr)
                    nr = new node();
                nr->update(ql, qr, d, m + 1, r, xs);
            }
            pull(l, r, xs);
        }
    } *root;
    const vector<int> &xs;
    int n;
    seg_tree_interval_union(const vector<int> &_xs) : xs(_xs), n(_xs.size() - 1), root(new node) {}
    inline int query() { return root->len; }
    inline void update(int ql, int qr, int d) { root->update(ql, qr, d, 0, n - 1, xs); }
};

class Solution
{
public:
    double separateSquares(const vector<vector<int>> &squares)
    {
        vector<tuple<int, int, int, bool>> sqs;
        vector<int> xs, ws;
        for (auto &sq : squares)
        {
            const int x = sq[0], y = sq[1], l = sq[2];
            sqs.emplace_back(y, x, l, true);
            sqs.emplace_back(y + l, x, l, false);
            xs.push_back(x);
            xs.push_back(x + l);
        }
        ranges::sort(sqs);
        ranges::sort(xs);
        xs.erase(ranges::unique(xs).begin(), xs.end());
        seg_tree_interval_union st(xs);
        int64_t sum = 0;
        int h = 0;
        vector<int64_t> ps;
        for (const auto &[y, x, l, type] : sqs)
        {
            const int d = y - h, w = st.query();
            ws.push_back(w);
            ps.push_back(sum += INT64_C(1) * w * d);
            const int xl = ranges::lower_bound(xs, x) - xs.begin(), xr = ranges::lower_bound(xs, x + l) - xs.begin();
            st.update(xl, xr - 1, type - !type);
            h = y;
        }
        const auto itr = ranges::lower_bound(ps, sum + 1 >> 1);
        const int i = itr - ps.begin();
        return get<0>(sqs[i]) + (sum - (*itr << 1)) / (ws[i] * 2.);
    }
};
