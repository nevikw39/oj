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

using pll = pair<int64_t, int64_t>;
using vpll = vector<pll>;

int64_t d_c(const vpll::const_iterator &fl, const vpll::const_iterator &fr, const vector<int64_t>::const_iterator &cl, const vector<int64_t>::const_iterator &cr)
{
    if (cl > cr)
        return 0;
    int64_t y = INT64_MIN;
    auto cm = cl + ((cr - cl) >> 1);
    vpll::const_iterator fm;
    for (auto itr = fl; itr <= fr; itr++)
    {
        auto v = itr->ST * *cm + itr->ND;
        if (y < v)
        {
            y = v;
            fm = itr;
        }
    }
    return d_c(fl, fm, cl, cm - 1) + y + d_c(fm, fr, cm + 1, cr);
}

int main()
{
    nevikw39;
    int64_t n, m, s = 0;
    cin >> n >> m;
    vpll f(n);
    vector<int64_t> c(m);
    for (auto &i : f)
        cin >> i.ST >> i.ND;
    for (auto &i : c)
        cin >> i;
    sort(ALL(f));
    sort(ALL(c));
    cout << d_c(ALL(f) - 1, ALL(c) - 1) << '\n';
    return 0;
}