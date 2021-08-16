#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
using namespace std;
using pss = pair<set<short>, short>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n && n)
	{
		short sum = 0;
		map<set<short>, short> m;
		while (n--)
		{
			short a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			set<short> s = {a, b, c, d, e};
			m[s]++;
		}
		vector<pss> v;
		move(m.begin(), m.end(), back_inserter(v));
		sort(v.begin(), v.end(), [](pss a, pss b) { return a.second > b.second; });
		for (auto i : v)
		{
			if (i.second == v.front().second)
				sum += i.second;
			else
				break;
		}
		cout << sum << endl;
	}
	return 0;
}
