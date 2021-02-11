#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n)
	{
		vector<short> v(n);
		for (auto &i : v)
			cin >> i;
		while (v.size())
		{
			for (auto i : v)
				cout << i << ' ';
			cout << endl;
			v.erase(v.begin());
			reverse(v.begin(), v.end());
		}
	}
	return 0;
}
