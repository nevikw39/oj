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
    vector<int> v;
	while (cin >> n)
	{
		v.insert(upper_bound(v.begin(), v.end(), n), n);
		short l = v.size();
		cout << (l & 1 ? v[l >> 1] : (v[l >> 1] + v[(l >> 1) - 1]) >> 1) << '\n';
	}
    return 0;
}