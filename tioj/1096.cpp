#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n)
    {
        vector<vector<int>> v(n);
        for (auto &i : v)
        {
            i.resize(n);
            for (int &j : i)
            {
                cin >> j;
                if (!j)
                    j = INT_MAX;
            }
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (v[i][k] != INT_MAX && v[k][j] != INT_MAX)
                        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        int r = INT_MAX;
        for (int i = 0; i < n; i++)
            r = min(r, v[i][i]);
        cout << (r != INT_MAX ? r : -1) << '\n';
    }
    return 0;
}