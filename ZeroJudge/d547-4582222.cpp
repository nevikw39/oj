#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	cin >> n >> m;
	deque<bool> pwd;
	for (short i = m; i; i--)
	{
		bool tmp;
		cin >> tmp;
		pwd.push_back(tmp);
	}
	while (n--)
	{
		deque<bool> d;
		vector<short> v(m + 1);
		for (auto &i : v)
			cin >> i;
		short x = v.back();
		for (short i = m; i; i--)
		{
			d.push_front(x > v[i - 1]);
			x = abs(v[i] - v[i - 1]);
		}
		if (d == pwd)
			for (auto i : v)
				cout << i << ' ';
	}
	return 0;
}
