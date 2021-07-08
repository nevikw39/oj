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

int main()
{
    nevikw39;
    const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int n, m, x = 0, y = 0, t = INT_MAX, r = 0;
    cin >> n >> m;
    vector<vector<int>> g(n + 2, vector<int>(m + 2));
    vector<vector<bool>> v(n + 2, vector<bool>(m + 2));
    for (int i = 0; i <= n + 1; i++)
        v[i][0] = v[i][m + 1] = true;
    for (int j = 0; j <= m + 1; j++)
        v[0][j] = v[n + 1][j] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (t > g[i][j])
                t = g[i][j], x = i, y = j;
        }
    while (!v[x][y])
    {
        v[x][y] = true;
        r += g[x][y];
        int d = 0, t = INT_MAX;
        for (int k = 0; k < 4; k++)
            if (!v[x + dx[k]][y + dy[k]] && g[x + dx[k]][y + dy[k]] < t)
                t = g[x + dx[k]][y + dy[k]], d = k;
        if (t == INT_MAX)
            break;
        x += dx[d], y += dy[d];
    }
    cout << r << '\n';
    return 0;
}