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

static random_device rd;
static mt19937 mt(rd());

struct treap
{
    int key, pri, size;
    treap *tl, *tr;
    treap() = default;
    treap(int k) : key(k), pri(mt()), size(1) { tl = tr = nullptr; }
    ~treap()
    {
        if (tl)
            delete tl;
        if (tr)
            delete tr;
    }
    static int sz(treap *t) { return t ? t->size : 0; }
    void pull() { size = sz(tl) + 1 + sz(tr); }
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

void split(treap *t, int k, treap *&a, treap *&b)
{
    if (!t)
        a = b = nullptr;
    else if (t->sz(t->tl) < k)
    {
        a = t;
        split(t->tr, k - t->sz(t->tl) - 1, a->tr, b);
        a->pull();
    }
    else
    {
        b = t;
        split(t->tl, k, a, b->tl);
        b->pull();
    }
}

void dfs(treap *root)
{
    if (!root)
        return;
    dfs(root->tl);
    cout.put(root->key);
    dfs(root->tr);
}

int main()
{
    nevikw39;
    int n, m;
    string s;
    cin >> n >> m >> s;
    treap *root = nullptr;
    for (char c : s)
        root = merge(root, new treap(c));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        treap *l, *e, *g;
        split(root, a, l, g);
        split(g, b - a + 1, e, g);
        root = merge(merge(l, g), e);
    }
    dfs(root);
    cout.put('\n');
    return 0;
}
