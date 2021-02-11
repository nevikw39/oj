#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, c, d, e, f, x, y;
		cin >> a >> b >> c >> d >> e >> f;
		x = (c * e - b * f) / (a * e - b * d);
		y = (a * f - c * d) / (a * e - b * d);
		cout << x << ' ' << y << endl;
	}
	return 0;
}
