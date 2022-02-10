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

inline int d(const tuple<int, int, int> &x, const tuple<int, int, int> &y)
{
    const auto &[x1, y1, z1] = x;
    const auto &[x2, y2, z2] = y;
    return abs(x2 - x1) + abs(y2 - y1) + max(0, z2 - z1);
}

int main()
{
    nevikw39;
    int n, r = INT_MAX >> 1;
    cin >> n;
    vector<tuple<int, int, int>> v(n);
    for (auto &[x, y, z] : v)
        cin >> x >> y >> z;
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX >> 1));
    dp[1 << 0][0] = 0;
    for (int i = 1; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                for (int k = 0; k < n; k++)
                    if (i & (1 << k))
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + d(v[k], v[j]));
    for (int i = 0; i < n; i++)
        r = min(r, dp.back()[i] + d(v[i], v.front()));
    cout << r << '\n';
    return 0;
}