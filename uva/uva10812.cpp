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
    int n;
    cin >> n;
    while (n--)
    {
        long s, d, a, b;
        cin >> s >> d;
        a = (s + d) >> 1;
        b = (s - d) >> 1;
        if (a < 0 || b < 0 || (s + d) & 1)
            cout << "impossible\n";
        else
            cout << a << ' ' << b << '\n';
    }
    return 0;
}