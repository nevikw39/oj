#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short t;
	cin >> t;
	while (t--)
	{
		int sum = 0;
		short n;
		cin >> n;
		vector<short> v(n);
		for (auto &i : v)
			cin >> i;
		sort(v.begin(), v.end(), [](short a, short b) { return a > b; });
		for (short i = 2; i < n; i += 3)
			sum += v[i];
		cout << sum << endl;
	}
	return 0;
}
