#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(10);
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            while (j)
            {
                v[j % 10]++;
                j /= 10;
            }
        }
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << ' ' << v[4] << ' ' << v[5] << ' ' << v[6] << ' ' << v[7] << ' ' << v[8] << ' ' << v[9] << '\n';
    }
    return 0;
}