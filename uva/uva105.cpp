#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int l, h, r, n = 0;
    int a[10001] = {0};
    while (cin >> l >> h >> r)
    {
        for (int i = l; i < r; i++)
            a[i] = max(a[i], h);
        n = max(n, r);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (a[i - 1] != a[i])
        {
            if (flag)
            {
                cout << i << ' ' << a[i];
                flag = false;
            }
            else
                cout << ' ' << i << ' ' << a[i];
        }
    cout << '\n';
    return 0;
}