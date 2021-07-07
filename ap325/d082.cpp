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

int DP[33][33][33][33];

int dp(const vector<vector<int>> &v, int x1, int y1, int x2, int y2)
{
    if (DP[x1][y1][x2][y2] >= 0)
        return DP[x1][y1][x2][y2];
    int t = 0, b = 0, l = 0, r = 0;
    for (int i = x1; i <= x2; i++)
        t += v[i][y1], b += v[i][y2];
    t = min(t, x2 - x1 + 1 - t), b = min(b, x2 - x1 + 1 - b);
    for (int j = y1; j <= y2; j++)
        l += v[x1][j], r += v[x2][j];
    l = min(l, y2 - y1 + 1 - l), r = min(r, y2 - y1 + 1 - r);
    t += dp(v, x1, y1 + 1, x2, y2);
    b += dp(v, x1, y1, x2, y2 - 1);
    l += dp(v, x1 + 1, y1, x2, y2);
    r += dp(v, x1, y1, x2 - 1, y2);
    return DP[x1][y1][x2][y2] = min(min(t, b), min(l, r));
}

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < m; y1++)
            for (int x2 = 0; x2 < n; x2++)
                for (int y2 = 0; y2 < m; y2++)
                    DP[x1][y1][x2][y2] = -(x1 != x2 && y1 != y2);
    cout << dp(v, 0, 0, n - 1, m - 1) << '\n';
    return 0;
}