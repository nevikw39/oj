#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    array<int, 9> a;
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8])
    {
        auto itr = a.begin();
        while (!*itr && itr != a.end())
            itr++;
        if (itr == a.end())
        {
            cout << "0\n";
            continue;
        }
        int n = *itr, l = 8 - (itr - a.begin());
        cout << (n == 1 ? "" : n == -1 ? "-" : to_string(n)) << (l == 0 ? "" : l != 1 ? "x^" + to_string(l) : "x");
        itr++;
        for (; itr != a.end(); itr++)
            if (*itr)
            {
                n = *itr;
                l = 8 - (itr - a.begin());
                cout << (n >= 0 ? " + " : " - ") << ((n == 1 || n == -1) && l != 0 ? "" : to_string(abs(n))) << (l == 0 ? "" : l != 1 ? "x^" + to_string(l) : "x");
            }
        if (!a[7] && a[8] == -1)
            cout << '1';
        cout << '\n';
    }
}