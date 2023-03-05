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
    treap *tl, *tr;
    treap() = default;
    treap(int k) : key(k), pri(mt()) { tl = tr = nullptr; }
    ~treap()
    {
        if (tl)
            delete tl;
        if (tr)
            delete tr;
    }
};

inline void rv(treap *t)
{
    if (t)
        t->tag ^= 1;
}
void push(treap *t)
{
    if (!t || !t->tag)
        return;
    swap(t->tl, t->tr);
    rv(t->tl);
    rv(t->tr);
    t->tag = false;
}
inline int size(treap *t) { return t ? t->size : 0; }
inline void pull(treap *t)
{
    if (t)
        t->size = size(t->tl) + 1 + size(t->tr);
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

treap *rv(treap *t, int l, int r)
{
    treap *t1, *t2;
    split(t, l - 1, t1, t);
    split(t, r - l + 1, t, t2);
    rv(t);
    return merge(merge(t1, t), t2);
}

treap *build(const string &s)
{
    treap *root;
    vector<treap *> v;
    for (int i = 0, n = s.length(); i < n; i++)
    {
        auto *t = new treap(s[i]);
        root = nullptr;
        while (v.size() && v.back()->pri < t->pri)
        {
            v.back()->tr = root;
            root = v.back();
            pull(root);
            v.pop_back();
        }
        t->tl = root;
        v.push_back(t);
    }
    root = nullptr;
    while (v.size())
    {
        v.back()->tr = root;
        root = v.back();
        pull(root);
        v.pop_back();
    }
    return root;
}

void dfs(treap *root)
{
    if (!root)
        return;
    push(root);
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
        root = rv(root, a, b);
    }
    dfs(root);
    cout.put('\n');
    return 0;
}
