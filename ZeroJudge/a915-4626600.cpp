#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	vector<pair<int, int>> v;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i.first << ' ' << i.second << endl;
	return 0;
}
