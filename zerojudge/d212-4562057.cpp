#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		long a = 2, b = 1, c;
		if (n == 1 || n == 2 || n == 3)
		{
			cout << n << endl;
			continue;
		}
		n -= 2;
		while (n--)
		{
			c = a + b;
			b = a;
			a = c;
		}
		cout << a << endl;
	}
	return 0;
}
