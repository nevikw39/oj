#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int n, m, c;
vector<int> s, t;
vector<vector<int>> v;
bool dfs(int x)
{
    s[x] = -1;
    for (int y = 0; y < n; y++)
        if (v[x][y])
        {
            if (s[y] < 0)
                return false;
            else if (!s[y])
                dfs(y);
        }
    s[x] = 1;
    t[--c] = x;
    return true;
}
bool topo()
{
    c = n;
    fill(s.begin(), s.end(), 0);
    for (int x = 0; x < n; x++)
        if (!s[x])
            if (!dfs(x))
                return false;
    return true;
}
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    while (cin >> n >> m && n)
    {
        s.resize(n);
        t.resize(n);
        v.resize(n);
        fill(v.begin(), v.end(), vector<int>(n));
        while (m--)
        {
            int i, j;
            cin >> i >> j;
            v[i - 1][j - 1] = true;
        }
        topo();
        cout << t[0] + 1;
        for (int i = 1; i < n; i++)
            cout << ' ' << t[i] + 1;
        cout << '\n';
    }
    return 0;
}