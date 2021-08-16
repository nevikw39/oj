#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    while (cin >> a >> b >> c >> d && a || b || c || d)
    {
        if (a == c && b == d)
            cout << "0\n";
        else if (abs(a - c) == abs(b - d) || a == c || b == d)
            cout << "1\n";
        else
            cout << "2\n";
    }
    return 0;
}