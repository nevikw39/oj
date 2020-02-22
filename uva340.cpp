#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, t = 0;
    while (cin >> n && n)
    {
        cout << "Game " << ++t << ":\n";
        vector<int> x(n), y(n);
        for (int &i : x)
            cin >> i;
        for (;;)
        {
            int a = 0, b = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> y[i];
                a += x[i] == y[i];
            }
            if (y[0] == 0)
                break;
            for (int i = 1; i < 10; i++)
            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++)
                {
                    c1 += i == x[j];
                    c2 += i == y[j];
                }
                b += c1 < c2 ? c1 : c2;
            }
            cout << "    (" << a << ',' << b - a << ")\n";
        }
    }
    return 0;
}