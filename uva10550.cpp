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
    short n, a, b, c;
	while (cin >> n >> a >> b >> c && n || a || b || c)
		cout << ((n + 40 - a) % 40 + (b + 40 - a) % 40 + (b + 40 - c) % 40) * 9 + 1080 << '\n';
    return 0;
}