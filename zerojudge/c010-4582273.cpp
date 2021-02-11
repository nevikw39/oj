#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> v;
	while (cin >> n)
	{
		v.insert(upper_bound(v.begin(), v.end(), n), n);
		short l = v.size();
		cout << (l % 2 ? v[l / 2] : (v[l / 2] + v[l / 2 - 1]) / 2) << endl;
	}
	return 0;
}
