#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int n, mx;
vector<vector<char>> g;
vector<vector<bool>> vis;
bool f(int r, int l)
{
    static const pair<int, int> ds[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (const auto &d : ds)
    {
        int i = r + d.first, j = l + d.second;
        while (i >= 0 && i < n && j >= 0 && j < n)
        {
            if (g[i][j] == 'X')
                break;
            if (vis[i][j])
                return true;
            i += d.first;
            j += d.second;
        }
    }
    return false;
}
void dfs(int x, int y, int num)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[i][j] && g[i][j] == '.' && !f(i, j))
            {
                vis[i][j] = true;
                dfs(i, j, num + 1);
                vis[i][j] = false;
            }
    mx = mx > num ? mx : num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n && n)
    {
        mx = -1;
        g.clear();
        g.resize(n);
        vis.clear();
        vis.resize(n);
        for (int i = 0; i < n; i++)
        {
            g[i].clear();
            g[i].resize(n);
            vis[i].clear();
            vis[i].resize(n);
            for (auto &j : g[i])
                cin >> j;
        }
        dfs(0, 0, 0);
        cout << mx << '\n';
    }
    return 0;
}