#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using pcs = pair<char, short>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	cin >> n;
	vector<pcs> v;
	auto cmp = [](pcs a, pcs b) {
		map<char, char> m;
		m['S'] = 3;
		m['H'] = 2;
		m['D'] = 1;
		m['C'] = 0;
		return a.second != b.second ? a.second > b.second : (m[a.first] > m[b.first]);
	};
	while (n--)
	{
		char c;
		short s;
		cin >> c >> s;
		v.push_back({c, s});
	}
	cin >> m;
	sort(v.begin(), v.end(), cmp);
	cout << v[--m].first << ' ' << v[m ].second << endl;
	return 0;
}
