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

random_device rd;
mt19937 mt(rd());

struct treap
{
    int key, pri, size = 1;
    bool tag = false;
    int64_t sum;
    treap *tl, *tr;
    treap() = default;
    treap(int k) : key(k), pri(mt()), sum(k) { tl = tr = nullptr; }
    ~treap()
    {
        if (tl)
            delete tl;
        if (tr)
            delete tr;
    }
};

inline void reverse(treap *t)
{
    if (t)
        t->tag ^= 1;
}
void push(treap *t)
{
    if (!t || !t->tag)
        return;
    swap(t->tl, t->tr);
    reverse(t->tl);
    reverse(t->tr);
    t->tag = false;
}
inline int size(treap *t) { return t ? t->size : 0; }
inline int64_t query(treap *t) { return t ? t->sum : 0; }
inline void pull(treap *t)
{
    if (!t)
        return;
    t->size = size(t->tl) + 1 + size(t->tr);
    t->sum = query(t->tl) + t->key + query(t->tr);
}

treap *merge(treap *a, treap *b)
{
    if (!a || !b)
        return a ?: b;
    if (a->pri > b->pri)
    {
        push(a);
        a->tr = merge(a->tr, b);
        pull(a);
        return a;
    }
    else
    {
        push(b);
        b->tl = merge(a, b->tl);
        pull(b);
        return b;
    }
}

void split(treap *t, int k, treap *&a, treap *&b)
{
    if (!t)
    {
        a = b = nullptr;
        return;
    }
    push(t);
    if (size(t->tl) < k)
    {
        a = t;
        split(a->tr, k - size(t->tl) - 1, a->tr, b);
        pull(a);
    }
    else
    {
        b = t;
        split(b->tl, k, a, b->tl);
        pull(b);
    }
}

treap *reverse(treap *t, int l, int r)
{
    treap *t1, *t2;
    split(t, l - 1, t1, t);
    split(t, r - l + 1, t, t2);
    reverse(t);
    return merge(merge(t1, t), t2);
}

int64_t query(treap *t, int l, int r)
{
    treap *t1, *t2;
    split(t, l - 1, t1, t);
    split(t, r - l + 1, t, t2);
    auto y = query(t);
    merge(merge(t1, t), t2);
    return y;
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    treap *root = nullptr;
    while (n--)
    {
        int x;
        cin >> x;
        root = merge(root, new treap(x));
    }
    while (m--)
    {
        char t;
        int a, b;
        cin >> t >> a >> b;
        if (t == '1')
            reverse(root, a, b);
        else
            cout << query(root, a, b) << '\n';
    }
    return 0;
}
