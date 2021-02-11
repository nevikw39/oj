#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
vector<int> g[1001];
bool v[1001];
int m[1001];
bool dfs(int x)
{
    for (const int &i : g[x])
    {
        if (v[i])
            continue;
        v[i] = true;
        if (m[i] == -1 || dfs(m[i]))
        {
            m[i] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, t = 0;
    while (cin >> n >> k && n && k)
    {
        for (int i = 0; i <= n; i++)
            g[i].clear();
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            // g[b].push_back(a);
        }
        memset(m, -1, sizeof(m));
        int r = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            r += dfs(i);
        }
        cout << "Case #" << ++t << ':' << r << '\n';
    }
    return 0;
}