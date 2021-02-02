#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        int mx = 0;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, (int)v[i].length());
        }
        int c = (60 - mx) / (mx + 2) + 1, r = (n - 1) / c + 1;
        for (int i = 0; i < 60; i++)
            cout.put('-');
        cout.put('\n');
        sort(v.begin(), v.end());
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int x = i + j * r;
                if (x < n)
                {
                    cout << v[x];
                    for (int k = v[x].length(); k < mx + ((j != c - 1) << 1); k++)
                        cout.put(' ');
                }
            }
            cout.put('\n');
        }
    }
    return 0;
}