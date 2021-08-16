#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int m, n;
vector<vector<char>> v;
bool dfs(int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n || v[x][y] != '@')
        return false;
    v[x][y] = '#';
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
            if (dx || dy)
                dfs(x + dx, y + dy);
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    while (cin >> m >> n && m)
    {
        v.resize(m);
        for (auto &i : v)
        {
            i.resize(n);
            for (char &j : i)
                cin >> j;
        }
        int r = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] == '@')
                    r += dfs(i, j);
        cout << r << '\n';
    }
    return 0;
}