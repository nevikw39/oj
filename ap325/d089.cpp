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

int DP[1 << 17][17];

int dp(const vector<vector<int>> &v, int n, int s, int p)
{
    if (DP[s][p] >= 0)
        return DP[s][p];
    DP[s][p] = INT_MAX;
    for (int i = 0; i < n; i++)
        if (i != p && s & (1 << i))
            DP[s][p] = min(DP[s][p], dp(v, n, s - (1 << p), i) + v[p][i]);
    return DP[s][p];
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < n; i++)
        DP[1 << i][i] = v[m][i];
    cout << dp(v, n, (1 << n) - 1, m) << '\n';
    return 0;
}