#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	cin >> n >> m;
	while (n--)
	{
		set<int> a, b, c;
		for (int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;
			a.insert(tmp);
		}
		for (int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;
			b.insert(tmp);
		}
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
		cout << c.size() << endl;
	}
	return 0;
}
