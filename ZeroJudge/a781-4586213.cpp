#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char n;
	while (cin >> n && n - '0')
	{
		n -= '0';
		for (char i = 0; i < 8; i++)
			for (char x = 0; x < n; x++)
			{
				for (char j = 0; j < 8; j++)

					for (char y = 0; y < n; y++)
						cout << (i % 2 ^ !(j % 2)? '#' : '.');
				cout << endl;
			}
	}
	return 0;
}
