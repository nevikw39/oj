#include <iostream>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int n, maxn;
vector<vector<char>> map;
vector<vector<bool>> vis;
bool f(int r, int l)
{
    const pair<int, int> ds[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto d : ds)
    {
        int i = r + d.first, j = l + d.second;
        while (i >= 0 && i < n && j >= 0 && j < n)
        {
            if (map[i][j] == 'X')
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
            if (!vis[i][j] && map[i][j] == '.' && !f(i, j))
            {
                vis[i][j] = true;
                dfs(i, j, num + 1);
                vis[i][j] = false;
            }
    maxn = maxn > num ? maxn : num;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    while (cin >> n && n)
    {
        maxn = -1;
        map.clear();
        map.resize(n);
        vis.clear();
        vis.resize(n);
        for (int i = 0; i < n; i++)
        {
            map[i].clear();
            map[i].resize(n);
            vis[i].clear();
            vis[i].resize(n);
            for (auto &j : map[i])
                cin >> j;
        }
        dfs(0, 0, 0);
        cout << maxn << endl;
    }
    return 0;
}
