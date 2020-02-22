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
	tree<string, int> m;
	cin >> n;
	cin.ignore(1, '\n');
	while (n--)
	{
		string s;
		stringstream ss;
		getline(cin, s);
		ss.str(s);
		ss >> s;
		m[s]++;
	}
	for (const auto &i : m)
		cout << i.first << ' ' << i.second << '\n';
    return 0;
}