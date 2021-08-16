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
		short e, f, c, sum = 0;
		cin >> e >> f >> c;
		e += f;
		while (e >= c)
		{
			sum += e / c;
			e = e / c + e % c;
		}
		cout << sum << '\n';
	}
    return 0;
}