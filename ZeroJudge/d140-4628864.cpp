#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long a, b;
	while (cin >> a && cin.get() && cin >> b)
	{
		a = a * 100 + b;
		a = (a <= 10000) * 800 + a * (a <= 10000) * 0.9 + a * (a > 10000 && a <= 50000) * 0.8 + a * (a > 50000) * 0.6;
		b = a % 100;
		a /= 100;
		cout << '$' << a << '.' << setw(2) << setfill('0') << b << endl;
	}
	return 0;
}
