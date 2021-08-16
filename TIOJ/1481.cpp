#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#include "lib1481.h"
vector<int> r;
vector<bool> v;
vector<vector<int>> g;
vector<pair<int, int>> e;
int cnt = 0;
void dfs(int x)
{
    for (const int &i : g[x])
        if (!v[i])
        {
            v[i] = true;
            r[i] = ++cnt;
            dfs(e[i].first != x ? e[i].first : e[i].second);
        }
}
int main()
{
    Init();
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    g.resize(n + 1);
    v.resize(k);
    r.resize(k);
    for (int i = 0; i < k; i++)
    {
        int st, ed;
        cin >> st >> ed;
        g[st].push_back(i);
        g[ed].push_back(i);
        e.emplace_back(st, ed);
    }
    Possible();
    dfs(1);
    for (const int &i : r)
        Number(i);
    Finish();
    return 0;
}