#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // ios::sync_with_stdio(false);
    static int x[3003], y[3003], s[3003][3003];
    int n, l, w;
    cin >> n >> l >> w;
    vector<int> vx{-1}, vy{-1};
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 1; i <= n; i++)
    {
        int a = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin(), b = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
        s[a][b]++;
    }
    int mx = -1;
    for (int i = 1, di = 1; i < vx.size(); i++)
    {
        while (vx[i] - vx[di] > w)
            di++;
        for (int j = 1, dj = 1; j < vy.size(); j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            while (vy[j] - vy[dj] > l)
                dj++;
            mx = max(mx, s[i][j] - s[i][dj - 1] - s[di - 1][j] + s[di - 1][dj - 1]);
        }
    }
    cout << mx;
    return 0;
}