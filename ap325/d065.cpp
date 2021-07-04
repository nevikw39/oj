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

int64_t d_c(const vector<int64_t>::iterator &l, const vector<int64_t>::iterator &r)
{
    if (r <= l)
        return 0;
    if (r - l == 1)
        return *l;
    auto m = l + ((r - l) >> 1), itr = m, jtr = m;
    auto y = max(d_c(l, m), d_c(m, r)), h = *m;
    while (itr >= l || jtr < r)
    {
        h = max(itr >= l ? *itr : INT64_MIN, jtr < r ? *jtr : INT64_MIN);
        while (itr >= l && *itr >= h)
            --itr;
        while (jtr < r && *jtr >= h)
            ++jtr;
        y = max(y, (jtr - itr - 1) * h);
    }
    return y;
}

int main()
{
    nevikw39;
    int64_t n;
    cin >> n;
    vector<int64_t> v(n);
    for (auto &i : v)
        cin >> i;
    cout << d_c(ALL(v)) << '\n';
    return 0;
}