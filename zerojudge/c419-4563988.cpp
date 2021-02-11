#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n && n)
		for (short i = n - 1; i >= 0; i--)
		{
			for (short j = 0; j < n; j++)
				cout << (i > j ? '_' : '*');
			cout << endl;
		}
	return 0;
}
