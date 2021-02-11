#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ivec = vector<int>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	while (cin >> n >> m)
	{
		vector<ivec> v(n, ivec(m));
		for (auto &i : v)
			for (int &j : i)
				cin >> j;
		sort(v.begin(), v.end());
		for (auto i : v)
		{
			for (auto j : i)
				cout << j << ' ';
			cout << endl;
		}
	}
	return 0;
}
