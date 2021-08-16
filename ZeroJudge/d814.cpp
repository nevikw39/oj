/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39      \
    cin.tie(nullptr); \
    ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct _cerr
{
    template <typename T>
    _cerr &operator<<(const T &x) { return *this; }
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
using namespace __gnu_pbds;random_device rd;
mt19937 mt(rd());
struct treap
{
    int key, pri, size;
    treap *tl, *tr;
    treap() = default;
    treap(int k) : key(k), pri(mt()), size(1)
    {
        tl = tr = nullptr;
    }
    ~treap()
    {
        if (tl)
            delete tl;
        if (tr)
            delete tr;
    }
    inline static int sz(treap *t)
    {
        return t ? t->size : 0;
    }
    void pull()
    {
        size = sz(tl) + 1 + sz(tr);
    }
};
inline int sz(treap *t)
{
    return t ? t->size : 0;
}
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
    int n;
    while (cin >> n)
    {
        treap *t = nullptr;
        while (n--)
        {
            int m;
            cin >> m;
            treap *l, *r = nullptr;
            split(t, m, l, r);
            cout << (r ? r->size : 0) + 1 << '\n';
            t = merge(merge(l, new treap(m)), r);
        }
        delete t;
    }
    return 0;
}