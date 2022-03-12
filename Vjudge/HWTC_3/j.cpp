/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
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

int main()
{
    nevikw39;
    int n;
    cin >> n;
    vector<int64_t> a(n + 1), ps(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1, INT64_MAX >> 2));
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int i = n; i; i--)
        for (int j = i; j <= n; j++)
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + ps[j] - ps[i - 1] + dp[k + 1][j]);
    cout << dp[1][n] << '\n';
    return 0;
}