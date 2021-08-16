#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, mx = 0, mxi = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int cp, iv, ss = s, d;
        cin >> cp >> iv;
        switch (iv)
        {
        case 0 ... 29:
            d = 10;
            break;
        case 30 ... 39:
            d = 50;
            break;
        default:
            d = 100;
        }
        while (ss >= 1000)
        {
            ss -= 1000;
            cp += d;
        }
        if (mx < cp)
        {
            mx = cp;
            mxi = i;
        }
    }
    cout << mxi + 1 << ' ' << mx << '\n';
    return 0;
}