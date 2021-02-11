#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double c;
	while (cin >> c)
	{
		int n;
		double d;
		for (d = 0, n = 2; d < c; n++)
			d += 1.0 / n;
		cout << n - 2 << " card(s)\n";
	}
	return 0;
}
