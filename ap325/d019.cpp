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
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = __gnu_pbds::tree<K, M, Cmp, T, tree_order_statistics_node_update>;
template <typename T>
using _heap = __gnu_pbds::priority_queue<T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
using citr = vector<long long>::const_iterator;
template <typename T>
void f(citr i, const citr &end, _tree<T> &m, T p, T s = 0LL)
{
    if (s >= p)
        return;
    if (i >= end)
    {
        m.insert(s);
        return;
    }
    f(i + 1, end, m, p, s);
    f(i + 1, end, m, p, s + *i);
}
int main()
{
    nevikw39;
    long long n, p, r = LLONG_MIN;
    cin >> n >> p;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    _tree<long long> m1, m2;
    f(v.cbegin(), v.cbegin() + (n >> 1), m1, p);
    f(v.cbegin() + (n >> 1), v.cend(), m2, p);
    for (const auto &i : m1)
    {
        auto itr = m2.upper_bound(p - i);
        if (itr != m2.begin())
            r = max(r, i + *prev(itr));
    }
    cout << r << '\n';
    return 0;
}