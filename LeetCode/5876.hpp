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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

template <typename T>
struct st_min
{
    constexpr static T e = numeric_limits<T>::max();
    inline static T foo(T x, T y)
    {
        return min(x, y);
    }
    constexpr static T bar()
    {
        return numeric_limits<T>::max();
    }
};
template <typename T>
struct st_max
{
    constexpr static T e = numeric_limits<T>::min();
    inline static T foo(T x, T y)
    {
        return max(x, y);
    }
    constexpr static T bar()
    {
        return numeric_limits<T>::min();
    }
};
template <typename T, typename t>
struct segment_tree
{
    struct node
    {
        T val;
        node *nl, *nr;
        node()
        {
            val = 0;
            nl = nr = nullptr;
        }
        void inline pull()
        {
            val = t::foo(nl->val, nr->val);
        }
        void push(int l, int r)
        {
            int m = (l + r) >> 1;
        }
        T query(int ql, int qr, int l, int r)
        {
            if (ql > r || qr < l)
                return t::bar();
            if (ql <= l && r <= qr)
                return val;
            push(l, r);
            int m = (l + r) >> 1;
            return t::foo(nl->query(ql, qr, l, m), nr->query(ql, qr, m + 1, r));
        }
    } * root;
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
        int m = (l + r) >> 1;
        n->nl = build(l, m);
        n->nr = build(m + 1, r);
        n->pull();
        return n;
    }
    segment_tree(const vector<int> &_v)
    {
        v = _v;
        n = v.size() - 1;
        root = build(1, n);
    }
    T inline query(int ql, int qr)
    {
        return root->query(ql, qr, 1, n);
    }
};

class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        vector<int> v = {-1};
        v.insert(v.end(), make_move_iterator(nums.begin()), make_move_iterator(nums.end()));
        int y = 0;
        segment_tree<int, st_min<int>> mn(v);
        segment_tree<int, st_max<int>> mx(v);
        for (int i = 2, n = v.size() - 1; i < n; i++)
            if (mx.query(1, i - 1) < v[i] && v[i] < mn.query(i + 1, n))
                y += 2;
            else if (v[i - 1] < v[i] && v[i] < v[i + 1])
                y += 1;
        return y;
    }
};
