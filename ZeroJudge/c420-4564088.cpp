#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	short a = (2 * n - 1) / 2, b = a;
	for (short i = 0; i < n; i++, a--, b++)
	{
		for (short j = 0; j < 2 * n - 1; j++)
			cout << (j < a || j > b ? '_' : '*');
		cout << endl;
	}
	return 0;
}
