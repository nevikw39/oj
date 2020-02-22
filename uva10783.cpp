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
    int t, i = 0;
	cin >> t;
	while (i < t)
	{
		int a, b, n, m;
		cin >> a >> b;
		n = (a + 1 + !(a & 1)) >> 1;
		m = (b + 1 - !(b & 1)) >> 1;
		cout << "Case " << ++i << ": " << (m + n - 1) * (m - n + 1) << '\n';
	}
    return 0;
}