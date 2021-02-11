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
    int n;
    while (cin >> n && n)
    {
        long a = 2, b = 1, c;
        if (n == 1 || n == 2 || n == 3)
        {
            cout << n << endl;
            continue;
        }
        n -= 2;
        while (n--)
        {
            c = a + b;
            b = a;
            a = c;
        }
        cout << a << endl;
    }
    return 0;
}