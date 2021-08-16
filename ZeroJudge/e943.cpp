#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int n, mx = 0;
vector<gp_hash_table<int, null_type>> g;
vector<int> p;
void dfs(int x)
{
    mx = max(mx, (int)p.size());
    for (const int &i : g[x])
    {
        bool flag = true;
        for (const int &j : p)
            if (g[i].find(j) == g[i].end())
                flag = false;
        if (!flag)
            continue;
        p.push_back(i);
        dfs(i);
        p.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    g.resize(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int i = 0; i < n; i++)
        dfs(i);
    cout << (mx ?: 1);
    return 0;
}