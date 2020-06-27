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
    int t;
    cin >> t;
    while (t--)
    {
    	int s = 1, n;
    	cin >> n;
        for (int i = 2; i <= n >> 1; i++)
            if (n % i == 0)
                s += i;
        cout << (s > n ? "abundant\n" : (s < n ? "deficient\n" : "perfect\n"));
    }
    return 0;
}