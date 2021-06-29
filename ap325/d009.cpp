#include <bits/stdc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
long long f(const vector<vector<int>> &v, int x1, int y1, int x2, int y2)
{
    if (x2 - x1 < 0 || y2 - y1 < 0)
        return 0;
    int t = 0, b = 0, l = 0, r = 0;
    for (int i = x1; i <= x2; i++)
        t += v[i][y1], b += v[i][y2];
    t = min(t, x2 - x1 + 1 - t), b = min(b, x2 - x1 + 1 - b);
    for (int j = y1; j <= y2; j++)
        l += v[x1][j], r += v[x2][j];
    l = min(l, y2 - y1 + 1 - l), r = min(r, y2 - y1 + 1 - r);
    t += f(v, x1, y1 + 1, x2, y2);
    b += f(v, x1, y1, x2, y2 - 1);
    l += f(v, x1 + 1, y1, x2, y2);
    r += f(v, x1, y1, x2 - 1, y2);
    return min(min(t, b), min(l, r));
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto &i : v)
        for (int &j : i)
            cin >> j;
    cout << f(v, 0, 0, n - 1, m - 1) << '\n';
    return 0;
}