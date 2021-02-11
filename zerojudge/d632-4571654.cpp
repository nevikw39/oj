#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	while (cin >> a >> b)
	{
		bool c[32];
		cout << a << endl
			 << b << "\n---------------------------------\n";
		bool carry = false;
		for (short i = 31; i >= 0; i--)
		{
			short n = a[i] - '0' + b[i] - '0' + carry;
			c[i] = n % 2;
			carry = n / 2;
		}
		for (bool i : c)
			cout << i;
		cout << "\n****End of Data******************\n";
	}
	return 0;
}
