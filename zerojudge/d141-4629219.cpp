#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		array<pair<int, int>, 3> a;
		for (char i = 0; i < 3; i++)
		{
			int n, m;
			cin >> n;
			cin.get();
			cin >> m;
			a[i] = {n, m};
		}
		sort(a.begin(), a.end());
		if (a[0] == a[1] || a[1] == a[2])
		{
			cout << "collinear\n";
			continue;
		}
		cout << (double(a[0].second - a[1].second) * (a[2].first - a[1].first) == double(a[2].second - a[1].second) * (a[0].first - a[1].first) ? "collinear\n" : "not collinear\n");
	}
	return 0;
}
