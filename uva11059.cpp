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
    int n, t = 0;
    while (cin >> n && n)
    {
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        long long mx = 0, pos = 0, neg = 0;
        for (const int &i : v)
        {
            pos *= i;
            neg *= i;
            if (i > 0 && !pos)
                pos = i;
            else if (i < 0)
            {
                swap(pos, neg);
                if (!neg)
                    neg = i;
            }
            if (mx < pos && i)
                mx = pos;
        }
        cout << "Case #" << ++t << ": The maximum product is " << mx << ".\n\n";
    }
    return 0;
}