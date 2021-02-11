#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	while (n--)
	{
		long s, d, a, b;
		cin >> s >> d;
		a = (s + d) / 2;
		b = (s - d) / 2;
		if (a < 0 || b < 0 || (s + d) % 2)
			cout
				<< "impossible\n";
		else
			cout << a << ' ' << b << endl;
	}
	return 0;
}
