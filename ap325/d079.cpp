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

int64_t DP[202][202];

int64_t dp(const vector<int64_t> &v, int64_t i, int64_t j)
{
    if (DP[i][j] >= 0)
        return DP[i][j];
    if (j - i == 1)
        return DP[i][j] = 0;
    if (j - i == 2)
        return DP[i][j] = v[i] * v[i + 1] * v[j];
    int64_t y = INT64_MAX;
    for (int64_t k = i + 1; k < j; k++)
        y = min(y, dp(v, i, k) + v[i] * v[k] * v[j] + dp(v, k, j));
    return DP[i][j] = y;
}

int main()
{
    nevikw39;
    int64_t n;
    cin >> n;
    vector<int64_t> v(n + 1);
    for (auto &i : v)
        cin >> i;
    memset(DP, -1, sizeof(DP));
    cout << dp(v, 0, n) << '\n';
    return 0;
}