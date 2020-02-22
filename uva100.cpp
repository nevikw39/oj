#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int f(int x)
{
	int y = 1;
	while (x != 1)
	{
		x = x & 1 ? 3 * x + 1 : x >> 1;
		y++;
	}
	return y;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
	int i, j;
	while (cin >> i >> j)
	{
		int n = 0;
		cout << i << ' ' << j << ' ';
		if (i > j)
			swap(i, j);
		for (int k = i; k <= j; k++)
			n = max(n, f(k));
		cout << n << '\n';
	}
    return 0;
}