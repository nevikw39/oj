#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int d;
vector<vector<int> > adj;
int dfs(int x)
{
    int h1 = 0, h2 = 0;
    for (int i = 0; i < adj[x].size(); i++)
    {
        int h = dfs(adj[x][i]) + 1;
        if (h > h1)
        {
            h2 = h1;
            h1 = h;
        }
        else if (h > h2)
            h2 = h;
        d = max(d, h1 + h2);
    }
    return h1;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        d = -1;
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            while (tmp != -1)
            {
                adj[i].push_back(tmp);
                cin >> tmp;
            }
        }
        dfs(0);
        cout << d << endl;
    }
    return 0;
}
