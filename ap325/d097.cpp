#include <bits/stdc++.h>
using namespace std;
constexpr int N = 505;
int a[N * N] = {0}, p[N * N], d[4] = {1, -1}, cnt = 0, mx = 0;

int root(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = root(p[x]);
}

int dfs(int x, int r)
{
    p[x] = r;
    int cnt = 1;
    for (int k = 0; k < 4; k++)
    {
        int y = x + d[k];
        if (a[y] && p[y] == -1)
            cnt += dfs(y, r);
    }
    return cnt;
}

void unite(int x, int y)
{
    x = root(x);
    y = root(y);
    if (x == y)
        return;
    mx = max(mx, -p[x] - p[y]);
    --cnt;
    if (p[x] < p[y])
    {
        p[x] += p[y];
        p[y] = x;
    }
    else
    {
        p[y] += p[x];
        p[x] = y;
    }
    return;
}
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            p[i * (n + 2) + j] = -1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i * (n + 2) + j];
    d[2] = n += 2, d[3] = -n;
    for (int v = n; v < (m + 1) * n; v++)
    {
        if (a[v] && p[v] == -1)
        {
            p[v] = -dfs(v, v);
            mx = max(mx, -p[v]);
            ++cnt;
        }
    }
    int64_t s_cnt = cnt, s_mx = mx;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        i = i * n + j;
        if (a[i])
            continue;
        a[i] = 1;
        mx = max(mx, 1);
        ++cnt;
        for (int k = 0; k < 4; k++)
        {
            if (!a[i + d[k]])
                continue;
            unite(i, i + d[k]);
        }
        s_mx += mx;
        s_cnt += cnt;
    }
    cout << s_mx << '\n'
         << s_cnt << '\n';
    return 0;
}
