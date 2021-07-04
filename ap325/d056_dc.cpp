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
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

using pll = pair<int64_t, int64_t>;
using vpll = vector<pll>;

inline int64_t d(const pll &l, const pll &r)
{
    return abs(l.ST - r.ST) + abs(l.ND - r.ND);
}

bool cmp(const pll &l, const pll &r)
{
    return l.ND < r.ND;
}

int64_t d_c(const vpll::iterator &l, const vpll::iterator &r)
{
    if (r - l <= 3)
    {
        auto y = INT64_MAX;
        for (auto itr = l; itr != r; itr++)
            for (auto jtr = itr + 1; jtr != r; jtr++)
                y = min(y, d(*itr, *jtr));
        return y;
    }
    auto m = l + ((r - l) >> 1);
    auto y = min(d_c(l, m), d_c(m, r)), k = (int64_t)0;
    vpll v;
    merge(l, m, m, r, back_inserter(v), cmp);
    copy(ALL(v), l);
    for (auto itr = l; itr != r; itr++)
        if (abs(itr->ST - m->ST) < y)
        {
            for (int64_t j = k - 1; j >= 0 && itr->ND - v[j].ND < y; j--)
                y = min(y, d(*itr, v[j]));
            v[k++] = *itr;
        }
    return y;
}

int main()
{
    nevikw39;
    int64_t n;
    cin >> n;
    vpll v(n);
    for (auto &i : v)
        cin >> i.ST >> i.ND;
    sort(ALL(v));
    cout << d_c(ALL(v)) << '\n';
    return 0;
}