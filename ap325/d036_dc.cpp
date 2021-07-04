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

int64_t d_c(const vector<int64_t>::const_iterator &l, const vector<int64_t>::const_iterator &r, int64_t M)
{
    if (r - l < M)
        return 0;
    auto m = l + ((r - l) >> 1), start = max(m - M + 1, l);
    auto y = d_c(l, m, M) + d_c(m, r, M), k = (int64_t)0;
    _hash<int64_t, int64_t> ht;
    for (auto itr = start; itr != start + M; itr++)
        if (!ht[*itr]++)
            ++k;
    if (k == M)
        ++y;
    for (auto itr = start, end = min(m, r - M); itr != end; itr++)
    {
        if (!--ht[*itr])
            --k;
        if (!ht[*(itr + M)]++)
            ++k;
        if (k == M)
            ++y;
    }
    return y;
}

int main()
{
    nevikw39;
    int64_t m, n;
    cin >> m >> n;
    vector<int64_t> v(n);
    for (auto &i : v)
        cin >> i;
    cout << d_c(ALL(v), m) << '\n';
    return 0;
}