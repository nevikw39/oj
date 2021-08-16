#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using pss = pair<short, short>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	cin >> n >> m;
	m = floor(m * 1.5) - 1;
	vector<pss> v(n);
	for (auto &i : v)
	{
		short tmp0, tmp1;
		cin >> tmp0 >> tmp1;
		i = {tmp0, tmp1};
	}
	sort(v.begin(), v.end(), [](pss a, pss b) { return a.second == b.second ? a.first < b.first : a.second > b.second; });
	v.erase(remove_if(v.begin(), v.end(), [&](pss x) { return x.second < v[m].second; }), v.end());
	cout << v[m].second << ' ' << v.size() << endl;
	for (auto i : v)
		cout << i.first << ' ' << i.second << endl;
	return 0;
}
