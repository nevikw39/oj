#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	while (n--)
	{
		int sum = 0;
		short m;
		cin >> m;
		vector<int> v(m);
		for (int &i : v)
			cin >> i;
		sort(v.begin(), v.end(), greater<int>());
		for (short i = 0; i < m / 2; i++)
			sum += v[i] - v[m - i - 1];
		cout << sum << endl;
	}
	return 0;
}
