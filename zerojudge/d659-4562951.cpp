#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short t;
	cin >> t;
	for (short i = 0; i < t; i++)
	{
		array<int, 3> a;
		for (int &j : a)
			cin >> j;
		sort(a.begin(), a.end());
		cout << "Case " << i + 1 << ": " << a[1] << endl;
	}
	return 0;
}
