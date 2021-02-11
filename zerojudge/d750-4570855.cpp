#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	auto cmp = [&](int a, int b) {
		int x = a % m, y = b % m;
		if (x != y)
			return x < y;
		if (!!(a % 2) != !!(b % 2))
			return !!(a % 2);
		if (a % 2)
			return a > b;
		return a < b;
	};
	while (cin >> n >> m)
	{
		cout << n << ' ' << m << endl;
		if (!n)
			break;
		vector<int> v(n);
		for (int &i : v)
			cin >> i;
		sort(v.begin(), v.end(), cmp);
		for (int i : v)
			cout << i << endl;
	}
	return 0;
}
