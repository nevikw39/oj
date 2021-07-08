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
    int n, m;
    cin >> n >> m;
    vector<string> g(n + 2);
    vector<vector<int>> d(n + 2, vector<int>(m + 2));
    for (int i = 0; i < m + 2; i++)
        g.front().push_back('1'), g.back().push_back('1');
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        g[i] = '1' + s + '1';
    }
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    while (q.size() && !d[n][m])
    {
        auto tmp = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = tmp.ST + dx[k], y = tmp.ND + dy[k];
            while (g[x][y] == '0')
            {
                if (!d[x][y])
                {
                    d[x][y] = d[tmp.ST][tmp.ND] + 1;
                    q.emplace(x, y);
                }
                x += dx[k], y += dy[k];
            }
        }
    }
    cout << --d[n][m] << '\n';
    return 0;
}