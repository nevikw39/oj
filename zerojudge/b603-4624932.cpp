#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		int a = abs(x1 - x2), b = (y2 - y1) / a, c = -2 * b * x1, d = a * y2 - b * x2 * x2 - c * x2;
		int n = __gcd(a, __gcd(b, __gcd(c, d)));
		n = abs(n);
		a /= n;
		b /= n;
		c /= n;
		d /= n;
		cout << a << "y = " << b << "x^2 + " << c << "x + " << d << endl;
	}
	return 0;
}
