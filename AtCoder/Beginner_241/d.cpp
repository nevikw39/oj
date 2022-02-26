/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
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
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

random_device rd;
mt19937 mt(rd());
struct treap
{
    int64_t key, pri, size;
    treap *tl, *tr;
    treap() = default;
    treap(int64_t k) : key(k), pri(mt()), size(1) { tl = tr = nullptr; }
    ~treap()
    {
        if (tl)
            delete tl;
        if (tr)
            delete tr;
    }
    inline static int sz(treap *t) { return t ? t->size : 0; }
    void pull() { size = sz(tl) + 1 + sz(tr); }
    int64_t large(int64_t k)
    {
        if (k <= sz(tr))
            return tr->large(k);
        if (k == sz(tr) + 1)
            return key;
        return tl->large(k - 1 - sz(tr));
    }
    int64_t small(int64_t k)
    {
        if (k <= sz(tl))
            return tl->small(k);
        if (k == sz(tl) + 1)
            return key;
        return tr->small(k - 1 - sz(tl));
    }
};

treap *merge(treap *a, treap *b)
{
    if (!a || !b)
        return a ?: b;
    if (a->pri < b->pri)
    {
        a->tr = merge(a->tr, b);
        a->pull();
        return a;
    }
    else
    {
        b->tl = merge(a, b->tl);
        b->pull();
        return b;
    }
}

void split(treap *t, int64_t k, treap *&a, treap *&b)
{
    if (!t)
        a = b = nullptr;
    else if (t->key <= k)
    {
        a = t;
        split(t->tr, k, a->tr, b);
        a->pull();
    }
    else
    {
        b = t;
        split(t->tl, k, a, b->tl);
        b->pull();
    }
}

int main()
{
    nevikw39;
    treap *t = nullptr;
    int64_t q;
    cin >> q;
    while (q--)
    {
        int64_t c, x, k;
        cin >> c >> x;
        treap *a, *b;
        if (c == 1)
        {
            split(t, x, a, b);
            t = merge(merge(a, new treap(x)), b);
            continue;
        }
        cin >> k;
        if (c == 2)
        {
            split(t, x, a, b);
            cout << (a && a->size >= k ? a->large(k) : -1) << '\n';
            t = merge(a, b);
        }
        else
        {
            split(t, x - 1, a, b);
            cout << (b && b->size >= k ? b->small(k) : -1) << '\n';
            t = merge(a, b);
        }
    }
    return 0;
}