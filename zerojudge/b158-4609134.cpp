#include <algorithm>
#include <iostream>
#include <functional>
#include <array>
#include <map>
using namespace std;
using N = pair<short, short>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n)
	{
		multimap<N, short, greater<N>> m;
		for (short i = 1; i <= n; i++)
		{
			short sum, a, b, c;
			cin >> a >> b >> c;
			sum = a + b + c;
			m.insert({{sum, a}, i});
		}
		short j = 0;
		for (auto i = m.begin(); j < 5; i++, j++)
			cout << i->second << ' ' << i->first.first << endl;
	}
	return 0;
}
