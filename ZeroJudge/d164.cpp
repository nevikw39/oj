#include <bits/stdc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        int mx = 0;
        vector<int> v(n + 1), s(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            s[i] = v[i] + s[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            int j = i + m;
            if (j <= n)
                mx = max(mx, s[j - 1] - s[i - 1]);
            else
                mx = max(mx, s[n] - s[i - 1] + s[j - n - 1]);
        }
        cout << mx << '\n';
    }
    return 0;
}