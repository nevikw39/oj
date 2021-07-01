/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <bits/extc++.h>
#include <bits/stdc++.h>
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
using namespace __gnu_pbds;
template <typename T>
using _heap = __gnu_pbds::priority_queue<T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

using itr = vector<pair<long long, long long>>::iterator;
vector<itr>::iterator h;
void f(itr l, itr r, long long w, itr i)
{
    if (r - l <= 1)
    {
        l->ND = w;
        return;
    }
    while (*h <= l || *h >= r)
        ++h;
    if (w >= (r - l) * (*h)->ST)
        for (auto i = l; i < r; i++)
            i->ND = w / (r - l);
    else if (*h > i)
    {
        auto c = (*h - l) * (*h)->ST;
        if (w < c)
        {
            f(l, *h, w, i);
            return;
        }
        for (auto i = l; i < *h; i++)
            i->ND = (*h)->ST;
        if (w > c)
            f(*h, r, w - c, *h);
    }
    else
    {
        auto c = (r - *h) * (*h)->ST;
        if (w < c)
        {
            f(*h, r, w, i);
            return;
        }
        for (auto i = *h; i < r; i++)
            i->ND = (*h)->ST;
        if (w > c)
            f(l, *h, w - c, *h - 1);
    }
}

int main()
{
    nevikw39;
    long long n, i, w;
    cin >> n >> i >> w;
    vector<pair<long long, long long>> v;
    vector<itr> vv;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.emplace_back(x, 0);
    }
    for (int i = 0; i < n; i++)
        vv.push_back(v.begin() + i);
    sort(ALL(vv), [](const itr &l, const itr &r)
         { return l->ST > r->ST; });
    h = vv.begin();
    f(ALL(v) - 1, w, v.begin() + i);
    for (auto i = v.begin(); i < v.end() - 1; i++)
        cout << i->ND << ' ';
    return 0;
}