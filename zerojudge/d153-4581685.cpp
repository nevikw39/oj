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
		unsigned short n, m;
		cin >> n;
		m = n / 2 - 1 + n % 2;
		vector<short> v;
		while (n--)
		{
			short tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		cout << v[m] << endl;
	}
	return 0;
}
