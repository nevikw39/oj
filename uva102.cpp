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
    string s[] = {"BCG ", "BGC ", "CBG ", "CGB ", "GBC ", "GCB "};
	while (cin)
	{
		int t = 0;
		array<int, 3> b, c, g;
		array<int, 6> a;
		for (char i = 0; i < 3; i++)
		{
			cin >> b[i] >> g[i] >> c[i];
			t += b[i] + g[i] + c[i];
		}
		if (cin.eof())
			break;
		a[0] = t - b[0] - c[1] - g[2];
		a[1] = t - b[0] - g[1] - c[2];
		a[2] = t - c[0] - b[1] - g[2];
		a[3] = t - c[0] - g[1] - b[2];
		a[4] = t - g[0] - b[1] - c[2];
		a[5] = t - g[0] - c[1] - b[2];
		int n = 0;
		for (int i = 1; i < 6; i++)
			if (a[n] > a[i])
				n = i;
		cout << s[n] << a[n] << '\n';
	}
    return 0;
}