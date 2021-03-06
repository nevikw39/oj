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
	string s;
	size_t l = 0;
	deque<string> d;
	while (getline(cin, s))
	{
		d.push_front(s);
		l = max(l, s.length());
	}
	for (int i = 0; i < l; i++)
	{
		for (const auto &j : d)
			cout << (i < j.length() ? j[i] : ' ');
		cout << endl;
	}
    return 0;
}